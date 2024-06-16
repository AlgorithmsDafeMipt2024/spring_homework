
#include <gtest/gtest.h>

#include <stack>

#include "stack.hpp"

TEST(StackTest, Simple) {
  Stack stack;
  stack.Push(1);
  ASSERT_EQ(stack.Pop(), 1);
  ASSERT_EQ(stack.Size(), 0);
  EXPECT_THROW(stack.Top(), std::out_of_range);
  EXPECT_THROW(stack.Pop(), std::out_of_range);
  stack.Push(3);
  stack.Push(-1);
  ASSERT_EQ(stack.Top(), -1);
}

TEST(MinStackTest, Simple) {
  MinStack stack;
  stack.Push(1);
  ASSERT_EQ(stack.Pop(), 1);
  ASSERT_EQ(stack.Size(), 0);
  EXPECT_THROW(stack.Top(), std::out_of_range);
  EXPECT_THROW(stack.Pop(), std::out_of_range);
  EXPECT_THROW(stack.GetMin(), std::out_of_range);
  stack.Push(-2);
  stack.Push(5);
  ASSERT_EQ(stack.Top(), 5);
  ASSERT_EQ(stack.GetMin(), -2);
}