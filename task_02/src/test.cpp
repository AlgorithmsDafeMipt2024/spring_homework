
#include <gtest/gtest.h>

#include "stack.hpp"

TEST(StackTest, Simple) {
  Stack<int> stack;
  stack.Push(1);         
  ASSERT_EQ(stack.Pop(), 1);
}

TEST(MinStackTest, Simple) {
  MinStack<int> stack;
  stack.Push(3);
  stack.Push(1);
  ASSERT_EQ(stack.GetMin(), 1);
  ASSERT_EQ(stack.Pop(), 1);
}

TEST(StackTest, Complex) {
  Stack<int> stack;
  stack.Push(1);
  ASSERT_EQ(stack.Pop(), 1);
  stack.Push(1);
  stack.Push(2);
  ASSERT_EQ(stack.Pop(), 2);
  ASSERT_EQ(stack.Pop(), 1);
  stack.Push(1);
  stack.Push(2);
  ASSERT_EQ(stack.Pop(), 2);
  stack.Push(3);
  ASSERT_EQ(stack.Pop(), 3);
  ASSERT_EQ(stack.Pop(), 1);
}

TEST(MinStackTest, Complex) {
  MinStack<int> stack;
  stack.Push(1);
  ASSERT_EQ(stack.GetMin(), 1);
  ASSERT_EQ(stack.Pop(), 1);
  stack.Push(1);
  stack.Push(2);
  ASSERT_EQ(stack.GetMin(), 1);
  ASSERT_EQ(stack.Pop(), 2);
  ASSERT_EQ(stack.Pop(), 1);
  stack.Push(1);
  stack.Push(2);
  ASSERT_EQ(stack.GetMin(), 1);
  ASSERT_EQ(stack.Pop(), 2);
  stack.Push(3);
  ASSERT_EQ(stack.GetMin(), 1);
  ASSERT_EQ(stack.Pop(), 3);
  ASSERT_EQ(stack.Pop(), 1);
}