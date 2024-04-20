#pragma once

#include <algorithm>
#include <stack>
#include <stdexcept>
#include <vector>

template <typename T>
concept comparable = requires(T a, T b) {
  a < b;
  a <= b;
  a == b;
  a >= b;
  a > b;
  a != b;
};

template <comparable T>
struct Node {
  Node() : prev{nullptr}, data{}, next{nullptr} {}
  Node(T data_) : prev{nullptr}, data{data_}, next{nullptr} {}
  void add_node(T data_);
  Node* next;
  Node* prev;
  T data;
};

template <comparable T>
void Node<T>::add_node(T data_) {
  next = new Node(data_);
  next->prev = this;
}

template <comparable T>
class MyStack {
 public:
  MyStack() : top_{nullptr} {}

  void push(T value);
  T top();
  T pop();
  bool empty() const { return top_ == nullptr; }

 private:
  Node<T>* top_;
};

template <comparable T>
void MyStack<T>::push(T value) {
  if (top_ == nullptr)
    top_ = new Node(value);
  else {
    top_->add_node(value);
    top_ = top_->next;
  }
}

template <comparable T>
T MyStack<T>::top() {
  if (top_ == nullptr)
    throw std::runtime_error("there are no elements in the stack\n");
  return top_->data;
}

template <comparable T>
T MyStack<T>::pop() {
  if (top_ == nullptr)
    throw std::runtime_error("there are no elements in the stack\n");
  Node<T>* temp = top_->prev;
  T& val = top_->data;
  delete top_;
  top_ = temp;
  return val;
}

// works only if your type is comparable!!!
template <comparable T>
class MinStack {
 public:
  void push(T value);
  T pop();
  T min();
  T top();

 private:
  MyStack<std::pair<T, T>> stack;
};

template <comparable T>
void MinStack<T>::push(T value) {
  if (stack.empty())
    stack.push({value, value});
  else
    stack.push({value, std::min(value, stack.top().second)});
}

template <comparable T>
T MinStack<T>::pop() {
  return stack.pop().first;
}

template <comparable T>
T MinStack<T>::min() {
  return stack.top().second;
}

template <comparable T>
T MinStack<T>::top() {
  return stack.top().first;
}