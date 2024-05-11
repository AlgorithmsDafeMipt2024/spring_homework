#include "stack.hpp"

#include <memory>
#include <stdexcept>

void Stack::Push(int value) {
  std::shared_ptr<Node> p(new Node(value));
  if (top == nullptr) {
    top = p;
  }
  if (top != nullptr) {
    p->next = top;
  }
  top = p;
}

int Stack::Pop() {
  if (top == nullptr) {
    throw std::logic_error("Out_of_range");
  }
  int val = top->value;
  top = top->next;
  return val;
}

void MinStack::Push(int value) {
  if (st1_.top == nullptr) {
    st1_.Push(value);
    st2_.Push(value);
    return;
  }

  if (st1_.top->value > value) {
    st2_.Push(value);
  } else {
    st1_.Push(value);
    st2_.Push(st2_.top->value);
  }
}

int MinStack::Pop() {
  if (st1_.top == nullptr) {
    throw std::logic_error("Stack Underflow");
  }

  int val = st1_.top->value;
  st1_.top = st1_.top->next;
  st2_.top = st2_.top->next;
  return val;
}

int MinStack::GetMin() { return st2_.top->value; }
