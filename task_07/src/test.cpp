
#include <gtest/gtest.h>

#include "AVL_Tree.hpp"

TEST(AVLTreeTest, InsertAndContains) {
  AVL_Tree tree;

  tree.Insert(10);
  tree.Insert(5);
  tree.Insert(15);

  ASSERT_EQ(tree.Contains(10), true);
  tree.Remove(10);
  ASSERT_EQ(tree.Contains(5), true);
  ASSERT_EQ(tree.Contains(15), true);
  ASSERT_EQ(tree.Contains(20), false);
  ASSERT_EQ(tree.Contains(10), false);
}

TEST(AVLTreeTest, DuplicateInsert) {
  AVL_Tree tree;
  tree.Insert(5);
  tree.Insert(5);
  tree.Insert(5);
  ASSERT_EQ(tree.Contains(5), true);
}

TEST(AVLTreeTest, RemoveNonExisting) {
  AVL_Tree tree;
  tree.Insert(5);
  tree.Remove(10);
  ASSERT_EQ(tree.Contains(5), true);
  ASSERT_EQ(tree.Contains(10), false);
}

TEST(AVLTreeTest, LeftRotation) {
  AVL_Tree tree;
  tree.Insert(30);
  tree.Insert(20);
  tree.Insert(10);
  ASSERT_EQ(tree.Contains(10), true);
  ASSERT_EQ(tree.Contains(20), true);
  ASSERT_EQ(tree.Contains(30), true);
}

TEST(AVLTreeTest, RightRotation) {
  AVL_Tree tree;
  tree.Insert(10);
  tree.Insert(20);
  tree.Insert(30);
  ASSERT_EQ(tree.Contains(10), true);
  ASSERT_EQ(tree.Contains(20), true);
  ASSERT_EQ(tree.Contains(30), true);
}

TEST(AVLTreeTest, RandomData) {
  AVL_Tree tree;
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> dist(1, 1000);

  std::vector<int> data(100);
  for (int i = 0; i < 100; ++i) {
    data[i] = dist(gen);
  }

  std::shuffle(data.begin(), data.end(), gen);

  for (int value : data) {
    tree.Insert(value);
  }

  for (int value : data) {
    ASSERT_EQ(tree.Contains(value), true);
  }

  std::shuffle(data.begin(), data.end(), gen);
  for (int i = 0; i < 50; ++i) {
    tree.Remove(data[i]);
  }

  for (int i = 50; i < 100; ++i) {
    ASSERT_EQ(tree.Contains(data[i]), true);
  }
}
