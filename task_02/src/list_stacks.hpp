#pragma once

#include <list>
#include <stdexcept>

template <typename T>
class Stack final {
 public:
  constexpr Stack() noexcept {}
  Stack(const Stack& other) : list(other.list) {}
  Stack(Stack&& other) : list(other.list) { other.list.clear(); }
  Stack(const std::initializer_list<T>& init_list) : list(init_list) {}

  ~Stack() = default;

  void Push(const T& value) { list.push_back(value); }
  void Pop() {
    if (Empty()) throw std::underflow_error("Stack is empty!");
    list.pop_back();
  }

  T& Top() {
    if (Empty()) throw std::underflow_error("Stack is empty!");
    return list.back();
  }
  bool Empty() { return list.empty(); }
  std::size_t Size() { return list.size(); }

 private:
  std::list<T> list;
};

template <typename T>
class StackMin final {
 public:
  constexpr StackMin() noexcept {}
  StackMin(const StackMin& other) : list(other.list) {}
  StackMin(StackMin&& other) : list(other.list) { other.list.clear(); }
  StackMin(const std::initializer_list<T>& init_list) : list(init_list) {}

  ~StackMin() = default;

  void Push(const T& value) {
    if (min_stack.Empty() || min_stack.Top() > value) min_stack.Push(value);
    list.push_back(value);
  }
  void Pop() {
    if (Empty()) throw std::underflow_error("Stack is empty!");
    if (min_stack.Top() == list.back()) min_stack.Pop();
    list.pop_back();
  }

  T& Top() {
    if (Empty()) throw std::underflow_error("Stack is empty!");
    return list.back();
  }
  bool Empty() { return list.empty(); }
  std::size_t Size() { return list.size(); }

  T& Min() { return min_stack.Top(); }

 private:
  std::list<T> list;
  Stack<T> min_stack;
};
