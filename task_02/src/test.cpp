
#include <gtest/gtest.h>

#include <stack>

#include "stack.hpp"

TEST(StackTest, Simple) {
  MyStack<int> stack;
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
  ASSERT_EQ(stack.min(), 1);
  ASSERT_EQ(stack.pop(), 1);  // Stack []
  stack.push(1);              // Stack [1]
  stack.push(2);              // Stack [1, 2]
  ASSERT_EQ(stack.min(), 1);
  ASSERT_EQ(stack.pop(), 2);  // Stack [1]
  ASSERT_EQ(stack.pop(), 1);  // Stack []
  stack.push(1);              // Stack [1]
  stack.push(2);              // Stack [1, 2]
  ASSERT_EQ(stack.min(), 1);
  ASSERT_EQ(stack.pop(), 2);  // Stack [1]
  stack.push(3);              // Stack [1, 3]
  ASSERT_EQ(stack.min(), 1);
  ASSERT_EQ(stack.pop(), 3);  // Stack [1]
  ASSERT_EQ(stack.pop(), 1);  // Stack []
}