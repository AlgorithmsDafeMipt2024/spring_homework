#include "heap.hpp"
#include <gtest/gtest.h>

TEST(heap, Simple) {
  ASSERT_EQ(Find_Minimum(std::vector<int>{1, 3, 5, 6, 2, 4}), 1);
  ASSERT_EQ(Find_Minimum(std::vector<int>{11, 37, 55, 34, -6, 0, 4}), -6);
  ASSERT_EQ(Heap_Ready(std::vector<int>{4, 1, 3, 2, 5}),
            (std::vector<int>{1, 2, 3, 4, 5}));
  ASSERT_EQ(Heap_Ready(std::vector<int>{3, 1, 5, 6, 2, 4}),
            (std::vector<int>{1, 2, 4, 6, 3, 5}));
  Heap heap;
  heap.Build_heap(std::vector<int>{1, 3, 5, 7, 9, 12, 324, 5, 47, 457, 9467, -4,
                                   758, -579, -4, 0});
  ASSERT_EQ(heap.Find_Min(), -579);
}
