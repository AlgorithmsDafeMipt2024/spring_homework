#include <gtest/gtest.h>

#include "heap.hpp"

TEST(heap, Test1) {
  ASSERT_EQ(Result(std::vector<int>{4, 1, 3, 2, 5}),
            (std::vector<int>{1, 2, 3, 4, 5}));
  ASSERT_EQ(Result(std::vector<int>{5, 4, 1, 3, 7, 2, 9}),
            (std::vector<int>{1, 3, 2, 5, 7, 4, 9}));
  ASSERT_EQ(FindMin(std::vector<int>{5}), 5);
  Heap heap;
  std::vector<int> a = {8, 2, 5, 3, -10, 23, -190, 56, 79};
  heap.Build(a);
  ASSERT_EQ(heap.GetMin(), -190);
}
