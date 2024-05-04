#pragma once

#include <memory>
#include <stdexcept>

template <typename T>
class Stack {
 public:
  explicit Stack() : top_(nullptr) {}
  void Push(T data);
  T Pop();
  T Top() const;
  size_t Size() const;

 private:
  struct StackNode {
    T data_;
    std::shared_ptr<StackNode> next_;
    explicit StackNode(T data, const std::shared_ptr<StackNode>& next)
        : data_(data), next_(next) {}
  };
  size_t size_ = 0;
  std::shared_ptr<StackNode> top_;
};

template <typename T>
class MinStack {
 public:
  explicit MinStack() : data_stack_(), minimums_stack_() {}

  void Push(T data);
  T Pop();
  T Top() const;
  T GetMin() const;
  size_t Size() const;

 private:
  Stack<T> data_stack_;
  Stack<T> minimums_stack_;
};
template <typename T>
void Stack<T>::Push(T data) {
  top_ = std::make_shared<StackNode>(data, top_);
  size_++;
}

template <typename T>
T Stack<T>::Pop() {
  if (size_ == 0) throw std::out_of_range("Stack is empty");
  T removed_value = top_->data_;
  top_ = std::move(top_->next_);
  size_--;
  return removed_value;
}

template <typename T>
T Stack<T>::Top() const {
  if (size_ == 0) throw std::out_of_range("Stack is empty");
  return top_->data_;
}

template <typename T>
size_t Stack<T>::Size() const {
  return size_;
}

template <typename T>
void MinStack<T>::Push(T data) {
  data_stack_.Push(data);
  if (minimums_stack_.Size() > 0 && data > minimums_stack_.Top())
    minimums_stack_.Push(minimums_stack_.Top());
  else
    minimums_stack_.Push(data);
}

template <typename T>
T MinStack<T>::Pop() {
  minimums_stack_.Pop();
  return data_stack_.Pop();
}

template <typename T>
T MinStack<T>::GetMin() const {
  return minimums_stack_.Top();
}

template <typename T>
size_t MinStack<T>::Size() const {
  return data_stack_.Size();
}

template <typename T>
T MinStack<T>::Top() const {
  return data_stack_.Top();
}