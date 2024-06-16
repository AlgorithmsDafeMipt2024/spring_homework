#pragma once

#include <cstddef>
#include <memory>
#include <stack>
#include <stdexcept>
#include <type_traits>
#include <vector>

template <class T>
class StackNode {
 public:
  explicit StackNode(T _data, StackNode<T> *_prev = nullptr)
      : data(_data), prev_ptr(_prev) {}
  StackNode() : data(), prev_ptr(nullptr) {}
  T data;
  StackNode<T> *prev_ptr;
};

template <class T>
class Stack {
 public:
  Stack() : top_(nullptr), size_(0) {}
  void Push(T value);
  T Pop();
  T GetTop();
  int GetSize();

 private:
  StackNode<T> *top_;
  int size_;
};

template <class T>
void Stack<T>::Push(T value) {
  StackNode<T> *new_elem = new StackNode<T>(value, top_);
  size_++;
  top_ = new_elem;
}

template <class T>
T Stack<T>::Pop() {
  if (size_ == 0) {
    throw std::underflow_error("Empty stack");
  }
  T returning_value = std::move(top_->data);
  StackNode<T> *old_top = top_;
  top_ = top_->prev_ptr;
  delete old_top;
  size_--;
  return returning_value;
}

template <class T>
int Stack<T>::GetSize() {
  return size_;
}

template <class T>
T Stack<T>::GetTop() {
  if (size_ == 0) {
    throw std::underflow_error("Empty stack");
  }
  return top_->data;
}
template <class T>
class MinStack {
 public:
  MinStack() : main_stack_(), min_stack_() {}
  void Push(T value);
  T Pop();
  T GetMin();
  int GetSize();

 private:
  Stack<T> main_stack_;
  Stack<T> min_stack_;
};

template <class T>
void MinStack<T>::Push(T value) {
  main_stack_.Push(value);
  if (min_stack_.GetSize() == 0)
    min_stack_.Push(value);
  else
    min_stack_.Push(std::min(value, min_stack_.GetTop()));
}

template <class T>
T MinStack<T>::Pop() {
  min_stack_.Pop();
  return main_stack_.Pop();
}

template <class T>
T MinStack<T>::GetMin() {
  return min_stack_.GetTop();
}

template <class T>
int MinStack<T>::GetSize() {
  return main_stack_.GetSize();
}
