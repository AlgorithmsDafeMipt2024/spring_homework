
#include <gtest/gtest.h>

#include "splay_tree.hpp"

TEST(SplayTree, Simple) {
  SplayTree<int> st1{};
  st1.add(1, 1);
  st1.add(2, 2);
  st1.add(3, 3);

  EXPECT_TRUE(st1.root()->parent == nullptr);

  ASSERT_EQ(st1[1], 1);
  ASSERT_EQ(st1[2], 2);
  ASSERT_EQ(st1[3], 3);
}

TEST(in_order_DFS, Simple) {
  SplayTree<int> st2{};
  for (int i = 10; i >= 1; i--) st2[i] = i * i;
  std::vector<int> vector2;
  std::vector<int> assert_vector2 = {1, 4, 9, 16, 25, 36, 49, 64, 81, 100};
  in_order_DFS(st2.root(), vector2);

  EXPECT_TRUE(st2.root()->parent == nullptr);
  ASSERT_EQ(vector2, assert_vector2);
}

TEST(in_order_DFS, tree_sort) {
  SplayTree<int> st3{{4, 4},   {2, 2},   {5, 5}, {2, 2},
                     {11, 11}, {20, 20}, {1, 1}};
  std::vector<int> vector3;
  std::vector<int> assert_vector3 = {1, 2, 4, 5, 11, 20};
  in_order_DFS(st3.root(), vector3);

  EXPECT_TRUE(st3.root()->parent == nullptr);
  ASSERT_EQ(vector3, assert_vector3);
}