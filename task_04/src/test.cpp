#include <gtest/gtest.h>
#include "heap.hpp"
#include <iostream>

TEST(BinaryMinHeap_test, Empty) {
  BinaryMinHeap<int> heap;
  ASSERT_EQ(heap.Empty(), true);
  ASSERT_EQ(heap.Size(), 0);
  heap.Add(1);
  ASSERT_EQ(heap.Empty(), false);
  ASSERT_EQ(heap.Size(), 1);
  ASSERT_EQ(heap.ExtractMin(), 1);
  EXPECT_THROW(heap.GetMin(), std::out_of_range);
  EXPECT_THROW(heap.ExtractMin(), std::out_of_range);
}

TEST(BinaryMinHeap_test, WithoutDuplicates) {
  BinaryMinHeap<int> heap{};
  for (int value : {3, 1, 2, 4, 5}) heap.Add(value);
  ASSERT_EQ(heap.ExtractMin(), 1);
  ASSERT_EQ(heap.ExtractMin(), 2);
  ASSERT_EQ(heap.ExtractMin(), 3);
  ASSERT_EQ(heap.ExtractMin(), 4);
  ASSERT_EQ(heap.ExtractMin(), 5);
}

TEST(BinaryMinHeap_test, WithDuplicates) {
  BinaryMinHeap<int> heap{};
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

TEST(BinaryMinHeap_test, InitListConstructor) {
  BinaryMinHeap<int> heap{1, 2, 3};
  ASSERT_EQ(heap.ExtractMin(), 1);
  ASSERT_EQ(heap.ExtractMin(), 2);
  ASSERT_EQ(heap.ExtractMin(), 3);
}

TEST(BinaryMinHeap_test, EmptyHeapDataTest) {
  BinaryMinHeap<int> heap;
  EXPECT_TRUE(heap.Data().empty());
  ASSERT_EQ(heap.Data().empty(), heap.Empty());
}

TEST(BinaryMinHeap_test, AddElementTest) {
  BinaryMinHeap<int> heap;
  heap.Add(5);
  EXPECT_EQ(heap.Data().size(), 1);
  EXPECT_EQ(heap.GetMin(), 5);
}

TEST(BinaryMinHeap_test, ExtractMinTest) {
  BinaryMinHeap<int> heap;
  heap.Add(5);
  heap.Add(3);
  heap.Add(7);
  EXPECT_EQ(heap.ExtractMin(), 3);
  EXPECT_EQ(heap.Data().size(), 2);
}

TEST(BinaryMinHeap_test, GetMinTest) {
  BinaryMinHeap<int> heap;
  heap.Add(5);
  heap.Add(3);
  heap.Add(7);
  EXPECT_EQ(heap.GetMin(), 3);
}

TEST(BinaryMinHeap_test, MaintainHeapPropertyAfterAdd) {
  BinaryMinHeap<int> heap;
  heap.Add(5);
  heap.Add(3);
  heap.Add(7);
  heap.Add(2);
  heap.Add(6);
  EXPECT_EQ(heap.Data()[0], 2);  // Минимальный элемент должен быть 2
}

TEST(BinaryMinHeap_test, MaintainHeapPropertyAfterExtractMin) {
  BinaryMinHeap<int> heap;
  heap.Add(5);
  heap.Add(3);
  heap.Add(7);
  heap.Add(2);
  heap.Add(6);
  heap.ExtractMin();
  EXPECT_EQ(heap.GetMin(),
            3);  // После извлечения минимальный элемент должен быть 3
}

TEST(BinaryMinHeap_test, AddDuplicateElements) {
  BinaryMinHeap<int> heap;
  heap.Add(5);
  heap.Add(3);
  heap.Add(5);
  EXPECT_EQ(heap.GetMin(), 3);  // Минимальный элемент должен быть 3
}

TEST(BinaryMinHeap_test, AddAndRemoveNegativeElements) {
  BinaryMinHeap<int> heap;
  heap.Add(-5);
  heap.Add(3);
  heap.Add(-7);
  heap.ExtractMin();
  EXPECT_EQ(heap.GetMin(), -5);  // Минимальный элемент должен быть -5
}

TEST(BinaryMinHeap_test, ExtractMinFromEmptyHeap) {
  BinaryMinHeap<int> heap;
  ASSERT_THROW(heap.ExtractMin(), std::out_of_range);
}

TEST(BinaryMinHeap_test, AddAndExtractMinLargeData) {
  BinaryMinHeap<int> heap;
  for (int i = 1000; i > 0; --i) {
    heap.Add(i);
  }
  for (int i = 1; i <= 500; ++i) {
    EXPECT_EQ(heap.ExtractMin(), i);
  }
}

TEST(BinaryMinHeap_test, ExtractMinWithDuplicates) {
  BinaryMinHeap<int> heap;
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
  BinaryMinHeap<int> heap(data);
  EXPECT_EQ(heap.ExtractMin(), 2);
}

TEST(BinaryMinHeap_test, ExtractMinAfterInitializationWithInitializerList) {
  BinaryMinHeap<int> heap = {15, 7, 9, 4, 11};
  EXPECT_EQ(heap.ExtractMin(), 4);
}

TEST(BinaryMinHeap_test, ExtractMinAfterInitializationAndAdd) {
  std::vector<int> data = {8, 2, 10, 3, 5};
  BinaryMinHeap<int> heap(data);
  heap.Add(4);
  heap.Add(1);
  EXPECT_EQ(heap.ExtractMin(), 1);
}