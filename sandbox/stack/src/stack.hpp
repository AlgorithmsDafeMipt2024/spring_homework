#pragma once

#include <initializer_list>
#include <iostream>
#include <memory>
#include <stack>
#include <vector>

/**
 * @brief Элемент стека
 * @tparam T: тип значения в стеке
 */
template <typename T>
class Elem {
 public:
  Elem() : prev{nullptr} {}
  ~Elem() { delete prev; }

  Elem(const Elem<T>& elem) : prev{&elem} {}
  Elem(Elem<T>* elem) : prev{elem} {}
  Elem(Elem<T>* elem, const T& value) : prev(elem), data{value} {}
  Elem(const T& value) : prev{nullptr}, data{value} {}

  Elem<T>& operator=(Elem<T>&&) = default;
  Elem<T>& operator=(const Elem<T>& elem) = default;

  /// @brief указатель на предыдущий элемент
  Elem<T>* prev;

  /// @brief значение элемента
  T data;
};

template <typename T>
class Stack {
 public:
  Stack() : top_{nullptr}, size_{0} {}
  ~Stack() { delete top_; }

  Stack(const Stack<T>&) = default;

  Stack(const T& value) : top_{new Elem<T>(value)} {}

  Stack(const std::stack<T>& stack) {
    for (const auto& elem : stack) Push(elem);
  }

  Stack(const std::vector<T>& vector) {
    for (const auto& elem : vector) Push(elem);
  }

  Stack(const std::initializer_list<T>& init_list) {
    for (const auto& elem : init_list) Push(elem);
  }

  Stack& operator=(const Stack<T>&) = default;
  Stack& operator=(Stack<T>&&) = default;

  /**
   * @brief
   * возвращает верхний элемент стека
   * @return T
   */
  T Top() { return top_->data; }

  /**
   * @brief
   * проверяет, пуст ли стек
   * @return true: если пуст
   * @return false: если не пуст
   */
  bool Empty() { return top_ == nullptr; }

  /**
   * @brief
   * возвращает размер стека
   * @return size_t
   */
  size_t Size() { return size_; }

  /**
   * @brief
   * добавляет новый элемент в стек
   * @param value: значение нового элемента
   */
  void Push(const T& value) {
    auto new_elem = new Elem<T>(top_, value);
    top_ = std::move(new_elem);
    size_++;
  }

  /**
   * @brief
   * расширяет стек значениями элементов другого стека
   * @param stack
   */
  void PushRange(Stack<T> stack) {
    while (!stack.Empty()) {
      Push(stack.Top());
      stack.Pop();
    }
  }

  /**
   * @brief
   * расширяет стек значениями std::stack
   * @param stack
   */
  void PushRange(std::stack<T> stack) {
    while (!stack.empty()) {
      Push(stack.top());
      stack.pop();
    }
  }

  /**
   * @brief
   * расширяет стек значениями элементов вектора
   * @param vector
   */
  void PushRange(const std::vector<T>& vector) {
    for (const auto& elem : vector) Push(elem);
  }

  /**
   * @brief
   * расширяет стек значениями элементов списка инициализации
   * @param init_list
   */
  void PushRange(const std::initializer_list<T>& init_list) {
    for (const auto& elem : init_list) Push(elem);
  }

  /**
   * @return T: верхний элемент стека
   */
  void Pop() {
    top_ = top_->prev;
    size_--;
  }

  /**
   * @brief
   * меняет все элементы двух стеков местами
   * @param another_stack
   */
  void Swap(Stack<T>& another_stack);

 private:
  /// @brief указатель на последний элемент
  Elem<T>* top_;
  size_t size_;
};
