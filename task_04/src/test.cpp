#include <gtest/gtest.h>

#include "heap.hpp"

TEST(heap, Test1) {
  ASSERT_EQ(Result(std::vector<int>{4, 1, 3, 2, 5}),
            (std::vector<int>{1, 2, 3, 4, 5}));
  ASSERT_EQ(Result(std::vector<int>{5, 4, 1, 3, 7, 2, 9}),
            (std::vector<int>{1, 3, 2, 5, 7, 4, 9}));
  ASSERT_EQ(FindMininum(std::vector<int>{5}), 5);
  Heap heap;
  std::vector<int> a = {8, 2, 5, 3, -10, 23, -190, 56, 79};
  heap.Build(a);
  ASSERT_EQ(heap.GetMininum(), -190);
}

TEST(heap, Test2) {
  Heap heap;
  std::vector<int> a = {45, 33, 1, 7, 8, 9};
  heap.Build(a);
  ASSERT_EQ(heap.DelMininum(), 1);
  ASSERT_EQ(heap.DelMininum(), 7);
  ASSERT_EQ(heap.DelMininum(), 8);
  ASSERT_EQ(heap.DelMininum(), 9);
  ASSERT_EQ(heap.DelMininum(), 33);
  ASSERT_EQ(heap.DelMininum(), 45);
}

TEST(heap, Test3) {
  Heap heap;
  std::vector<int> a = {-123, 2, 244, 1, 1999, 3};
  heap.Build(a);
  ASSERT_EQ(heap.DelMininum(), -123);
  ASSERT_EQ(heap.DelMininum(), 1);
  ASSERT_EQ(heap.DelMininum(), 2);
  ASSERT_EQ(heap.DelMininum(), 3);
  ASSERT_EQ(heap.DelMininum(), 244);
  ASSERT_EQ(heap.DelMininum(), 1999);
}