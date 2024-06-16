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
  int value = t->value_;
  delete t;
  return value;
}

Stack::Node* Stack::Top() { return top_; }
void MinStack::Push(int value) {
  if (data_.CheckTop()) {
    min_values_.Push(value);
  } else {
    min_values_.Push(std::min(value, data_.GetTopValue()));
  }
  data_.Push(value);
}

int MinStack::Pop() {
  int t = min_values_.Pop();
  return data_.Pop();
}

int MinStack::GetMin() { return min_values_.GetTopValue(); }