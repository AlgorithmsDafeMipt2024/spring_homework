#include "stack.hpp"

#include <algorithm>

void Stack::Push(int value) {
  Node* t = new Node();
  t->value_ = value;
  if (top_ == nullptr) {
    top_ = t;
  } else {
    t->prev_ = top_;
    top_ = t;
  }
}

bool Stack::CheckTop() {
  if (Top() == nullptr) {
    return true;
  } else {
    return false;
  }
}

int Stack::GetTopValue() { return Top()->value_; }

int Stack::Pop() {
  Node* t = top_;
  top_ = top_->prev_;
  return t->value_;
}

Stack::Node* Stack::Top() { return top_; }
void MinStack::Push(int value) {
  if (s_.CheckTop()) {
    m_.Push(value);
  } else {
    m_.Push(std::min(value, s_.GetTopValue()));
  }
  s_.Push(value);
}

int MinStack::Pop() {
  int t = m_.Pop();
  return s_.Pop();
}

int MinStack::GetMin() { return m_.GetTopValue(); }