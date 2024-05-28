#pragma once

#include <stack>
#include <vector>

class Stack {
 public:
  void Push(int value);
  int Pop();

 private:
  std::vector<int> data_;
};

class MinStack {
 public:
  void Push(int value);
  int Pop();
  int GetMin() { return minimum_; };

 private:
  std::vector<int> data_;
  int minimum_;
};
