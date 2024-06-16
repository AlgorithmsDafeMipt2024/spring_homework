
#include <gtest/gtest.h>

#include <heap.hpp>
#include <stdexcept>

TEST(BinaryHeap, Simple) {
  BinaryHeap<int> heap;
  heap.Insert(37);
  heap.Insert(212);
  heap.Insert(0);
  ASSERT_EQ(heap.ExtractMin(), 0);
  ASSERT_EQ(heap.ExtractMin(), 37);
  ASSERT_EQ(heap.ExtractMin(), 212);
  heap.Insert(34);
  ASSERT_EQ(heap.ExtractMin(), 34);
  heap.Insert(201);
  heap.Insert(0);
  heap.Insert(16);
  ASSERT_EQ(heap.ExtractMin(), 0);
  heap.Insert(345);
  ASSERT_EQ(heap.ExtractMin(), 16);
  ASSERT_EQ(heap.ExtractMin(), 201);
  ASSERT_EQ(heap.ExtractMin(), 345);
}

TEST(BinaryHeap, Vectors) {
  BinaryHeap<int> heap{98, 29, 4, 92, 48, 35, 11, 41, 84, 49};
  ASSERT_EQ(heap.ExtractMin(), 4);
  ASSERT_EQ(heap.ExtractMin(), 11);
  ASSERT_EQ(heap.ExtractMin(), 29);
  ASSERT_EQ(heap.ExtractMin(), 35);
  ASSERT_EQ(heap.ExtractMin(), 41);
  ASSERT_EQ(heap.ExtractMin(), 48);
  ASSERT_EQ(heap.ExtractMin(), 49);
  ASSERT_EQ(heap.ExtractMin(), 84);
  ASSERT_EQ(heap.ExtractMin(), 92);
  ASSERT_EQ(heap.ExtractMin(), 98);
}

TEST(BinaryHeap, Exceptions) {
  BinaryHeap<int> heap;
  ASSERT_THROW(heap.ExtractMin(), std::underflow_error);
  heap.Insert(12);
  heap.Insert(13);
  ASSERT_EQ(heap.ExtractMin(), 12);
  ASSERT_EQ(heap.ExtractMin(), 13);
  ASSERT_THROW(heap.ExtractMin(), std::underflow_error);
}
