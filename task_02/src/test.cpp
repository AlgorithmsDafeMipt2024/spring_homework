
#include <gtest/gtest.h>

#include <stack>

#include "stack.hpp"

TEST(StackTest, Simple) {
  Stack<int> stack;
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

TEST(StackTest, Empty) {
  Stack<double> stack;
  EXPECT_THROW(stack.Pop(), std::out_of_range);
}

TEST(MinStackTest, Empty) {
  MinStack<int> stack;
  EXPECT_THROW(stack.Pop(), std::out_of_range);
}

TEST(MinStackTest, Empty_2) {
  MinStack<int> stack;
  EXPECT_THROW(stack.GetMin(), std::out_of_range);
}
