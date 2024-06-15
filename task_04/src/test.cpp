#include <gtest/gtest.h>

#include <stdexcept>

#include "heap.hpp"

TEST(HeapMin, Simple) {
  ASSERT_EQ(FindMin(std::vector<int>{4, 5, 16, 3, 6}), 3);
  ASSERT_EQ(FindMin(std::vector<int>{29, 25, 10, 13, 14, 23, 4, 6}), 4);
  ASSERT_EQ(FindMin(std::vector<int>{29, 17, 16, 27, 6, 11}), 6);
}

TEST(EmptyHeap, Simple) {
  Heap empty_heap;

  ASSERT_EQ(empty_heap.Size(), 0);
  EXPECT_THROW(empty_heap.Top(), std::runtime_error);
  EXPECT_THROW(empty_heap.Min(), std::runtime_error);
}

TEST(Heap, Simple) {
  Heap heap;
  heap.Insert(5);
  heap.Insert(3);

  ASSERT_EQ(heap.Size(), 2);
  ASSERT_EQ(heap.Top(), 3);

  ASSERT_EQ(heap.Min(), 3);

  ASSERT_EQ(heap.Size(), 1);
  ASSERT_EQ(heap.Top(), 5);
}