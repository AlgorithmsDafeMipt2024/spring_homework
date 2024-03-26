#include "stack.hpp"

#include <algorithm>
#include <memory>
#include <stdexcept>

void Stack::Push(int value) {
  top = std::make_shared<Node>(value, top);
  size++;
}

int Stack::Pop() {
  if (size == 0) throw std::length_error("Stack already empty");
  int value = top->value;
  top = std::move(top->next);
  size--;
  return value;
}

int Stack::Get() {
  if (size == 0) throw std::out_of_range("Stack is empty");
  return top->value;
}

void MinStack::Push(int value) {
  values.Push(value);
  if (minimums.size > 0 and value > minimums.Get())
    minimums.Push(minimums.Get());
  else
    minimums.Push(value);
}

int MinStack::Pop() {
  minimums.Pop();
  return values.Pop();
}

int MinStack::GetMin() {
  if (minimums.size == 0) throw std::out_of_range("Stack is empty");
  return minimums.Get();
}