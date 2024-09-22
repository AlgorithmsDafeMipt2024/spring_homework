#ifndef MIN_STACK_HPP
#define MIN_STACK_HPP
#include <exception>
#include <optional>
#include <stdexcept>

#include "stack.hpp"

template <class T>
class MinStack {
 public:
  void push(T value) {
    if ((getMin_()) && *getMin_() < value)
      min_.push(getMin());
    else
      min_.push(value);
    data_.push(value);
  }
  T pop() {
    T result = data_.pop();
    min_.pop();
    return result;
  }
  T getMin() {
    T result = min_.pop();
    min_.push(result);
    return result;
  }

 private:
  std::optional<T> getMin_() {
    std::optional<T> result;
    try {
      result = min_.pop();
      min_.push(*result);
    } catch (std::exception& e) {
      result = std::nullopt;
    }
    return result;
  }
  Stack<T> data_;
  Stack<T> min_;
};

#endif