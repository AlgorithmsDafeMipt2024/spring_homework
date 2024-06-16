#include <gtest/gtest.h>

#include <iostream>
#include <vector>

#include "max_heap.hpp"

using namespace std;

TEST(MaxHeap_Test, Test_1) {
  MaxHeap<int> heap;
  EXPECT_THROW(heap.ExtractMax(), out_of_range);
  ASSERT_EQ(heap.Size(), 0);
  EXPECT_TRUE(heap.Empty());
}

TEST(MaxHeap_Test, Test_2) {
  MaxHeap<int> heap{1, 6, 3, 8, 2};
  ASSERT_EQ(heap.ExtractMax(), 8);
  ASSERT_EQ(heap.ExtractMax(), 6);
  ASSERT_EQ(heap.ExtractMax(), 3);
  ASSERT_EQ(heap.ExtractMax(), 2);
  ASSERT_EQ(heap.ExtractMax(), 1);
  EXPECT_THROW(heap.ExtractMax(), out_of_range);
}

TEST(MaxHeap_Test, Test_3) {
  vector<int> data{1, 4, 3, 5, 0, 6};
  MaxHeap<int> heap(data);
  ASSERT_EQ(heap.ExtractMax(), 6);
  ASSERT_EQ(heap.ExtractMax(), 5);
  ASSERT_EQ(heap.ExtractMax(), 4);
  ASSERT_EQ(heap.ExtractMax(), 3);
  ASSERT_EQ(heap.ExtractMax(), 1);
  ASSERT_EQ(heap.ExtractMax(), 0);
  heap.Add(5);
  heap.Add(7);
  ASSERT_EQ(heap.ExtractMax(), 7);
  ASSERT_EQ(heap.ExtractMax(), 5);
}

TEST(MaxHeap_Test, Test_4) {
  MaxHeap<int> heap;
  heap.Add(1);
  heap.Add(2);
  heap.Add(3);
  heap.Add(4);
  heap.Add(5);
  ASSERT_EQ(heap.ExtractMax(), 5);
  ASSERT_EQ(heap.ExtractMax(), 4);
  ASSERT_EQ(heap.ExtractMax(), 3);
  ASSERT_EQ(heap.ExtractMax(), 2);
  ASSERT_EQ(heap.ExtractMax(), 1);
}

TEST(MaxHeap_Test, Test_5) {
  MaxHeap<int> heap;
  EXPECT_TRUE(heap.Empty());
  heap.Add(6);
  ASSERT_EQ(heap.Size(), 1);
  heap.Add(6);
  heap.Add(6);
  ASSERT_EQ(heap.Size(), 3);
  ASSERT_EQ(heap.ExtractMax(), 6);
  ASSERT_EQ(heap.ExtractMax(), 6);
  ASSERT_EQ(heap.ExtractMax(), 6);
}
