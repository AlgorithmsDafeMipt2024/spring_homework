#include "stack.hpp"

#include <algorithm>
#include <exception>
#include <optional>
#include <stdexcept>
#include <utility>

void Stack::Push(int value) { data_.push_back(value); }

int Stack::Pop() {
  if (data_.empty()) throw std::runtime_error("stack is empty");
  int result = data_.back();
  data_.pop_back();
  return result;
}

void MinStack::Push(int value) {
  if ((GetMin_()) && *GetMin_() < value)
    min_.Push(GetMin());
  else
    min_.Push(value);
  data_.Push(value);
}

int MinStack::Pop() {
  int result = data_.Pop();
  min_.Pop();
  return result;
}

std::optional<int> MinStack::GetMin_() {
  std::optional<int> result;
  try {
    result = min_.Pop();
    min_.Push(*result);
  } catch (std::exception& e) {
    result = std::nullopt;
  }
  return result;
}

int MinStack::GetMin() {
  auto result = min_.Pop();
  min_.Push(result);
  return result;
}