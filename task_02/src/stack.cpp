#include "stack.hpp"

#include <algorithm>

void MinStack::Push(int value) { data_.push_back(value); }

int MinStack::Pop() {
  auto result = data_.back();
  data_.pop_back();
  return result;
}

int MinStack::GetMin() { return *std::min_element(data_.begin(), data_.end()); }