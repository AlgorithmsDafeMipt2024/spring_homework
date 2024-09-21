#include <gtest/gtest.h>

#include "binary_heap.hpp"
#include "util.hpp"

TEST(BinaryMinHeap_test, Empty) {
  BinaryMinHeap<int> heap;
  ASSERT_EQ(heap.Empty(), true);
  ASSERT_EQ(heap.Size(), 0);
  heap.Add(1);
  ASSERT_EQ(heap.Empty(), false);
  ASSERT_EQ(heap.Size(), 1);
  EXPECT_EQ(heap.GetMin(), 1);
  ASSERT_EQ(heap.ExtractMin(), 1);
  EXPECT_THROW(heap.GetMin(), std::underflow_error);
  EXPECT_THROW(heap.ExtractMin(), std::underflow_error);
  heap.Add(4);
  heap.Add(14);
  heap.Add(6);
  heap.Add(111);
  EXPECT_EQ(heap.GetMin(), 4);
}

TEST(BinaryMaxHeap_test, Empty) {
  BinaryMaxHeap<int> heap;
  ASSERT_EQ(heap.Empty(), true);
  ASSERT_EQ(heap.Size(), 0);
  heap.Add(1);
  ASSERT_EQ(heap.Empty(), false);
  ASSERT_EQ(heap.Size(), 1);
  EXPECT_EQ(heap.GetMax(), 1);
  ASSERT_EQ(heap.ExtractMax(), 1);
  EXPECT_THROW(heap.GetMax(), std::underflow_error);
  EXPECT_THROW(heap.ExtractMax(), std::underflow_error);
  heap.Add(4);
  heap.Add(14);
  heap.Add(6);
  heap.Add(111);
  EXPECT_EQ(heap.GetMax(), 111);
}
