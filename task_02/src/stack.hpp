#pragma once

class Stack {
 private:
  struct Node {
    int value_ = 0;
    Node* prev_ = nullptr;
  };
  Node* top_ = nullptr;
  Node* Top();

 public:
  void Push(int value);
  int Pop();
  bool CheckTop();
  int GetTopValue();
};

class MinStack {
 public:
  void Push(int value);
  int Pop();
  int GetMin();

 private:
  Stack s_;
  Stack m_;
};
