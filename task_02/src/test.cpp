
#include <gtest/gtest.h>

#include <stack>

#include "singly_list_stack.hpp"

// тесты для SinglyListStackTest

TEST(SinglyListStackTest, Simple) {
  SinglyListStack<int> stack;
  // в стандартной реализации у стека pop() имеет void
  stack.Push(1);              // SinglyListStack [1]
  ASSERT_EQ(stack.Top(), 1);  // SinglyListStack [1]
  stack.Pop();                // SinglyListStack []
  stack.Push(1);              // SinglyListStack [1]
  stack.Push(2);              // SinglyListStack [1, 2]
  ASSERT_EQ(stack.Top(), 2);  // SinglyListStack [1, 2]
  stack.Pop();                // SinglyListStack [1]
  ASSERT_EQ(stack.Top(), 1);  // SinglyListStack [1]
  stack.Pop();                // SinglyListStack []
  stack.Push(1);              // SinglyListStack [1]
  stack.Push(2);              // SinglyListStack [1, 2]
  ASSERT_EQ(stack.Top(), 2);  // SinglyListStack [1, 2]
  stack.Pop();                // SinglyListStack [1]
  stack.Push(3);              // SinglyListStack [1, 3]
  ASSERT_EQ(stack.Top(), 3);  // SinglyListStack [1, 3]
  stack.Pop();                // SinglyListStack [1]
  ASSERT_EQ(stack.Top(), 1);  // SinglyListStack [1]
  stack.Pop();
}
