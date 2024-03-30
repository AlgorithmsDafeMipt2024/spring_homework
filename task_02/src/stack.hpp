#pragma once

struct Node {
  int value_ = 0;
  Node* prev_ = nullptr;
};

struct Stack {
  void Push(int value);
  int Pop();
  Node* Top();

  Node* top_ = nullptr;
};

struct MinStack {
  void Push(int value);
  int Pop();
  int GetMin();

  Stack s_;
  Stack m_;
};
