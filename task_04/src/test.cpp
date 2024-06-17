
#include <gtest/gtest.h>

#include <vector>

#include "heap.hpp"

TEST(HeapTest, Simple) {
  Heap heap;
  std::vector<int> answer = {};
  heap.PopMin();
  ASSERT_EQ(heap.GetData(), answer);  // pop from empty heap

  heap.Insert(1);
  heap.Insert(2);
  heap.Insert(3);
  heap.Insert(4);
  heap.Insert(5);
  heap.Insert(6);

  heap.Insert(0);
  answer = {0, 2, 1, 4, 5, 6, 3};
  ASSERT_EQ(heap.GetData(), answer);  // insert key, smaller than its parent

  heap.PopMin();
  answer = {1, 2, 3, 4, 5, 6};
  ASSERT_EQ(heap.GetData(), answer);  // pop from full heap

  heap.Insert(100);
  answer = {1, 2, 3, 4, 5, 6, 100};
  ASSERT_EQ(heap.GetData(), answer);  // insert key, smaller than its parent
}
