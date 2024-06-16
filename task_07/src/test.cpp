
#include <gtest/gtest.h>

#include "binary_tree.hpp"

TEST(BinaryTree, Total) {
  BinaryTree<int> tree;
  std::vector<int> data = {35, 38, 12, 30, 25, 22, 18, 21, 39, 13, 40};
  for (int i = 0; i < data.size(); i++) tree.Insert(data[i]);
  for (int i = -40; i <= 40; i++) {
    bool ans = std::find(data.begin(), data.end(), i) != data.end();
    ASSERT_EQ(tree.Search(i), ans);
  }
  std::vector<int> ans_in = {12, 13, 18, 21, 22, 25, 30, 35, 38, 39, 40};
  std::vector<int> ans_pre = {25, 18, 12, 13, 22, 21, 35, 30, 38, 39, 40};
  std::vector<int> ans_post = {13, 12, 21, 22, 18, 30, 40, 39, 38, 35, 25};
  ASSERT_EQ(tree.InorderTraversal(), ans_in);
  ASSERT_EQ(tree.PreorderTraversal(), ans_pre);
  ASSERT_EQ(tree.PostorderTraversal(), ans_post);
}
