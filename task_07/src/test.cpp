
#include <gtest/gtest.h>

#include "search_tree.hpp"

TEST(search_tree, Simple) {
  BinarySearchTree Tree;

  Tree.Insert(12);
  Tree.Insert(7);
  Tree.Insert(11);
  Tree.Insert(4);
  Tree.Insert(-9);
  ASSERT_EQ(Tree.Find(13), nullptr);
  ASSERT_EQ(Tree.Find(11)->value, 11);
  ASSERT_EQ(Tree.Find(-9)->value, -9);
  Tree.Remove(-9);
  ASSERT_EQ(Tree.Find(-9), nullptr);

  Tree.Remove(12);
  Tree.Remove(11);
  Tree.Insert(999);
  ASSERT_EQ(Tree.Find(999)->right, nullptr);
  ASSERT_EQ(Tree.Find(4)->left, nullptr);
  ASSERT_EQ(Tree.Find(7)->value, 7);
  ASSERT_EQ(Tree.Find(0), nullptr);
}
