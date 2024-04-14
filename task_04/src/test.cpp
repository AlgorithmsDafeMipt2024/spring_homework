
#include <gtest/gtest.h>

#include <vector>

#include "heap.hpp"

TEST(HeapTest, Simple) {
  Heap heap;
  std::vector<int> answer = {};
  heap.pop_min();
  ASSERT_EQ(heap.get_data(), answer);  // pop from empty heap

  heap.insert(1);
  heap.insert(2);
  heap.insert(3);
  heap.insert(4);
  heap.insert(5);
  heap.insert(6);

  heap.insert(0);
  answer = {0, 2, 1, 4, 5, 6, 3};
  ASSERT_EQ(heap.get_data(), answer);  // insert key, smaller than its parent

  heap.pop_min();
  answer = {1, 2, 3, 4, 5, 6};
  ASSERT_EQ(heap.get_data(), answer);  // pop from full heap

  heap.insert(100);
  answer = {1, 2, 3, 4, 5, 6, 100};
  ASSERT_EQ(heap.get_data(), answer);  // insert key, smaller than its parent
}
