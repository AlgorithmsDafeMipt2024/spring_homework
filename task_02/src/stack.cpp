#include "stack.hpp"

#include <algorithm>
#include <stdexcept>

void Stack::Push(int value) {
  Node* new_top = new Node();
  new_top->value = value;
  if (top == nullptr) {
    top = new_top;
  } else {
    new_top->prev = top;
    top = new_top;
  }
}

int Stack::Pop() {
  if (top == nullptr) {
    throw std::out_of_range("Stack is out of elements");
  }
  int result = top->value;
  top = top->prev;
  return result;
}

void MinStack::Push(int value) {
  Stack::Push(value);

  Node* new_min_top = new Node();
  if (min_top == nullptr) {
    new_min_top->value = value;
    min_top = new_min_top;
  } else {
    new_min_top->value = std::min(value, min_top->value);
    new_min_top->prev = min_top;
    min_top = new_min_top;
  }
}

int MinStack::Pop() {
  int a = Stack::Pop();
  min_top = min_top->prev;
  return a;
}

int MinStack::GetMin() { return min_top->value; }