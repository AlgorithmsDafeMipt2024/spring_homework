#include <gtest/gtest.h>

#include "heap.hpp"

TEST(HeapMin, Simple) {
  ASSERT_EQ(FindMin(std::vector<int>{4, 5, 16, 3, 6}), 3);
  ASSERT_EQ(FindMin(std::vector<int>{29, 25, 10, 13, 14, 23, 4, 6}), 4);
  ASSERT_EQ(FindMin(std::vector<int>{29, 17, 16, 27, 6, 11}), 6);
}
