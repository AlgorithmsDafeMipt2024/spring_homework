#pragma once

#include <concepts/comparable.hpp>
#include <concepts/constructable.hpp>
#include <listnode.hpp>
#include <stack>
#include <stdexcept>

template <typename CustomClass>
concept constructable_and_comparable =
    comparable<CustomClass> && constructable<CustomClass>;

template <constructable CustomClass>
class Stack {
 public:
  Stack() : top_{nullptr} {}

  void Push(CustomClass value);
  CustomClass Top();
  CustomClass Pop();
  bool Empty() const { return top_ == nullptr; }

 private:
  ListNode<CustomClass>* top_;
};

template <constructable CustomClass>
void Stack<CustomClass>::Push(CustomClass value) {
  if (top_ == nullptr)
    top_ = new ListNode(value);
  else {
    top_->AddNodeFront(value);
    top_ = top_->next;
  }
}

template <constructable CustomClass>
CustomClass Stack<CustomClass>::Top() {
  if (top_ == nullptr) throw std::out_of_range("Empty stack\n");
  return top_->data;
}

template <constructable CustomClass>
CustomClass Stack<CustomClass>::Pop() {
  if (top_ == nullptr) throw std::out_of_range("Empty stack\n");
  ListNode<CustomClass>* temp = top_->prev;
  CustomClass val = top_->data;
  delete top_;
  top_ = temp;
  return val;
}

template <constructable_and_comparable CustomClass>
class MinStack {
 public:
  void Push(CustomClass value);

  CustomClass Top();
  CustomClass Pop();
  CustomClass GetMin();

 private:
  Stack<std::pair<CustomClass, CustomClass>> stack;
};

template <constructable_and_comparable CustomClass>
void MinStack<CustomClass>::Push(CustomClass value) {
  if (stack.Empty())
    stack.Push({value, value});
  else
    stack.Push({value, std::min(value, stack.Top().second)});
}

template <constructable_and_comparable CustomClass>
CustomClass MinStack<CustomClass>::Pop() {
  return stack.Pop().first;
}

template <constructable_and_comparable CustomClass>
CustomClass MinStack<CustomClass>::GetMin() {
  return stack.Top().second;
}

template <constructable_and_comparable CustomClass>
CustomClass MinStack<CustomClass>::Top() {
  return stack.Top().first;
}