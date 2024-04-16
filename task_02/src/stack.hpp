#pragma once

#include <memory>

/// @brief Элемент стека
template <typename T>
struct Element
{
  explicit Element(T data, const std::shared_ptr<Element>& next) : data_(data), next_(next) {}

  T data_;
  std::shared_ptr<Element> next_;
};

/// @brief Cтек
/// @tparam Т Тип данных
template <typename T>
class Stack
{
public:
  explicit Stack() : top_(nullptr), size_{0} {}

  size_t Size () const;
  virtual void Push (T data);
  virtual T Pop ();
  virtual T Top () const;

private:
  size_t size_;
  std::shared_ptr<Element<T>> top_;
};

/// @brief Стек с минимумом
/// @tparam T Тип данных
template <typename T>
class MinStack : public Stack<T>
{
public:
  explicit MinStack() : Stack<T>(), minimums_stack_() {}

  void Push (T data) override;
  T Pop () override;
  T GetMin () const;

private:
  Stack<T> minimums_stack_;
  size_t size_;
  std::shared_ptr<Element<T>> top_;
};
