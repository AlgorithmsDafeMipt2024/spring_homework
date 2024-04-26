#include <gtest/gtest.h>

#include <stack>
#include <stdexcept>

#include "stack.hpp"

TEST(StackTest, Simple) {
  Stack stack;
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

TEST(MinStackTest, Complex) {
  MinStack stack;
  stack.Push(2);
  ASSERT_EQ(stack.GetMin(), 2);
  stack.Push(1);
  ASSERT_EQ(stack.GetMin(), 1);
  stack.Push(3);
  ASSERT_EQ(stack.GetMin(), 1);
  stack.Pop();
  ASSERT_EQ(stack.GetMin(), 1);
  stack.Pop();
  ASSERT_EQ(stack.GetMin(), 2);
}

TEST(StackTest, Empty) {
  Stack stack;
  ASSERT_THROW(stack.Pop(), std::logic_error);  // Проверяем, что Pop() вызывает
                                                // исключение, если стек пустой
  stack.Push(1);
  ASSERT_NO_THROW(stack.Pop());  // Проверяем, что Pop() не вызывает исключение,
                                 // если в стеке есть элементы
}

TEST(StackTest, Behavior) {
  Stack stack;
  stack.Push(1);              // Stack [1]
  stack.Push(2);              // Stack [1, 2]
  ASSERT_EQ(stack.Pop(), 2);  // Stack [1]
  stack.Push(3);              // Stack [1, 3]
  ASSERT_EQ(stack.Pop(), 3);  // Stack [1]
  ASSERT_EQ(stack.Pop(), 1);  // Stack []
}

// Тесты для MinStack
TEST(MinStackTest, Behavior) {
  MinStack stack;
  stack.Push(2);                 // Stack [2]
  ASSERT_EQ(stack.GetMin(), 2);  // Минимальный элемент равен 2
  stack.Push(1);                 // Stack [2, 1]
  ASSERT_EQ(stack.GetMin(), 1);  // Минимальный элемент обновляется до 1
  stack.Push(3);                 // Stack [2, 1, 3]
  ASSERT_EQ(stack.GetMin(), 1);  // Минимальный элемент остается 1
  ASSERT_EQ(stack.Pop(), 3);  // Stack [2, 1]
  ASSERT_EQ(stack.GetMin(), 1);  // Минимальный элемент остается 1
  ASSERT_EQ(stack.Pop(), 2);  // Stack [2]
  ASSERT_EQ(stack.GetMin(), 2);  // Минимальный элемент обновляется до 2
  ASSERT_EQ(stack.Pop(), 2);  // Stack []
}
