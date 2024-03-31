
#include <gtest/gtest.h>

#include <stdexcept>
#include <vector>

#include "heap.hpp"

TEST(Heap, EmptyHeap) {
  Heap<int> empty_heap;
  EXPECT_THROW(empty_heap.Top(), std::runtime_error);
  EXPECT_THROW(empty_heap.Pop(), std::runtime_error);
  ASSERT_EQ(empty_heap.Empty(), true);
  ASSERT_EQ(empty_heap.Size(), 0);
}

TEST(Heap, Simple) {
  Heap<int> heap;
  heap.Push(10);
  heap.Push(5);
  heap.Push(15);
  heap.Push(3);

  ASSERT_EQ(heap.Size(), 4);
  ASSERT_EQ(heap.Top(), 3);

  ASSERT_EQ(heap.Pop(), 3);
  ASSERT_EQ(heap.Pop(), 5);

  heap.Push(7);
  ASSERT_EQ(heap.Pop(), 7);
  ASSERT_EQ(heap.Pop(), 10);
  ASSERT_EQ(heap.Pop(), 15);

  EXPECT_THROW(heap.Pop(), std::runtime_error);
}

TEST(Heap, DuplicateData) {
  Heap<int> heap;
  heap.Push(5);
  heap.Push(10);
  heap.Push(5);

  ASSERT_EQ(heap.Size(), 3);

  ASSERT_EQ(heap.Top(), 5);
  ASSERT_EQ(heap.Pop(), 5);

  ASSERT_EQ(heap.Top(), 5);
  ASSERT_EQ(heap.Pop(), 5);

  ASSERT_EQ(heap.Top(), 10);
}
