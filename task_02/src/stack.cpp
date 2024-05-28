#include "stack.hpp"

#include <algorithm>

void Stack::Push(int value) { data_.push_back(value); }

int Stack::Pop() {
  int result = data_[data_.size() - 1];
  data_.pop_back();
  return result;
}

void MinStack::Push(int value) {
  data_.push_back(value);
  if (value < minimum_) {
    minimum_ = value;
  }
}

int MinStack::Pop() {
  int result = data_[data_.size() - 1];
  data_.pop_back();
  return result;
}
