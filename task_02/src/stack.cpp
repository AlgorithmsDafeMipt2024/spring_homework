#include "stack.hpp"

#include <memory>

void Stack::Push(int value) {
  Element new_data{value, std::make_shared<Element>(data_)};
  size_ += 1;
  data_ = new_data;
}

int Stack::Pop() {
  int deleted_element = data_.element;
  Element new_data = *data_.prev;
  data_.prev = nullptr;
  data_ = new_data;
  size_ -= 1;
  return deleted_element;
}

bool Stack::Empty() const { return data_.prev == nullptr; }

const int& Stack::Top() const { return data_.element; }

size_t Stack::Size() const { return size_; }

void MinStack::Push(int value) {
  if (main_stack_.Size() == 0) {
    min_stack_.Push(value);
    main_stack_.Push(value);
  } else {
    main_stack_.Push(value);
    if (value < min_stack_.Top())
      min_stack_.Push(value);
    else
      min_stack_.Push(min_stack_.Top());
  }
}

int MinStack::Pop() {
  int result = main_stack_.Top();
  main_stack_.Pop();
  min_stack_.Pop();
  return result;
}

int MinStack::GetMin() const { return min_stack_.Top(); }