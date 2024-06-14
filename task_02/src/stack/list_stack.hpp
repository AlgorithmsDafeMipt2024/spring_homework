#pragma once

#include <initializer_list>
#include <list>
#include <memory>
#include <stack>
#include <stdexcept>
#include <string>
#include <vector>

/**
 * @brief реализация стека на двусвязном списке (std::list)
 * @tparam T: тип значений элементов стека
 */
template <typename T>
class ListStack {
 public:
  ListStack() = default;

  ListStack(const T& value) { Push(value); }

  ListStack(const ListStack<T>&) = default;

  ListStack(const std::stack<T>& stack) { PushRange(stack); }

  ListStack(const std::vector<T>& vector) { PushRange(vector); }

  ListStack(const std::initializer_list<T>& init_list) { PushRange(init_list); }

  ListStack& operator=(const ListStack<T>&) = default;
  ListStack& operator=(ListStack<T>&&) = default;

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
  void Push(const T& value = T()) { list_.push_back(value); }

  /**
   * @brief расширяет стек значениями элементов другого стека
   * @param stack
   */
  void PushRange(ListStack<T> stack) {
    ListStack<T> temp_stack;
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
  void Swap(ListStack<T>& another_stack) {
    // проще особо не сделаешь, если хочется сохранить порядок

    ListStack<T> extra_stack_1;
    ListStack<T> extra_stack_2;

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

 private:
  // @brief двусвязный список, на основе которого написан стек
  std::list<T> list_;
};