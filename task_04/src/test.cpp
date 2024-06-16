#include <gtest/gtest.h>

#include <iostream>
#include <vector>

#include "heap.hpp"

TEST(BinaryMinHeap_test, Empty) {
  MinHeap<int> heap;
  ASSERT_EQ(heap.Empty(), true);
  ASSERT_EQ(heap.Size(), 0);
  heap.Add(1);
  ASSERT_EQ(heap.Empty(), false);
  ASSERT_EQ(heap.Size(), 1);
  ASSERT_EQ(heap.ExtractMin(), 1);
  EXPECT_THROW(heap.ExtractMin(), std::out_of_range);
}

TEST(BinaryMinHeap_test, WithoutDuplicates) {
  MinHeap<int> heap{};
  for (int value : {3, 1, 2, 4, 5}) heap.Add(value);
  ASSERT_EQ(heap.ExtractMin(), 1);
  ASSERT_EQ(heap.ExtractMin(), 2);
  ASSERT_EQ(heap.ExtractMin(), 3);
  ASSERT_EQ(heap.ExtractMin(), 4);
  ASSERT_EQ(heap.ExtractMin(), 5);
}

TEST(BinaryMinHeap_test, WithDuplicates) {
  MinHeap<int> heap{};
  for (int value : {6, 7, 7, 3, 3, 3, 1, 2}) heap.Add(value);
  ASSERT_EQ(heap.ExtractMin(), 1);
  ASSERT_EQ(heap.ExtractMin(), 2);
  ASSERT_EQ(heap.ExtractMin(), 3);
  ASSERT_EQ(heap.ExtractMin(), 3);
  ASSERT_EQ(heap.ExtractMin(), 3);
  ASSERT_EQ(heap.ExtractMin(), 6);
  ASSERT_EQ(heap.ExtractMin(), 7);
  ASSERT_EQ(heap.ExtractMin(), 7);
}

TEST(BinaryMinHeap_test, ConstructorTest) {
  std::vector<int> h{1, 2, 3};
  MinHeap<int> heap{h};
  ASSERT_EQ(heap.ExtractMin(), 1);
  ASSERT_EQ(heap.ExtractMin(), 2);
  ASSERT_EQ(heap.ExtractMin(), 3);
}

TEST(BinaryMinHeap_test, EmptyHeapTest) {
  MinHeap<int> heap;
  EXPECT_TRUE(heap.Empty());
}

TEST(BinaryMinHeap_test, AddElementTest) {
  MinHeap<int> heap;
  heap.Add(5);
  EXPECT_EQ(heap.Size(), 1);
  EXPECT_EQ(heap.ExtractMin(), 5);
}

TEST(BinaryMinHeap_test, ExtractMinTest) {
  MinHeap<int> heap;
  heap.Add(5);
  heap.Add(3);
  heap.Add(7);
  EXPECT_EQ(heap.ExtractMin(), 3);
  EXPECT_EQ(heap.Size(), 2);
}

TEST(BinaryMinHeap_test, HeapPropertyAfterAddTest) {
  MinHeap<int> heap;
  heap.Add(5);
  heap.Add(3);
  heap.Add(7);
  heap.Add(2);
  heap.Add(6);
  EXPECT_EQ(heap.ExtractMin(), 2);
}

TEST(BinaryMinHeap_test, HeapPropertyAfterExtractMinTest) {
  MinHeap<int> heap;
  heap.Add(5);
  heap.Add(3);
  heap.Add(7);
  heap.Add(2);
  heap.Add(6);
  heap.ExtractMin();
  EXPECT_EQ(heap.ExtractMin(), 3);
}

TEST(BinaryMinHeap_test, AddDuplicateElementsTest) {
  MinHeap<int> heap;
  heap.Add(5);
  heap.Add(3);
  heap.Add(5);
  EXPECT_EQ(heap.ExtractMin(), 3);
  EXPECT_EQ(heap.ExtractMin(), 5);
  EXPECT_EQ(heap.ExtractMin(), 5);
}

TEST(BinaryMinHeap_test, ExtractMinFromEmptyHeap) {
  MinHeap<int> heap;
  ASSERT_THROW(heap.ExtractMin(), std::out_of_range);
}

TEST(BinaryMinHeap_test, AddAndExtractMinLargeData) {
  MinHeap<int> heap;
  for (int i = 10000; i > 0; --i) {
    heap.Add(i);
  }
  for (int i = 1; i <= 100; ++i) {
    EXPECT_EQ(heap.ExtractMin(), i);
  }
}

TEST(BinaryMinHeap_test, ExtractMinWithDuplicates) {
  MinHeap<int> heap;
  heap.Add(5);
  heap.Add(3);
  heap.Add(3);
  heap.Add(7);
  heap.Add(2);
  EXPECT_EQ(heap.ExtractMin(), 2);
  EXPECT_EQ(heap.ExtractMin(), 3);
  EXPECT_EQ(heap.ExtractMin(), 3);
}

TEST(BinaryMinHeap_test, ExtractMinAfterInitializationWithVector) {
  std::vector<int> data = {8, 2, 10, 3, 5};
  MinHeap<int> heap(data);
  EXPECT_EQ(heap.ExtractMin(), 2);
}