#pragma once

#include <vector>

class Stack {
 public:
  struct Node {
    int value;
    Node* prev = nullptr;
  };

  void Push(int value);
  int Pop();

 private:
  Node* top = nullptr;
};

class MinStack : public Stack {
 public:
  void Push(int value);
  int Pop();
  int GetMin();

 private:
  Node* top = nullptr;
  Node* min_top = nullptr;
};
