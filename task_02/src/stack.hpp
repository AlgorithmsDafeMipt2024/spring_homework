#pragma once

class Stack {
 private:
  struct Node {
    int value_ = 0;
    Node* prev_ = nullptr;
  };
  Node* top_ = nullptr;

 public:
  void Push(int value);
  int Pop();
  Node* Top();
};

struct MinStack {
  void Push(int value);
  int Pop();
  int GetMin();

  Stack s_;
  Stack m_;
};
