#include "stack.hpp"

template <typename T>
Stack<T>::Stack(const Elem<T> &) {}

template <typename T>
Stack<T>::Stack(const std::vector<T> &) {}

template <typename T>
Stack<T>::Stack(const std::initializer_list<T> &) {}

template <typename T>
T Stack<T>::Top() {
  return T();
}

template <typename T>
bool Stack<T>::Empty() {
  return false;
}

template <typename T>
size_t Stack<T>::Size() {
  return size_t();
}

template <typename T>
void Stack<T>::Push(const T &) {}

template <typename T>
void Stack<T>::PushRange(const Stack<T> &stack) {}

template <typename T>
void Stack<T>::PushRange(const std::stack<T> &stack) {}

template <typename T>
void Stack<T>::PushRange(const std::vector<T> &vector) {}

template <typename T>
void Stack<T>::PushRange(const std::initializer_list<T> &init_list) {}

template <typename T>
T Stack<T>::Pop() {
  return Stack<T>();
}

template <typename T>
void Stack<T>::Swap(Stack<T> &another_stack) {}
