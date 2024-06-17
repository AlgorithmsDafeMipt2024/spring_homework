#include <bits/stdc++.h>
#include <gtest/gtest.h>

#include "avl_tree.hpp"

TEST(AVLTree_Test, Test_1) {
  AVLTree<int> tree;

  tree.Insert(1);
  ASSERT_TRUE(tree.Contains(1));
  tree.Insert(3);
  ASSERT_TRUE(tree.Contains(3));
  ASSERT_FALSE(tree.Contains(5));
}

TEST(AVLTree_Test, Test_2) {
  AVLTree<short> tree;

  tree.Insert(20);
  ASSERT_TRUE(tree.Contains(20));
  tree.Remove(20);
  ASSERT_FALSE(tree.Contains(20));
}

TEST(AVLTree_Test, Test_3) {
  AVLTree<double> tree;

  tree.Insert(10);
  tree.Remove(30);
  ASSERT_TRUE(tree.Contains(10));
  ASSERT_FALSE(tree.Contains(30));
  tree.Remove(10);
  ASSERT_FALSE(tree.Contains(10));
}

TEST(AVLTree_Test, Test_4) {
  AVLTree<long long> tree;

  tree.Insert(60000000);
  tree.Insert(40000000);
  tree.Insert(20000000);
  ASSERT_TRUE(tree.Contains(20000000));
  ASSERT_TRUE(tree.Contains(40000000));
  ASSERT_TRUE(tree.Contains(60000000));
  ASSERT_FALSE(tree.Contains(10000000));
  ASSERT_FALSE(tree.Contains(30000000));
  ASSERT_FALSE(tree.Contains(50000000));
}

TEST(AVLTree_Test, Test_5) {
  AVLTree<unsigned> tree;

  tree.Insert(10000000);
  tree.Insert(30000000);
  tree.Insert(50000000);
  ASSERT_TRUE(tree.Contains(10000000));
  ASSERT_TRUE(tree.Contains(30000000));
  ASSERT_TRUE(tree.Contains(50000000));
  ASSERT_FALSE(tree.Contains(20000000));
  ASSERT_FALSE(tree.Contains(40000000));
  ASSERT_FALSE(tree.Contains(60000000));
}
