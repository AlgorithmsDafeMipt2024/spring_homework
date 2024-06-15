
#include <gtest/gtest.h>

#include "splay_tree.hpp"

TEST(SplayTree, Simple) {
  SplayTree<int> st1{};
  st1.Add(1, 1);
  st1.Add(2, 2);
  st1.Add(3, 3);

  EXPECT_TRUE(st1.Root()->parent == nullptr);

  ASSERT_EQ(st1[1], 1);
  ASSERT_EQ(st1[2], 2);
  ASSERT_EQ(st1[3], 3);
}

TEST(in_order_DFS, Simple) {
  SplayTree<int> st2{};
  for (int i = 10; i >= 1; i--) st2[i] = i * i;
  std::vector<int> vector2;
  std::vector<int> assert_vector2 = {1, 4, 9, 16, 25, 36, 49, 64, 81, 100};
  in_order_DFS(st2.Root(), vector2);

  EXPECT_TRUE(st2.Root()->parent == nullptr);
  ASSERT_EQ(vector2, assert_vector2);
}

TEST(tree_sort, Simple) {
  SplayTree<int> st3{};
  std::vector<int> data_vector1 = {2, 3, 1, 4, 5};
  for (const int& value : data_vector1) st3[value] = value;
  std::vector<int> vector3;
  std::vector<int> assert_vector3 = {1, 2, 3, 4, 5};
  in_order_DFS(st3.Root(), vector3);

  EXPECT_TRUE(st3.Root()->parent == nullptr);
  ASSERT_EQ(vector3, assert_vector3);
}

TEST(string_tree, Simple) {
  SplayTree<std::string> st4{};
  st4[1] = "hello";
  st4[5] = "this";
  st4[10] = "is";
  st4[11] = "string";
  st4[20] = "tree";

  ASSERT_EQ(st4[1], "hello");
  ASSERT_EQ(st4[5], "this");
  ASSERT_EQ(st4[10], "is");
  ASSERT_EQ(st4[11], "string");
  ASSERT_EQ(st4[20], "tree");
}

TEST(string_tree, String_keys) {
  SplayTree<std::string, std::string> st5{};
  st5["this"] = "is";
  st5["even"] = "crazier";

  ASSERT_EQ(st5["this"], "is");
  ASSERT_EQ(st5["even"], "crazier");
}