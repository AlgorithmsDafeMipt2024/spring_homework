
#include <gtest/gtest.h>

#include <stack>

#include "stack.hpp"

TEST(StackTest, Simple) {
  Stack<int> stack;
  // в стандартной реализации у стека pop() имеет void
  stack.Push(1);              // Stack [1]
  ASSERT_EQ(stack.Top(), 1);  // Stack [1]
  stack.Pop();                // Stack []
  stack.Push(1);              // Stack [1]
  stack.Push(2);              // Stack [1, 2]
  ASSERT_EQ(stack.Top(), 2);  // Stack [1, 2]
  stack.Pop();                // Stack [1]
  ASSERT_EQ(stack.Top(), 1);  // Stack [1]
  stack.Pop();                // Stack []
  stack.Push(1);              // Stack [1]
  stack.Push(2);              // Stack [1, 2]
  ASSERT_EQ(stack.Top(), 2);  // Stack [1, 2]
  stack.Pop();                // Stack [1]
  stack.Push(3);              // Stack [1, 3]
  ASSERT_EQ(stack.Top(), 3);  // Stack [1, 3]
  stack.Pop();                // Stack [1]
  ASSERT_EQ(stack.Top(), 1);  // Stack [1]
  stack.Pop();
}

TEST(MinStackTest, Simple) {
  MinStack stack;
  stack.Push(1);  // Stack [1]
  ASSERT_EQ(stack.GetMin(), 1);
  ASSERT_EQ(stack.Pop(), 1);  // Stack []
  stack.Push(1);              // Stack [1]
  stack.Push(2);              // Stack [1, 2]
  ASSERT_EQ(stack.GetMin(), 1);
  ASSERT_EQ(stack.Pop(), 2);  // Stack [1]
  ASSERT_EQ(stack.Pop(), 1);  // Stack []
  stack.Push(1);              // Stack [1]
  stack.Push(2);              // Stack [1, 2]
  ASSERT_EQ(stack.GetMin(), 1);
  ASSERT_EQ(stack.Pop(), 2);  // Stack [1]
  stack.Push(3);              // Stack [1, 3]
  ASSERT_EQ(stack.GetMin(), 1);
  ASSERT_EQ(stack.Pop(), 3);  // Stack [1]
  ASSERT_EQ(stack.Pop(), 1);  // Stack []
}