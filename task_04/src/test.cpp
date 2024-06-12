
#include <gtest/gtest.h>

#include <heap.hpp>
#include <stdexcept>

TEST(BinaryHeap, Simple) {
  BinaryHeap<int> heap;
  heap.insert(37);
  heap.insert(212);
  heap.insert(0);
  ASSERT_EQ(heap.extractMin(), 0);
  ASSERT_EQ(heap.extractMin(), 37);
  ASSERT_EQ(heap.extractMin(), 212);
  heap.insert(34);
  ASSERT_EQ(heap.extractMin(), 34);
  heap.insert(201);
  heap.insert(0);
  heap.insert(16);
  ASSERT_EQ(heap.extractMin(), 0);
  heap.insert(345);
  ASSERT_EQ(heap.extractMin(), 16);
  ASSERT_EQ(heap.extractMin(), 201);
  ASSERT_EQ(heap.extractMin(), 345);
}

TEST(BinaryHeap, Vectors) {
  BinaryHeap<int> heap{98, 29, 4, 92, 48, 35, 11, 41, 84, 49};
  ASSERT_EQ(heap.extractMin(), 4);
  ASSERT_EQ(heap.extractMin(), 11);
  ASSERT_EQ(heap.extractMin(), 29);
  ASSERT_EQ(heap.extractMin(), 35);
  ASSERT_EQ(heap.extractMin(), 41);
  ASSERT_EQ(heap.extractMin(), 48);
  ASSERT_EQ(heap.extractMin(), 49);
  ASSERT_EQ(heap.extractMin(), 84);
  ASSERT_EQ(heap.extractMin(), 92);
  ASSERT_EQ(heap.extractMin(), 98);
}

TEST(BinaryHeap, Exceptions) {
  BinaryHeap<int> heap;
  ASSERT_THROW(heap.extractMin(), std::underflow_error);
  heap.insert(12);
  heap.insert(13);
  ASSERT_EQ(heap.extractMin(), 12);
  ASSERT_EQ(heap.extractMin(), 13);
  ASSERT_THROW(heap.extractMin(), std::underflow_error);
}
