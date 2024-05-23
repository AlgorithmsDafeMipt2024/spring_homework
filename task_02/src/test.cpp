
#include <gtest/gtest.h>

#include <stack>
#include <stdexcept>

#include "list_stacks.hpp"

TEST(StackTest, test1) {
  Stack<int> stack;
  stack.Push(1);
  stack.Pop();
  EXPECT_THROW(stack.Pop(), std::underflow_error);
  stack.Push(1);
  stack.Push(2);
  ASSERT_EQ(stack.Top(), 2);
  ASSERT_EQ(stack.Top(), 2);
  stack.Push(1000);
  stack.Push(21412);
  stack.Pop();
  stack.Pop();
  stack.Pop();
  stack.Pop();
  EXPECT_THROW(stack.Pop(), std::underflow_error);
  EXPECT_THROW(stack.Top(), std::underflow_error);
  stack.Push(1);
  stack.Push(3);
  ASSERT_EQ(stack.Top(), 3);
  stack.Pop();
  ASSERT_EQ(stack.Top(), 1);
}

TEST(MinStackTest, test2) {
  StackMin<int> stack;
  stack.Push(1);
  stack.Pop();
  EXPECT_THROW(stack.Pop(), std::underflow_error);
  stack.Push(1);
  stack.Push(2);
  ASSERT_EQ(stack.Top(), 2);
  ASSERT_EQ(stack.Top(), 2);
  stack.Push(1000);
  stack.Push(21412);
  ASSERT_EQ(stack.Min(), 1);
  stack.Pop();
  stack.Pop();
  stack.Pop();
  stack.Pop();
  EXPECT_THROW(stack.Min(), std::underflow_error);
  EXPECT_THROW(stack.Pop(), std::underflow_error);
  EXPECT_THROW(stack.Top(), std::underflow_error);
  stack.Push(1);
  stack.Push(3);
  ASSERT_EQ(stack.Top(), 3);
  stack.Pop();
  ASSERT_EQ(stack.Top(), 1);
  stack.Push(-10);
  stack.Push(-102410);
  stack.Push(10432140);
  stack.Push(0);
  stack.Push(-1010);
  ASSERT_EQ(stack.Min(), -102410);
}