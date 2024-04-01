#pragma once

#include <initializer_list>
#include <list>
#include <memory>
#include <stack>
#include <stdexcept>
#include <string>
#include <vector>

/**
 * @brief реализация стека на односвязном списке
 * @tparam T: тип значений элементов стека
 */
template <typename T>
class MinListStack {
 public:
  MinListStack() = default;

  MinListStack(const T& value) { Push(value); }

  MinListStack(const MinListStack<T>&) = default;

  MinListStack(const std::stack<T>& stack) { PushRange(stack); }

  MinListStack(const std::vector<T>& vector) { PushRange(vector); }

  MinListStack(const std::initializer_list<T>& init_list) {
    PushRange(init_list);
  }

  MinListStack& operator=(const MinListStack<T>&) = default;
  MinListStack& operator=(MinListStack<T>&&) = default;

  /**
   * @return T: верхний элемент стека
   * @throw std::logic_error: если стек пуст
   */
  T Top() {
    if (Empty()) throw std::logic_error("Stack is empty");

    return list_.back();
  }

  /**
   * @brief проверяет, пуст ли стек
   * @return true: если пуст
   * @return false: если не пуст
   */
  bool Empty() { return list_.size() == 0; }

  /**
   * @return size_t: размер стека
   */
  size_t Size() { return list_.size(); };

  /**
   * @brief добавляет новый элемент в стек
   * @param value: значение нового элемента
   */
  void Push(const T& value = T()) {
    if (!is_min_init) {
      min_ = value;
      is_min_init = true;
    }

    if (value < min_) min_ = value;

    list_.push_back(value);
  }

  /**
   * @brief расширяет стек значениями элементов другого стека
   * @param stack
   */
  void PushRange(MinListStack<T> stack) {
    MinListStack<T> temp_stack;
    while (!stack.Empty()) {
      temp_stack.Push(stack.Top());
      stack.Pop();
    }

    while (!temp_stack.Empty()) {
      Push(temp_stack.Top());
      temp_stack.Pop();
    }
  }

  /**
   * @brief расширяет стек значениями std::stack
   * @param stack
   */
  void PushRange(std::stack<T> stack) {
    std::stack<T> temp_stack;
    while (!stack.empty()) {
      temp_stack.push(stack.top());
      stack.pop();
    }

    while (!temp_stack.empty()) {
      Push(temp_stack.top());
      temp_stack.pop();
    }
  }

  /**
   * @brief расширяет стек значениями элементов вектора
   * @param vector
   */
  void PushRange(const std::vector<T>& vector) {
    for (const auto& elem : vector) Push(elem);
  }

  /**
   * @brief расширяет стек значениями элементов списка инициализации
   * @param init_list
   */
  void PushRange(const std::initializer_list<T>& init_list) {
    for (const auto& elem : init_list) Push(elem);
  }

  /**
   * @throw std::invalid_argument: если стек пуст
   */
  void Pop() {
    if (Empty()) throw std::logic_error("Stack is empty");

    list_.pop_back();
  }

  /**
   * @brief меняет все элементы двух стеков местами
   * @param another_stack
   * @throw std::invalid_argument: если размеры стеков не совпадает
   */
  void Swap(MinListStack<T>& another_stack) {
    // проще особо не сделаешь, если хочется сохранить порядок

    MinListStack<T> extra_stack_1;
    MinListStack<T> extra_stack_2;

    while (!Empty()) {
      extra_stack_1.Push(Top());
      Pop();
    }

    while (!another_stack.Empty()) {
      extra_stack_2.Push(another_stack.Top());
      another_stack.Pop();
    }

    while (!extra_stack_1.Empty()) {
      another_stack.Push(extra_stack_1.Top());
      extra_stack_1.Pop();
    }

    while (!extra_stack_2.Empty()) {
      Push(extra_stack_2.Top());
      extra_stack_2.Pop();
    }
  }
  /**
   * @brief меняет все элементы двух стеков местами
   * @param another_stack
   * @throw std::invalid_argument: если размеры стеков не совпадает
   */
  void Swap(std::stack<T>& another_stack) {
    // проще особо не сделаешь, если хочется сохранить порядок

    MinListStack<T> extra_stack_1;
    MinListStack<T> extra_stack_2;

    while (!Empty()) {
      extra_stack_1.Push(Top());
      Pop();
    }

    while (!another_stack.empty()) {
      extra_stack_2.Push(another_stack.top());
      another_stack.pop();
    }

    while (!extra_stack_1.Empty()) {
      another_stack.push(extra_stack_1.Top());
      extra_stack_1.Pop();
    }

    while (!extra_stack_2.Empty()) {
      Push(extra_stack_2.Top());
      extra_stack_2.Pop();
    }
  }

  /**
   * @return T: значение минимума стека
   */
  T GetMin() { return min_; }

 private:
  // @brief двусвязный список, на основе которого написан стек
  std::list<T> list_;

  T min_;
  bool is_min_init{false};
};