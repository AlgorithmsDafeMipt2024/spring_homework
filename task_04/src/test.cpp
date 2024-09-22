
#include <gtest/gtest.h>

#include <stdexcept>

#include "heap.hpp"

TEST(Heap, Simple) {
  Heap<int> heap;
  heap.push(1);
  heap.push(2);
  heap.push(-1);
  ASSERT_EQ(heap.popMin(), -1);
  ASSERT_EQ(heap.popMin(), 1);
  ASSERT_EQ(heap.popMin(), 2);
  heap.push(1);
  ASSERT_EQ(heap.popMin(), 1);
  heap.push(2);
  heap.push(-1);
  heap.push(1);
  ASSERT_EQ(heap.popMin(), -1);
  heap.push(3);
  ASSERT_EQ(heap.popMin(), 1);
  ASSERT_EQ(heap.popMin(), 2);
  ASSERT_EQ(heap.popMin(), 3);
}

TEST(Heap, empty) {
  Heap<int> heap;
  ASSERT_THROW(heap.popMin(), std::runtime_error);
}

TEST(Heap, constructor) {
  Heap<int> heap = {2, 3, 1, 5, -1};
  ASSERT_EQ(heap.popMin(), -1);
  ASSERT_EQ(heap.popMin(), 1);
  ASSERT_EQ(heap.popMin(), 2);
  std::vector<int> vec = {7, 3, -1, 4};
  Heap<int> heap2 = vec;
  ASSERT_EQ(heap2.popMin(), -1);
  ASSERT_EQ(heap2.popMin(), 3);
  ASSERT_EQ(heap2.popMin(), 4);
}