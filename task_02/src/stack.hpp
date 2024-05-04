#pragma once

#include <algorithm>
#include <stack>
#include <stdexcept>
#include <vector>

// check if type comparasion operators are defined for a class
template <typename CutsomType>
concept comparable = requires(CutsomType a, CutsomType b) {
  a < b;
  a <= b;
  a == b;
  a >= b;
  a > b;
  a != b;
};

// simple structure, helps to form a linked list
template <typename CutsomType>
struct Node {
  Node() : prev{nullptr}, data{}, next{nullptr} {}
  Node(CutsomType data_) : prev{nullptr}, data{data_}, next{nullptr} {}
  void AddNode(CutsomType data_);
  Node* next;
  Node* prev;
  CutsomType data;
};

// method, that allows to add a node with a value to an existing one
template <typename CutsomType>
void Node<CutsomType>::AddNode(CutsomType data_) {
  next = new Node(data_);
  next->prev = this;
}

// data structure that can store and retrieve data in such fashion:
// last element inserted will be retrieved first (last in first out (LIFO))
// insertion, deletion and retrieval has time complexity of O(1)
template <typename CutsomType>
class MyStack {
 public:
  MyStack() : top_{nullptr} {}

  // insert an element at the top of the stack
  void Push(CutsomType value);

  // retrieve last inserted element
  CutsomType Top();
  // retrieve last inserted element and delete it from the stack
  CutsomType Pop();
  // check if stack is empty
  bool Empty() const { return top_ == nullptr; }

 private:
  Node<CutsomType>* top_;
};

template <typename CutsomType>
void MyStack<CutsomType>::Push(CutsomType value) {
  if (top_ == nullptr)
    top_ = new Node(value);
  else {
    top_->AddNode(value);
    top_ = top_->next;
  }
}

template <typename CutsomType>
CutsomType MyStack<CutsomType>::Top() {
  if (top_ == nullptr) throw std::runtime_error("out_of_range\n");
  return top_->data;
}

template <typename CutsomType>
CutsomType MyStack<CutsomType>::Pop() {
  if (top_ == nullptr) throw std::runtime_error("out_of_range\n");
  Node<CutsomType>* temp = top_->prev;
  CutsomType val = top_->data;
  delete top_;
  top_ = temp;
  return val;
}

template <comparable CutsomType>
class MinStack {
 public:
  // insert an element at the top of the stack
  void Push(CutsomType value);
  // retrieve last inserted element and delete it from the stack
  CutsomType Pop();
  // retrieve minimal element
  CutsomType Min();
  // retrieve last inserted element
  CutsomType Top();

 private:
  MyStack<std::pair<CutsomType, CutsomType>> stack;
};

template <comparable CutsomType>
void MinStack<CutsomType>::Push(CutsomType value) {
  if (stack.Empty())
    stack.Push({value, value});
  else
    stack.Push({value, std::min(value, stack.Top().second)});
}

template <comparable CutsomType>
CutsomType MinStack<CutsomType>::Pop() {
  return stack.Pop().first;
}

template <comparable CutsomType>
CutsomType MinStack<CutsomType>::Min() {
  return stack.Top().second;
}

template <comparable CutsomType>
CutsomType MinStack<CutsomType>::Top() {
  return stack.Top().first;
}