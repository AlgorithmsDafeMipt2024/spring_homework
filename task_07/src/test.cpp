#include <gtest/gtest.h>

#include "avl_tree.hpp"

TEST(AVLTree, Simple) {
  AVLTree<short> tree;
  ASSERT_EQ(tree.Contains(10), false);
  ASSERT_EQ(tree.Contains(5), false);
  ASSERT_EQ(tree.Contains(15), false);
  tree.Push(10);
  tree.Push(5);
  tree.Push(15);
  ASSERT_EQ(tree.Contains(10), true);
  ASSERT_EQ(tree.Contains(5), true);
  ASSERT_EQ(tree.Contains(15), true);
  tree.Push(12);
  tree.Pop(5);
  ASSERT_EQ(tree.Contains(5), false);
  tree.Pop(15);
  ASSERT_EQ(tree.Contains(15), false);
}