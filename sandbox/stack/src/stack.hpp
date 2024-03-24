#pragma once

#include <initializer_list>
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
  Elem() = default;
  Elem(Elem*, const T&);
  Elem(Elem*);

  /// @brief указатель на предыдущий элемент
  std::unique_ptr<Elem> prev;

  /// @brief значение элемента
  T data;
};

template <typename T>
class Stack {
 public:
  Stack() : top_{nullptr} {}
  Stack(const Elem<T>&);
  Stack(const Stack<T>&) = default;
  Stack(const std::stack<T>&);
  Stack(const std::vector<T>&);
  Stack(const std::initializer_list<T>&);

  Stack& operator=(const Stack<T>&) = default;

  /**
   * @brief
   * возвращает верхний элемент стека
   * @return T
   */
  T Top();

  /**
   * @brief
   * проверяет, пуст ли стек
   * @return true: если пуст
   * @return false: если не пуст
   */
  bool Empty();

  /**
   * @brief
   * возвращает размер стека
   * @return size_t
   */
  size_t Size();

  /**
   * @brief
   * добавляет новый элемент в стек
   * @param value: значение нового элемента
   */
  void Push(const T& value);

  /**
   * @brief
   * расширяет стек значениями элементов другого стека
   * @param stack
   */
  void PushRange(Stack<T> stack);

  /**
   * @brief
   * расширяет стек значениями std::stack
   * @param stack
   */
  void PushRange(std::stack<T> stack);

  /**
   * @brief
   * расширяет стек значениями элементов вектора
   * @param vector
   */
  void PushRange(const std::vector<T>& vector);

  /**
   * @brief
   * расширяет стек значениями элементов списка инициализации
   * @param init_list
   */
  void PushRange(const std::initializer_list<T>& init_list);

  /**
   * @return T: верхний элемент стека
   */
  T Pop();

  /**
   * @brief
   * меняет все элементы двух стеков местами
   * @param another_stack
   */
  void Swap(Stack<T>& another_stack);

 private:
  /// @brief указатель на последний элемент
  std::unique_ptr<Elem<T>> top_;
  size_t size_;
};
