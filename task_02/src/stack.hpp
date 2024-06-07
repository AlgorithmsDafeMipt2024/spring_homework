#pragma once

#include <memory>
#include <stdexcept>

template <typename T>
struct StackElem {
  explicit StackElem(T value, const std::shared_ptr<StackElem>& prev)
      : value_{value}, prev_{prev} {}

  T value_;
  std::shared_ptr<StackElem> prev_;
};

template <typename T>
class Stack {
 public:
  explicit Stack() : top_{nullptr} {}

  void Push(T value);
  T Pop();

  T Top() const {
    if (IsEmpty()) throw std::out_of_range("Stack is empty!");
    return top_->value_;
  }
  size_t Size() const { return size_; }
  bool IsEmpty() const { return size_ == 0; }

 private:
  std::shared_ptr<StackElem<T>> top_;
  size_t size_ = 0;
};

template <typename T>
class MinStack {
 public:
  explicit MinStack() : data_(), mins_data_() {}

  void Push(T value);
  T Pop();

  T Top() const { return data_.Top(); }
  T GetMin() const { return mins_data_.Top(); }
  size_t Size() const { return data_.Size(); }
  bool IsEmpty() const { return data_.IsEmpty(); }

 private:
  Stack<T> data_;
  Stack<T> mins_data_;
};

template <typename T>
void Stack<T>::Push(T value) {
  top_ = std::make_shared<StackElem<T>>(value, top_);
  size_++;
}

template <typename T>
T Stack<T>::Pop() {
  if (IsEmpty()) throw std::out_of_range("Stack is empty!");
  T res = top_->value_;
  top_ = std::move(top_->prev_);
  size_--;
  return res;
}

template <typename T>
void MinStack<T>::Push(T value) {
  data_.Push(value);
  if (mins_data_.Size() > 0 && mins_data_.Top() < value)
    mins_data_.Push(mins_data_.Top());
  else
    mins_data_.Push(value);
}

template <typename T>
T MinStack<T>::Pop() {
  mins_data_.Pop();
  return data_.Pop();
}