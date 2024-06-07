
#include <gtest/gtest.h>

#include "binary_search_tree.hpp"

TEST(binary_search_tree, 1) {
  vector<int> arr = {10, 3, 11, 5, 4, 2, 9};
  Node* root = nullptr;
  build_binary_search_tree(arr, root);
  ASSERT_EQ(find(root, 2), "Есть");
  ASSERT_EQ(find(root, 8), "Нет");
  remove(root, 2);
  ASSERT_EQ(find(root, 2), "Нет");
}
