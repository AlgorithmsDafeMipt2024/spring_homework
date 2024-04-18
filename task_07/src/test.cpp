
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
  for (int i = 1; i <= 10; i++) st2[i] = i * i;
  std::cout << '\n';
  std::vector<int> vector2;
  std::vector<int> assert_vector2 = {1, 4, 9, 16, 25, 36, 49, 64, 81, 100};
  in_order_DFS(st2.root(), vector2);

  EXPECT_TRUE(st2.root()->parent == nullptr);
  ASSERT_EQ(vector2, assert_vector2);
}