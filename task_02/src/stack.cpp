#include "stack.hpp"

template <typename T>
size_t Stack<T>::Size() const {
  return size_;
}

template <typename T>
void Stack<T>::Push(T data) {
  top_ = std::make_shared<Element>(data, top_);
  size_++;
}

template <typename T>
T Stack<T>::Pop() {
  if (size_ == 0) throw std::runtime_error("Stack is empty");
  T removed_value = top_->data_;
  top_ = std::move(top_->next_);
  size_--;
  return removed_value;
}

template <typename T>
T Stack<T>::Top() const {
  if (size_ == 0) throw std::runtime_error("Stack is empty");
  return top_->data_;
}

template <typename T>
void MinStack<T>::Push(T data) {
  top_ = std::make_shared<Element>(data, top_);
  size_++;
  if (minimums_stack_.Size() > 0 && data > minimums_stack_.Top())
    minimums_stack_.Push(minimums_stack_.Top());
  else
    minimums_stack_.Push(data);
}

template <typename T>
T MinStack<T>::Pop() {
  if (size_ == 0) throw std::runtime_error("Stack is empty");
  T removed_value = top_->data_;
  top_ = std::move(top_->next_);
  size_--;
  minimums_stack_.Pop();
  return removed_value;
}

template <typename T>
T MinStack<T>::GetMin() const {
  return minimums_stack_.Top();
}