#include <gtest/gtest.h>

#include <vector>

#include "tree.hpp"

TEST(AVLTree, EmptyTree) {
  Tree<int> avl;
  ASSERT_EQ(avl.Contains(10), false);
  ASSERT_EQ(avl.Contains(5), false);
  ASSERT_EQ(avl.Contains(0), false);
}

TEST(AVLTree, AddElements) {
  Tree<int> avl;
  avl.Push(10);
  avl.Push(5);
  avl.Push(15);
  ASSERT_EQ(avl.Contains(10), true);
  ASSERT_EQ(avl.Contains(5), true);
  ASSERT_EQ(avl.Contains(15), true);
}

TEST(AVLTree, RemoveElements) {
  Tree<int> avl;
  avl.Push(10);
  avl.Push(5);
  avl.Push(15);
  avl.Pop(5);
  ASSERT_EQ(avl.Contains(5), false);
}

TEST(AVLTree, ContainsMethod) {
  Tree<int> avl;
  avl.Push(10);
  avl.Push(5);
  ASSERT_EQ(avl.Contains(10), true);
  ASSERT_EQ(avl.Contains(5), true);
  ASSERT_EQ(avl.Contains(15), false);
}

TEST(AVLTree, RemoveNonExistentElement) {
  Tree<int> avl;
  avl.Push(10);
  avl.Push(5);
  avl.Pop(15);
  ASSERT_EQ(avl.Contains(15), false);
}

TEST(AVLTree, RemoveInEmptyTree) {
  Tree<int> avl;
  ASSERT_EQ(avl.Contains(13), false);
  avl.Pop(13);
  ASSERT_EQ(avl.Contains(13), false);
  ASSERT_EQ(avl.Contains(37), false);
}