
#include <gtest/gtest.h>

#include "heap.hpp"

TEST(heap, Simple) {
  heap<int> hp1;
  ASSERT_EQ(hp1.empty(), true);
  ASSERT_EQ(hp1.size(), 0);
  hp1.push(1);
  ASSERT_EQ(hp1.empty(), false);
  ASSERT_EQ(hp1.size(), 1);
}
