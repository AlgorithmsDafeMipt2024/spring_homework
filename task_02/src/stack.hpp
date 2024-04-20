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
  void add_node(CutsomType data_);
  Node* next;
  Node* prev;
  CutsomType data;
};

// method, that allows to add a node with a value to an existing one
template <typename CutsomType>
void Node<CutsomType>::add_node(CutsomType data_) {
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
  void push(CutsomType value);

  // retrieve last inserted element
  CutsomType top();
  // retrieve last inserted element and delete it from the stack
  CutsomType pop();
  // check if stack is empty
  bool empty() const { return top_ == nullptr; }

 private:
  Node<CutsomType>* top_;
};

template <typename CutsomType>
void MyStack<CutsomType>::push(CutsomType value) {
  if (top_ == nullptr)
    top_ = new Node(value);
  else {
    top_->add_node(value);
    top_ = top_->next;
  }
}

template <typename CutsomType>
CutsomType MyStack<CutsomType>::top() {
  if (top_ == nullptr)
    throw std::runtime_error("there are no elements in the stack\n");
  return top_->data;
}

template <typename CutsomType>
CutsomType MyStack<CutsomType>::pop() {
  if (top_ == nullptr)
    throw std::runtime_error("there are no elements in the stack\n");
  Node<CutsomType>* temp = top_->prev;
  CutsomType& val = top_->data;
  delete top_;
  top_ = temp;
  return val;
}

template <comparable CutsomType>
class MinStack {
 public:
  // insert an element at the top of the stack
  void push(CutsomType value);
  // retrieve last inserted element and delete it from the stack
  CutsomType pop();
  // retrieve minimal element
  CutsomType min();
  // retrieve last inserted element
  CutsomType top();

 private:
  MyStack<std::pair<CutsomType, CutsomType>> stack;
};

template <comparable CutsomType>
void MinStack<CutsomType>::push(CutsomType value) {
  if (stack.empty())
    stack.push({value, value});
  else
    stack.push({value, std::min(value, stack.top().second)});
}

template <comparable CutsomType>
CutsomType MinStack<CutsomType>::pop() {
  return stack.pop().first;
}

template <comparable CutsomType>
CutsomType MinStack<CutsomType>::min() {
  return stack.top().second;
}

template <comparable CutsomType>
CutsomType MinStack<CutsomType>::top() {
  return stack.top().first;
}