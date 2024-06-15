#pragma once

#include <list>
#include <stdexcept>

template <typename T>
class Stack final {
 public:
  constexpr Stack() noexcept {}
  Stack(const Stack& other) : list_(other.list_) {}
  Stack(Stack&& other) : list_(std::move(other.list_)) { other.list_.clear(); }
  Stack(const std::initializer_list<T>& init_list) : list_(init_list) {}

  ~Stack() = default;

  void Push(const T& value) { list_.push_back(value); }
  void Pop() {
    if (Empty()) throw std::underflow_error("Stack is empty!");
    list_.pop_back();
  }

  T& Top() {
    if (Empty()) throw std::underflow_error("Stack is empty!");
    return list_.back();
  }
  bool Empty() { return list_.empty(); }
  std::size_t Size() { return list_.size(); }

 private:
  std::list<T> list_;
};

template <typename T>
class StackMin final {
 public:
  constexpr StackMin() noexcept {}
  StackMin(const StackMin& other) : list_(other.list_) {}
  StackMin(StackMin&& other) : list_(other.list_) { other.list_.clear(); }
  StackMin(const std::initializer_list<T>& init_list_) : list_(init_list_) {}

  ~StackMin() = default;

  void Push(const T& value) {
    if (min_stack.Empty() || min_stack.Top() > value) min_stack.Push(value);
    list_.push_back(value);
  }
  void Pop() {
    if (Empty()) throw std::underflow_error("Stack is empty!");
    if (min_stack.Top() == list_.back()) min_stack.Pop();
    list_.pop_back();
  }

  T& Top() {
    if (Empty()) throw std::underflow_error("Stack is empty!");
    return list_.back();
  }
  bool Empty() { return list_.empty(); }
  std::size_t Size() { return list_.size(); }

  T& Min() { return min_stack.Top(); }

 private:
  std::list<T> list_;
  Stack<T> min_stack;
};
