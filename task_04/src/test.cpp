
#include <gtest/gtest.h>

#include "heap.hpp"

TEST(TopologySort, Simple) {
  Heap heap;

  EXPECT_THROW(heap.ExtractMin(), std::out_of_range);
  EXPECT_THROW(heap.GetMin(), std::out_of_range);

  heap.Insert(-1);

  heap.ExtractMin();
  EXPECT_THROW(heap.ExtractMin(), std::out_of_range);

  ASSERT_EQ(heap.Size(), 0);
  heap.Insert(5);
  ASSERT_EQ(heap.GetMin(), 5);
  heap.Insert(3);
  heap.Insert(1);
  heap.Insert(7);
  heap.Insert(-2);
  heap.ExtractMin();
  ASSERT_EQ(heap.Size(), 4);
  ASSERT_EQ(heap.GetMin(), 1);
}