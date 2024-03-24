#include "stack.hpp"

template <typename T>
Elem<T>::Elem(Elem *elem, const T &value) : prev{elem}, data{value} {}

template <typename T>
Elem<T>::Elem(Elem *elem) : prev{elem} {}

template <typename T>
Stack<T>::Stack(const Elem<T> &value) : top_{new Elem<T>(value)} {}

template <typename T>
Stack<T>::Stack(const std::stack<T> &stack) {
  for (const auto &elem : stack) Push(elem);
}

template <typename T>
Stack<T>::Stack(const std::vector<T> &vector) {
  for (const auto &elem : vector) Push(elem);
}

template <typename T>
Stack<T>::Stack(const std::initializer_list<T> &init_list) {
  for (const auto &elem : init_list) Push(elem);
}

template <typename T>
T Stack<T>::Top() {
  top_->data;
}

template <typename T>
bool Stack<T>::Empty() {
  return top_ == nullptr;
}

template <typename T>
size_t Stack<T>::Size() {
  return size_;
}

template <typename T>
void Stack<T>::Push(const T &value) {
  auto new_elem = new Elem<T>(top_, value);
  top_ = new_elem;
}

template <typename T>
void Stack<T>::PushRange(Stack<T> stack) {
  for (size_t i = 0; i < stack.Size(); i++) {
    Push(stack.Top());
    stack.Pop();
  };
}

template <typename T>
void Stack<T>::PushRange(std::stack<T> stack) {
  for (size_t i = 0; i < stack.size(); i++) {
    Push(stack.top());
    stack.pop();
  };
}

template <typename T>
void Stack<T>::PushRange(const std::vector<T> &vector) {
  for (const auto &elem : vector) Push(elem);
}

template <typename T>
void Stack<T>::PushRange(const std::initializer_list<T> &init_list) {
  for (const auto &elem : init_list) Push(elem);
}

template <typename T>
T Stack<T>::Pop() {
  auto old_top = top_;
  top_ = old_top.prev;
  return old_top;
}

template <typename T>
void Stack<T>::Swap(Stack<T> &another_stack) {}
