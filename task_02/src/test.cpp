
#include <gtest/gtest.h>

#include <stack>
#include <stdexcept>

#include "stack.hpp"

TEST(EmptyStack, Simple) {
  MyStack<int> stack;
  EXPECT_THROW(stack.Top(), std::runtime_error);
  EXPECT_THROW(stack.Pop(), std::runtime_error);
  stack.Push(1);
  EXPECT_NO_THROW(stack.Pop());
  EXPECT_THROW(stack.Top(), std::runtime_error);
  EXPECT_THROW(stack.Pop(), std::runtime_error);
}

TEST(StackTest, Simple) {
  MyStack<int> stack;
  stack.Push(1);              // Stack [1]
  ASSERT_EQ(stack.Pop(), 1);  // Stack []
  stack.Push(1);              // Stack [1]
  stack.Push(2);              // Stack [1, 2]
  ASSERT_EQ(stack.Pop(), 2);  // Stack [1]
  ASSERT_EQ(stack.Pop(), 1);  // Stack []
  stack.Push(1);              // Stack [1]
  stack.Push(2);              // Stack [1, 2]
  ASSERT_EQ(stack.Pop(), 2);  // Stack [1]
  stack.Push(3);              // Stack [1, 3]
  ASSERT_EQ(stack.Pop(), 3);  // Stack [1]
  ASSERT_EQ(stack.Pop(), 1);  // Stack []
}

TEST(MinStackTest, Simple) {
  MinStack<int> stack;
  stack.Push(1);  // Stack [1]
  ASSERT_EQ(stack.Min(), 1);
  ASSERT_EQ(stack.Pop(), 1);  // Stack []
  stack.Push(1);              // Stack [1]
  stack.Push(2);              // Stack [1, 2]
  ASSERT_EQ(stack.Min(), 1);
  ASSERT_EQ(stack.Pop(), 2);  // Stack [1]
  ASSERT_EQ(stack.Pop(), 1);  // Stack []
  stack.Push(1);              // Stack [1]
  stack.Push(2);              // Stack [1, 2]
  ASSERT_EQ(stack.Min(), 1);
  ASSERT_EQ(stack.Pop(), 2);  // Stack [1]
  stack.Push(3);              // Stack [1, 3]
  ASSERT_EQ(stack.Min(), 1);
  ASSERT_EQ(stack.Pop(), 3);  // Stack [1]
  ASSERT_EQ(stack.Pop(), 1);  // Stack []

  EXPECT_THROW(stack.Top(), std::runtime_error);
  EXPECT_THROW(stack.Pop(), std::runtime_error);
}

TEST(StackTest, Empty) {
  MyStack<int> stack;
  EXPECT_THROW(stack.Top(), std::runtime_error);
  EXPECT_THROW(stack.Pop(), std::runtime_error);
}