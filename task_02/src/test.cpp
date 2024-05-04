#include <gtest/gtest.h>

#include <stack>
#include <stdexcept>

#include "stack.hpp"

TEST(StackTest, PushAndPop) {
  Stack<int> stack;
  stack.Push(1);
  stack.Push(2);
  stack.Push(3);

  ASSERT_EQ(stack.Size(), 3);
  ASSERT_EQ(stack.Top(), 3);
  ASSERT_EQ(stack.Pop(), 3);
  ASSERT_EQ(stack.Size(), 2);
  ASSERT_EQ(stack.Top(), 2);
  ASSERT_EQ(stack.Pop(), 2);
  ASSERT_EQ(stack.Size(), 1);
  ASSERT_EQ(stack.Top(), 1);
  ASSERT_EQ(stack.Pop(), 1);
  ASSERT_EQ(stack.Size(), 0);
}

TEST(StackTest, PopFromEmptyStack) {
  Stack<int> stack;
  ASSERT_THROW(stack.Pop(), std::out_of_range);
}

TEST(StackTest, TopFromEmptyStack) {
  Stack<int> stack;
  ASSERT_THROW(stack.Top(), std::out_of_range);
}

TEST(MinStackTest, PushAndPop) {
  MinStack<int> stack;
  stack.Push(3);
  stack.Push(2);
  stack.Push(1);
  stack.Push(0);

  ASSERT_EQ(stack.Size(), 4);
  ASSERT_EQ(stack.Top(), 0);
  ASSERT_EQ(stack.GetMin(), 0);
  ASSERT_EQ(stack.Pop(), 0);
  ASSERT_EQ(stack.Size(), 3);
  ASSERT_EQ(stack.Top(), 1);
  ASSERT_EQ(stack.GetMin(), 1);
  ASSERT_EQ(stack.Pop(), 1);
  ASSERT_EQ(stack.Size(), 2);
  ASSERT_EQ(stack.Top(), 2);
  ASSERT_EQ(stack.GetMin(), 2);
  ASSERT_EQ(stack.Pop(), 2);
  ASSERT_EQ(stack.Size(), 1);
  ASSERT_EQ(stack.Top(), 3);
  ASSERT_EQ(stack.GetMin(), 3);
  ASSERT_EQ(stack.Pop(), 3);
  ASSERT_EQ(stack.Size(), 0);
}

TEST(MinStackTest, PopFromEmptyStack) {
  MinStack<int> stack;
  ASSERT_THROW(stack.Pop(), std::out_of_range);
}

TEST(MinStackTest, TopFromEmptyStack) {
  MinStack<int> stack;
  ASSERT_THROW(stack.Top(), std::out_of_range);
}

TEST(MinStackTest, GetMinFromEmptyStack) {
  MinStack<int> stack;
  ASSERT_THROW(stack.GetMin(), std::out_of_range);
}
