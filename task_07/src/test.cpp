#include <gtest/gtest.h>

#include <avl_tree.hpp>
#include <vector>

TEST(AVLTree, test) {
  AVLTree<int> avl;
  ASSERT_EQ(avl.Contains(10), false);
  ASSERT_EQ(avl.Contains(5), false);
  ASSERT_EQ(avl.Contains(15), false);
  avl.Push(10);
  avl.Push(5);
  avl.Push(15);
  ASSERT_EQ(avl.Contains(10), true);
  ASSERT_EQ(avl.Contains(5), true);
  ASSERT_EQ(avl.Contains(15), true);
  avl.Push(12);
  avl.Pop(5);
  ASSERT_EQ(avl.Contains(5), false);
  avl.Pop(15);
  ASSERT_EQ(avl.Contains(15), false);
}