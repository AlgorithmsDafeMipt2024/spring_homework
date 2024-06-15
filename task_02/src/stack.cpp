#include "stack.hpp"

#include <memory>
#include <stdexcept>

void Stack::Push(int value) {
  auto p = std::make_shared<Node>(value);
  if (top == nullptr) {
    top = p;
  } else {
    p->next = top;
    top = p;
  }
}

int Stack::Pop() {
  if (top == nullptr) {
    throw std::logic_error("Stack_is_empty");
  }
  int val = top->value;
  top = top->next;
  return val;
}

void MinStack::Push(int value) {
  if (stack_.top == nullptr) {
    stack_.Push(value);
    min_stack_.Push(value);
    return;
  }

  if (stack_.top->value > value) {
    min_stack_.Push(value);
  } else {
    stack_.Push(value);
    min_stack_.Push(min_stack_.top->value);
  }
}

int MinStack::Pop() {
  if (stack_.top == nullptr) {
    throw std::logic_error("Stack_is_empty");
  }

  int val = stack_.top->value;
  stack_.top = stack_.top->next;
  min_stack_.top = min_stack_.top->next;
  return val;
}

int MinStack::GetMin() { return min_stack_.top->value; }
