#include "stack.hpp"

#include <algorithm>

void Stack::Push(int value) { elements_.push_back(value); }

int Stack::Pop() {
  if (elements_.size() == 0) {
    throw std::out_of_range("Stack is empty");
  }
  int result = elements_.back();
  elements_.pop_back();
  return result;
}

int Stack::Size() { return elements_.size(); }

int Stack::Top() {
  if (elements_.size() == 0) {
    throw std::out_of_range("Stack is empty");
  }
  return elements_.back();
}

///////////////////

void MinStack::Push(int value) {
  main_stack_.Push(value);
  if (min_stack_.Size() && min_stack_.Top() > value) {
    min_stack_.Push(value);
  }
  if (min_stack_.Size() == 0) {
    min_stack_.Push(value);
  }
}

int MinStack::Pop() {
  if (main_stack_.Size() && min_stack_.Size() &&
      main_stack_.Top() == min_stack_.Top()) {
    min_stack_.Pop();
  }
  return main_stack_.Pop();
}

int MinStack::GetMin() { return min_stack_.Top(); }

int MinStack::Top() { return main_stack_.Top(); }

int MinStack::Size() { return main_stack_.Size(); }