#pragma once

#include <memory>
#include <stack>
#include <vector>

struct Node {
  int value;
  std::shared_ptr<Node> next;

  Node(int v, std::shared_ptr<Node> n) {
    value = v;
    next = n;
  }
};

struct Stack {
  std::shared_ptr<Node> top;
  size_t size = 0;

  void Push(int value);
  int Pop();
  int Get();
};

struct MinStack {
  Stack values;
  Stack minimums;

  void Push(int value);
  int Pop();
  int GetMin();
};
