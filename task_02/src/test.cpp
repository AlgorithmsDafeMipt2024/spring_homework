#include <gtest/gtest.h>

#include <stack>
#include <stdexcept>

#include "min_stack.hpp"
#include "stack.hpp"

TEST(StackTest, Simple) {
  Stack<int> stack;
  stack.push(1);              // Stack [1]
  ASSERT_EQ(stack.pop(), 1);  // Stack []
  stack.push(1);              // Stack [1]
  stack.push(2);              // Stack [1, 2]
  ASSERT_EQ(stack.pop(), 2);  // Stack [1]
  ASSERT_EQ(stack.pop(), 1);  // Stack []
  stack.push(1);              // Stack [1]
  stack.push(2);              // Stack [1, 2]
  ASSERT_EQ(stack.pop(), 2);  // Stack [1]
  stack.push(3);              // Stack [1, 3]
  ASSERT_EQ(stack.pop(), 3);  // Stack [1]
  ASSERT_EQ(stack.pop(), 1);  // Stack []
}

TEST(MinStackTest, Simple) {
  MinStack<int> stack;
  stack.push(1);  // Stack [1]
  ASSERT_EQ(stack.getMin(), 1);
  ASSERT_EQ(stack.pop(), 1);  // Stack []
  stack.push(1);              // Stack [1]
  stack.push(2);              // Stack [1, 2]
  ASSERT_EQ(stack.getMin(), 1);
  ASSERT_EQ(stack.pop(), 2);  // Stack [1]
  ASSERT_EQ(stack.pop(), 1);  // Stack []
  stack.push(1);              // Stack [1]
  stack.push(2);              // Stack [1, 2]
  ASSERT_EQ(stack.getMin(), 1);
  ASSERT_EQ(stack.pop(), 2);  // Stack [1]
  stack.push(3);              // Stack [1, 3]
  ASSERT_EQ(stack.getMin(), 1);
  ASSERT_EQ(stack.pop(), 3);  // Stack [1]
  ASSERT_EQ(stack.pop(), 1);  // Stack []
}

TEST(StackTest, empty) {
  Stack<int> stack;
  ASSERT_THROW(stack.pop(), std::runtime_error);
}

TEST(MinStackTest, empty) {
  MinStack<int> stack;
  ASSERT_THROW(stack.getMin(), std::runtime_error);
  ASSERT_THROW(stack.pop(), std::runtime_error);
}