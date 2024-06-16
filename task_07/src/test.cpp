
#include <gtest/gtest.h>

#include "binary_search_tree.hpp"

TEST(binary_search_tree, 1) {
  std::vector<int> arr = {10, 3, 11, 5, 4, 2, 9};
  Node* root = nullptr;
  BuildBinarySearchTree(arr, root);
  ASSERT_EQ(Find(root, 3)->value, 3);
  ASSERT_EQ(Find(root, 8), nullptr);
  ASSERT_EQ(FindMin(root)->value, 2);
  root = Remove(root, 2);
  ASSERT_EQ(Find(root, 2), nullptr);
  root = Remove(root, 1);
}
