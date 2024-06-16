#pragma once

#include <stack>
#include <vector>

class Stack {
 public:
  void Push(int value);
  int Pop();
  int Top();
  int Size();

 private:
  std::vector<int> elements_;
};

class MinStack {
 public:
  void Push(int value);
  int Pop();
  int Top();
  int GetMin();
  int Size();

 private:
  Stack main_stack_;
  Stack min_stack_;
};
