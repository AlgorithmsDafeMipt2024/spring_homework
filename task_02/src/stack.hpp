#pragma once
#include <iostream>
#include <memory>

struct Node {
  int value;
  std::shared_ptr<Node> next{nullptr};
  Node(int value) : value(value) {}
};

class Stack {
 public:
  Stack() { top = nullptr; }
  void Push(int value);
  int Pop();
  std::shared_ptr<Node> top;
};

class MinStack {
 public:
  void Push(int value);
  int Pop();
  int GetMin();

 private:
  Stack st1_;
  Stack st2_;
};
