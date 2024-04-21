#pragma once

#include <memory>

template <typename T>
struct Element {
  explicit Element(T data, std::shared_ptr<Element<T>> prev = nullptr)
      : element{data}, prev{prev} {}

  explicit Element() : element{}, prev{nullptr} {}

  T element;

  std::shared_ptr<Element<T>> prev;
};

template <typename T>
class Stack {
 public:
  explicit Stack() : data_{} {}

  void Push(T value);

  T Pop();

  bool Empty() const;

  const T& Top() const;

  size_t Size() const;

 private:
  Element<T> data_;

  size_t size_ = 0;
};

template <typename T>
void Stack<T>::Push(T value) {
  Element new_data{value, std::make_shared<Element<T>>(data_)};
  size_ += 1;
  data_ = new_data;
}

template <typename T>
T Stack<T>::Pop() {
  T deleted_element = data_.element;
  Element new_data = *data_.prev;
  data_.prev = nullptr;
  data_ = new_data;
  size_ -= 1;
  return deleted_element;
}

template <typename T>
bool Stack<T>::Empty() const {
  return data_.prev == nullptr;
}

template <typename T>
const T& Stack<T>::Top() const {
  return data_.element;
}

template <typename T>
size_t Stack<T>::Size() const {
  return size_;
}

template <typename T>
class MinStack {
 public:
  void Push(T value);
  T Pop();
  T GetMin() const;

 private:
  Stack<T> main_stack_;
  Stack<T> min_stack_;
};

template <typename T>
void MinStack<T>::Push(T value) {
  if (main_stack_.Size() == 0) {
    min_stack_.Push(value);
    main_stack_.Push(value);
  } else {
    main_stack_.Push(value);
    if (value < min_stack_.Top())
      min_stack_.Push(value);
    else
      min_stack_.Push(min_stack_.Top());
  }
}

template <typename T>
T MinStack<T>::Pop() {
  T result = main_stack_.Top();
  main_stack_.Pop();
  min_stack_.Pop();
  return result;
}

template <typename T>
T MinStack<T>::GetMin() const {
  return min_stack_.Top();
}