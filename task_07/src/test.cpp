
#include <gtest/gtest.h>

#include "AVL_tree.hpp"

TEST(avlTree, Simple) {
  AVL_tree tree;

  ASSERT_EQ(tree.contains(0), false);
  ASSERT_EQ(tree.contains(-24124), false);

  tree.push(1);
  tree.push(123);
  tree.push(-1);
  tree.push(1);

  ASSERT_EQ(tree.contains(-1), true);
  ASSERT_EQ(tree.contains(0), false);

  ASSERT_EQ(tree.contains(1), true);
  tree.pop(1);
  ASSERT_EQ(tree.contains(1), true);
  tree.pop(1);
  ASSERT_EQ(tree.contains(1), false);
  tree.pop(1);

  ASSERT_EQ(tree.contains(1), false);
  ASSERT_EQ(tree.contains(123), true);
  ASSERT_EQ(tree.contains(-1), true);
  ASSERT_EQ(tree.contains(1), false);
}
