
#include <gtest/gtest.h>

#include <vector>

#include "merge_sort.hpp"

TEST(Merge_sort, Simple) {
  std::vector<int> data = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  merge_sort(data);
  std::vector<int> ref = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  ASSERT_TRUE(data == ref);
}

TEST(Merge_sort, Unsorted) {
  std::vector<int> data = {7, 5, 9, 1, 2, 6, 8, 3, 4};
  merge_sort(data);
  std::vector<int> ref = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  ASSERT_TRUE(data == ref);
}

TEST(Merge_sort, Reversed) {
  std::vector<int> data = {9, 8, 7, 6, 5, 4, 3, 2, 1};
  merge_sort(data);
  std::vector<int> ref = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  ASSERT_TRUE(data == ref);
}

TEST(Merge_sort, Empty) {
  std::vector<int> data = {};
  merge_sort(data);
  std::vector<int> ref = {};
  ASSERT_TRUE(data == ref);
}
