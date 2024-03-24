
#include <gtest/gtest.h>

#include <stdexcept>
#include <vector>

#include "heap.hpp"

TEST(Heap, Simple) {
  Heap heap_1;

  heap_1.Push(4);
  heap_1.Push(2);
  heap_1.Push(5);
  ASSERT_EQ(heap_1.Pop(), 2);
  ASSERT_EQ(heap_1.Top(), 4);
  ASSERT_EQ(heap_1.Pop(), 4);
  ASSERT_EQ(heap_1.Pop(), 5);
  EXPECT_THROW(heap_1.Pop(), std::out_of_range);
  EXPECT_THROW(heap_1.Top(), std::out_of_range);
  ASSERT_EQ(heap_1.Empty(), true);

  std::vector<int> array{1, 6, 2, 0, 11, 8, 8, 9, 2, 1};
  Heap heap_2(array);

  ASSERT_EQ(heap_2.Size(), 10);
  heap_2.Push(-1);
  ASSERT_EQ(heap_2.Size(), 11);
  ASSERT_EQ(heap_2.Top(), -1);
  ASSERT_EQ(heap_2.Top(), heap_2.Pop());
}
