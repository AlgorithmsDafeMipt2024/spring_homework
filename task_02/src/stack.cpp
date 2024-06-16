#include "stack.hpp"

#include <algorithm>
#include <cstddef>
#include <utility>

int Stack::Pop() {
  int result = data_[data_.size() - 1];
  data_.pop_back();
  return result;
}

void MinStack::Push(int value) {
  std::pair<int, int> new_element;
  if (current_minimum_ == NULL) {
    new_element = {value, value};
  } else if (value < current_minimum_) {
    new_element = {value, value};
  } else {
    new_element = {value, current_minimum_};
  }
  data_.push_back(new_element);
  current_minimum_ = new_element.second;
}

int MinStack::Pop() {
  int result = data_[data_.size() - 1].first;
  data_.pop_back();
  if (data_.size() == 0) {
    current_minimum_ = NULL;
  } else {
    current_minimum_ = data_[data_.size() - 1].second;
  }
  return result;
}
