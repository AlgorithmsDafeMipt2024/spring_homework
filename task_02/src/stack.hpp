#ifndef STACK_HPP
#define STACK_HPP
#include <exception>
#include <stdexcept>
#include <vector>

template <class T>
class Stack {
 public:
  void push(T value) { data_.push_back(value); }
  T pop() {
    if (data_.empty()) throw std::runtime_error("stack is empty");
    int result = data_.back();
    data_.pop_back();
    return result;
  }

 private:
  std::vector<T> data_;
};

#endif