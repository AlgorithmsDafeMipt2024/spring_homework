#pragma once

#include <cstddef>
#include <memory>
#include <stack>
#include <stdexcept>
#include <type_traits>
#include <vector>

template <class T>
class StackNode {
 public:
  explicit StackNode(T _data, StackNode<T> *_prev = nullptr)
      : data(_data), prevptr(_prev) {}
  StackNode() : data(), prevptr(nullptr) {}
  T data;
  StackNode<T> *prevptr;
};

template <class T>
class Stack {
 public:
  Stack() : top(nullptr), size(0) {}
  void push(T value);
  T pop();
  T getTop();
  int getSize();

 private:
  StackNode<T> *top;
  int size;
};

template <class T>
void Stack<T>::push(T value) {
  StackNode<T> *newElem = new StackNode<T>(value, top);
  size++;
  top = newElem;
}

template <class T>
T Stack<T>::pop() {
  if (size == 0) {
    throw std::underflow_error("Empty stack");
  }
  T returningValue = top->data;
  StackNode<T> *oldTop = top;
  top = top->prevptr;
  delete oldTop;
  size--;
  return returningValue;
}

template <class T>
int Stack<T>::getSize() {
  return size;
}

template <class T>
T Stack<T>::getTop() {
  if (size == 0) {
    throw std::underflow_error("Empty stack");
  }
  return top->data;
}
template <class T>
class MinStack {
 public:
  MinStack() : mainStack(), minStack() {}
  void push(T value);
  T pop();
  T getMin();
  int getSize();

 private:
  Stack<T> mainStack;
  Stack<T> minStack;
};

template <class T>
void MinStack<T>::push(T value) {
  mainStack.push(value);
  if (minStack.getSize() == 0)
    minStack.push(value);
  else
    minStack.push(std::min(value, minStack.getTop()));
}

template <class T>
T MinStack<T>::pop() {
  minStack.pop();
  return mainStack.pop();
}

template <class T>
T MinStack<T>::getMin() {
  return minStack.getTop();
}

template <class T>
int MinStack<T>::getSize() {
  return mainStack.getSize();
}
