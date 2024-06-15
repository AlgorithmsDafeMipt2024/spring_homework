
#include <gtest/gtest.h>

#include "heap.hpp"

TEST(TopologySort, Simple) {
  Heap a;

  EXPECT_THROW(a.ExtractMin(), std::out_of_range);
  EXPECT_THROW(a.GetMin(), std::out_of_range);

  a.Insert(-1);

  a.ExtractMin();
  EXPECT_THROW(a.ExtractMin(), std::out_of_range);

  ASSERT_EQ(a.Size(), 0);
  a.Insert(5);
  ASSERT_EQ(a.GetMin(), 5);
  a.Insert(3);
  a.Insert(1);
  a.Insert(7);
  a.Insert(-2);
  a.ExtractMin();
  ASSERT_EQ(a.Size(), 4);
  ASSERT_EQ(a.GetMin(), 1);
}