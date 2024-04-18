
#include <gtest/gtest.h>

#include "splay_tree.hpp"

TEST(SplayTree, Simple) {
  SplayTree<int, int> st1{};
  st1.add(1, 1);
  st1.add(2, 2);
  st1.add(3, 3);
  ASSERT_EQ(st1[1], 1);
  ASSERT_EQ(st1[2], 2);
  ASSERT_EQ(st1[3], 3);
}