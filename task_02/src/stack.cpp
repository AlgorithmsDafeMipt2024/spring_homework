#include "stack.hpp"

#include <algorithm>

void Stack::Push(int value) {
  Node* t = new Node();
  t->value_ = value;
  if (this->top_ == nullptr) {
    this->top_ = t;
  } else {
    t->prev_ = this->top_;
    this->top_ = t;
  }
}

int Stack::Pop() {
  Node* t = this->top_;
  this->top_ = this->top_->prev_;
  return t->value_;
}

Node* Stack::Top() { return this->top_; }
void MinStack::Push(int value) {
  if (s_.Top() == nullptr) {
    m_.Push(value);
  } else {
    m_.Push(std::min(value, s_.Top()->value_));
  }
  s_.Push(value);
}

int MinStack::Pop() {
  int t = m_.Pop();
  return s_.Pop();
}

int MinStack::GetMin() { return m_.Top()->value_; }