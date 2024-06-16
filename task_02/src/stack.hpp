#pragma once

#include <stack>
#include <utility>
#include <vector>

class Stack {
 public:
  void Push(int value) { data_.push_back(value); }
  int Pop();

 private:
  std::vector<int> data_;
};

class MinStack {
 public:
  void Push(int value);
  int Pop();
  int GetMin() { return current_minimum_; };

 private:
  std::vector<std::pair<int, int>> data_;
  int current_minimum_ = 1e9;
};
