#include "stack.hpp"

#include <algorithm>
#include <utility>

void Stack::Push(int value) { data_.push_back(value); }

int Stack::Pop() {
  auto result = data_.back();
  data_.pop_back();
  return result;
}

void MinStack::Push(int value) {
  if (GetMin() < value)
    min_.Push(GetMin());
  else
    min_.Push(value);
  data_.Push(value);
}

int MinStack::Pop() {
  auto result = data_.Pop();
  min_.Pop();
  return result;
}

int MinStack::GetMin() {
  auto result = min_.Pop();
  min_.Push(result);
  return result;
}