
#include <gtest/gtest.h>

#include "splay_tree.hpp"

TEST(SplayTree, Empty) {
  SplayTree<int> st1{};
  st1[1] = 1;
  st1[2] = 2;
  st1[3] = 3;
  ASSERT_EQ(st1[1], 1);
  ASSERT_EQ(st1[2], 2);
  ASSERT_EQ(st1[3], 3);
}
