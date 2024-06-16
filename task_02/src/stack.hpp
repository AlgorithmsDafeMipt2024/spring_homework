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


template <typename T>
size_t Stack<T>::Size() const { return size_; }

template <typename T>
void Stack<T>::Push(T data)
{
  top_ = std::make_shared<Element<T>>(data, top_);
  size_++;
}

template <typename T>
T Stack<T>::Pop()
{
  if (size_ == 0)
    throw std::runtime_error("Stack is empty");
  T removed_value = top_->data_;
  top_ = std::move(top_->next_);
  size_--;
  return removed_value;
}

template <typename T>
T Stack<T>::Top() const
{
  if (size_ == 0)
    throw std::runtime_error("Stack is empty");
  return top_->data_;
}

template <typename T>
void MinStack<T>::Push(T data)
{
  top_ = std::make_shared<Element<T>>(data, top_);
  size_++;
  if (minimums_stack_.Size() > 0 && data > minimums_stack_.Top())
    minimums_stack_.Push(minimums_stack_.Top());
  else
    minimums_stack_.Push(data);
}

template <typename T>
T MinStack<T>::Pop()
{
  if (size_ == 0)
    throw std::runtime_error("Stack is empty");
  T removed_value = top_->data_;
  top_ = std::move(top_->next_);
  size_--;
  minimums_stack_.Pop();
  return removed_value;
}

template <typename T>
T MinStack<T>::GetMin() const { return minimums_stack_.Top(); }