#include <gtest/gtest.h>

#include "avl_tree.hpp"

TEST(AVLTreeTest, Simple) {
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

TEST(AVLTreeTest, ConstructionFromVector) {
  std::vector<int> v = {1, 2, 3, 4, 5};
  AVLTree<int> tree(v);
  ASSERT_TRUE(tree.Contains(1));
  ASSERT_TRUE(tree.Contains(2));
  ASSERT_TRUE(tree.Contains(3));
  ASSERT_TRUE(tree.Contains(4));
  ASSERT_TRUE(tree.Contains(5));
}

TEST(AVLTreeTest, ConstructionFromInitializerList) {
  AVLTree<int> tree{1, 2, 3, 4, 5};
  ASSERT_TRUE(tree.Contains(1));
  ASSERT_TRUE(tree.Contains(2));
  ASSERT_TRUE(tree.Contains(3));
  ASSERT_TRUE(tree.Contains(4));
  ASSERT_TRUE(tree.Contains(5));
}

TEST(AVLTreeTest, ConstructionFromList) {
  std::list<int> l = {1, 2, 3, 4, 5};
  AVLTree<int> tree(l);
  ASSERT_TRUE(tree.Contains(1));
  ASSERT_TRUE(tree.Contains(2));
  ASSERT_TRUE(tree.Contains(3));
  ASSERT_TRUE(tree.Contains(4));
  ASSERT_TRUE(tree.Contains(5));
}

TEST(AVLTreeTest, PushAndContains) {
  AVLTree<int> tree;
  ASSERT_FALSE(tree.Contains(1));
  tree.Push(1);
  ASSERT_TRUE(tree.Contains(1));
}

TEST(AVLTreeTest, PopAndContains) {
  AVLTree<int> tree{1, 2, 3, 4, 5};
  ASSERT_TRUE(tree.Contains(3));
  tree.Pop(3);
  ASSERT_FALSE(tree.Contains(3));
}
