#pragma once

#include <initializer_list>
#include <memory>
#include <stack>
#include <stdexcept>
#include <string>
#include <vector>

/**
 * @brief элемент стека (звено в односвязном списке)
 * @tparam T: тип значения в стеке
 */
template <typename T>
class SinglyListElem {
 public:
  SinglyListElem() : prev{nullptr} {}

  SinglyListElem(const SinglyListElem<T>& elem) : prev{&elem} {}

  SinglyListElem(SinglyListElem<T>* elem) : prev{elem} {}

  SinglyListElem(SinglyListElem<T>* elem, const T& value)
      : prev(elem), data{value} {}

  SinglyListElem(const std::shared_ptr<SinglyListElem<T>>& elem, const T& value)
      : prev(elem), data{value} {}

  SinglyListElem(const T& value) : prev{nullptr}, data{value} {}

  SinglyListElem<T>& operator=(SinglyListElem<T>&&) = default;
  SinglyListElem<T>& operator=(const SinglyListElem<T>& elem) = default;

  // @brief указатель на предыдущий элемент
  std::shared_ptr<SinglyListElem<T>> prev;

  // @brief значение элемента
  T data;
};

/**
 * @brief реализация стека на односвязном списке
 * @tparam T: тип значений элементов стека
 */
template <typename T>
class MinSinglyListStack {
 public:
  MinSinglyListStack() = default;

  MinSinglyListStack(const T& value) { Push(value); }

  MinSinglyListStack(const MinSinglyListStack<T>& stack) = default;

  MinSinglyListStack(const std::stack<T>& stack) { PushRange(stack); }

  MinSinglyListStack(const std::vector<T>& vector) { PushRange(vector); }

  MinSinglyListStack(const std::initializer_list<T>& init_list) {
    PushRange(init_list);
  }

  MinSinglyListStack& operator=(const MinSinglyListStack<T>& stack) {
    PushRange(stack);
  }

  MinSinglyListStack& operator=(MinSinglyListStack<T>&& stack) {
    PushRange(stack);
  }

  /**
   * @return T: верхний элемент стека
   * @throw std::logic_error: если стек пуст
   */
  T Top() {
    if (Empty()) throw std::logic_error("Stack is empty");

    return top_->data;
  }

  /**
   * @param key: ключ, по которому можно получить Top в виде указателя
   * @return std::shared_ptr<SinglyListElem<int>>&: ptr на верхний элемент стека
   * @throw std::logic_error: если ключ != "ptr"
   */
  std::shared_ptr<SinglyListElem<int>>& Top(const std::string& key) {
    if (Empty()) throw std::logic_error("Stack is empty");

    if (key == "ptr")
      return top_;
    else
      throw std::logic_error(
          "invalid key string, do you mean 'T& Top('ptr')'?");
  }

  /**
   * @brief проверяет, пуст ли стек
   * @return true: если пуст
   * @return false: если не пуст
   */
  bool Empty() { return top_ == nullptr; }

  /**
   * @return size_t: размер стека
   */
  size_t Size() { return size_; }

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

    auto new_elem = std::make_shared<SinglyListElem<T>>(top_, value);
    top_ = new_elem;
    size_++;
  }

  /**
   * @brief расширяет стек значениями элементов другого стека
   * @param stack
   */
  void PushRange(MinSinglyListStack<T> stack) {
    MinSinglyListStack<T> temp_stack;
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

    top_ = top_->prev;
    size_--;

    if (Size() > 0)
      FindNewMin();
    else
      is_min_init = false;
  }

  /**
   * @brief меняет все элементы двух стеков местами
   * @param another_stack
   * @throw std::invalid_argument: если размеры стеков не совпадает
   */
  void Swap(MinSinglyListStack<T>& another_stack) {
    std::swap(another_stack.Top("ptr"), top_);
  }

  /**
   * @return T: значение минимума стека
   * @throw std::logic_error: если минимум не проинициализирован
   */
  T GetMin() {
    if (!is_min_init) throw std::logic_error("Minimum is not initialized");

    return min_;
  }

 private:
  /**
   * @return T: новый минимум
   * (после удаления)
   */
  void FindNewMin() {
    min_ = top_->data;

    auto iter = top_;
    while (iter->prev != nullptr) {
      if (iter->data < min_) min_ = iter->data;
      iter = iter->prev;
    }
  }

  // @brief указатель на последний элемент
  std::shared_ptr<SinglyListElem<T>> top_;
  size_t size_{0};

  T min_;
  bool is_min_init{false};
};