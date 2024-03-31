#pragma once

#include <initializer_list>
#include <memory>
#include <stack>
#include <stdexcept>
#include <string>
#include <vector>

/**
 * @brief Элемент стека (звено в односвязном списке)
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
class SinglyListStack {
 public:
  SinglyListStack() : top_{nullptr}, size_{0} {}

  SinglyListStack(const T& value) : top_{new SinglyListElem<T>(value)} {}

  SinglyListStack(const SinglyListStack<T>& stack) = default;

  SinglyListStack(const std::stack<T>& stack) { PushRange(stack); }

  SinglyListStack(const std::vector<T>& vector) { PushRange(vector); }

  SinglyListStack(const std::initializer_list<T>& init_list) {
    PushRange(init_list);
  }

  SinglyListStack& operator=(const SinglyListStack<T>& stack) {
    PushRange(stack);
  }

  SinglyListStack& operator=(SinglyListStack<T>&& stack) { PushRange(stack); }

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
      throw std::logic_error("invalid key string, do you mean 'T& Top(ptr)'?");
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
    auto new_elem = std::make_shared<SinglyListElem<T>>(top_, value);
    top_ = new_elem;
    size_++;
  }

  /**
   * @brief расширяет стек значениями элементов другого стека
   * @param stack
   */
  void PushRange(SinglyListStack<T> stack) {
    SinglyListStack<T> temp_stack;
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
  }

  /**
   * @brief меняет все элементы двух стеков местами
   * @param another_stack
   * @throw std::invalid_argument: если размеры стеков не совпадает
   */
  void Swap(SinglyListStack<T>& another_stack) {
    if (Size() != another_stack.Size())
      throw std::invalid_argument("Stacks sizes mismatch");

    std::swap(another_stack.Top("ptr"), top_);
  }

  /**
   * @brief меняет все элементы двух стеков местами
   * @param another_stack
   * @throw std::invalid_argument: если размеры стеков не совпадает
   */
  void Swap(std::stack<T>& another_stack) {
    if (Size() != another_stack.size())
      throw std::invalid_argument("Stack and std::stack sizes mismatch");

    // проще особо не сделаешь, если хочется сохранить порядок

    SinglyListStack<T> extra_stack_1;
    SinglyListStack<T> extra_stack_2;

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

 private:
  // @brief указатель на последний элемент
  std::shared_ptr<SinglyListElem<T>> top_;
  size_t size_;
};