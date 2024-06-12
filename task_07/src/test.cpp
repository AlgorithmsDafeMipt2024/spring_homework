
#include <gtest/gtest.h>

#include "BinaryTree.hpp"

TEST(BinaryTree, Total) {
  BinaryTree<int> tree;
  std::vector<int> data = {35, 38, 12, -30, 25, 22, -12, -21, 30, -13, 40};
  for (int i = 0; i < data.size(); i++) tree.insert(data[i]);
  for (int i = -40; i <= 40; i++) {
    bool ans = std::find(data.begin(), data.end(), i) != data.end();
    ASSERT_EQ(tree.search(i), ans);
  }
  std::vector<int> ansIn = {-30, -21, -13, -12, 12, 22, 25, 30, 35, 38, 40};
  std::vector<int> ansPre = {35, 12, -30, -12, -21, -13, 25, 22, 30, 38, 40};
  std::vector<int> ansPost = {-13, -21, -12, -30, 22, 30, 25, 12, 40, 38, 35};
  ASSERT_EQ(tree.inorderTraversal(), ansIn);
  ASSERT_EQ(tree.preorderTraversal(), ansPre);
  ASSERT_EQ(tree.postorderTraversal(), ansPost);
}
