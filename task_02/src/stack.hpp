#pragma once

#include <memory>

struct Element {
  explicit Element(int data, std::shared_ptr<Element> prev = nullptr)
      : element{data}, prev{prev} {}

  explicit Element() : element{}, prev{nullptr} {}

  int element;

  std::shared_ptr<Element> prev;
};

class Stack {
 public:
  explicit Stack() : data_{} {}

  void Push(int value);

  int Pop();

  bool Empty() const;

  const int& Top() const;

  size_t Size() const;

 private:
  Element data_;

  size_t size_ = 0;
};

class MinStack {
 public:
  void Push(int value);
  int Pop();
  int GetMin() const;

 private:
  Stack main_stack_;
  Stack min_stack_;
};
