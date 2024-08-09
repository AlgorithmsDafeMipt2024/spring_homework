#include <gtest/gtest.h>

#include <stack>
#include <stdexcept>

#include "stack.hpp"

TEST(StackTest, Simple) {
  stack<int> stack;
  stack.push(5);
  ASSERT_EQ(stack.pop(), 5);
  stack.push(4);
  ASSERT_EQ(stack.pop(), 4);
  stack.push(6);
  stack.push(2);
  ASSERT_EQ(stack.pop(), 2);
  stack.push(3);
  ASSERT_EQ(stack.pop(), 3);
  ASSERT_EQ(stack.pop(), 6);
}

TEST(MinStackTest, Simple) {
  minStack<int> stack;
  stack.push(1);
  ASSERT_EQ(stack.getMin(), 1);
  ASSERT_EQ(stack.pop(), 1);
  stack.push(1);
  stack.push(2);
  ASSERT_EQ(stack.getMin(), 1);
  ASSERT_EQ(stack.pop(), 2);
  ASSERT_EQ(stack.pop(), 1);
  stack.push(1);
  stack.push(2);
  ASSERT_EQ(stack.getMin(), 1);
  ASSERT_EQ(stack.pop(), 2);
  stack.push(3);
  ASSERT_EQ(stack.getMin(), 1);
  ASSERT_EQ(stack.pop(), 3);
  ASSERT_EQ(stack.pop(), 1);
}

TEST(MinStackTest, empty) {
  minStack<int> stack;
  ASSERT_THROW(stack.getMin(), std::runtime_error);
  ASSERT_THROW(stack.pop(), std::runtime_error);
}

TEST(StackTest, empty) {
  stack<int> stack;
  ASSERT_THROW(stack.pop(), std::runtime_error);
}