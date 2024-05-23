
#include <gtest/gtest.h>

#include "heap.hpp"

TEST(TopologySort, Simple) {
  Heap a;
  ASSERT_EQ(a.size(), 0);
  a.Insert(5);
  ASSERT_EQ(a.GetMin(), 5);
  a.Insert(3);
  ASSERT_EQ(a.GetMin(), 3);
  a.Insert(1);
  a.Insert(7);
  a.Insert(-2);
  a.extractMin();
  ASSERT_EQ(a.size(), 4);
  ASSERT_EQ(a.GetMin(), -2);
}