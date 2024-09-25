#include <gtest/gtest.h>

#include <vector>

#include "bin_heap.hpp"

TEST(BinHeap, Simple) {
  BinHeap heap1({1, 2, 3, 4, 5, 6, 7});
  ASSERT_EQ(heap1.get_heap(), std::vector<int>({7, 5, 6, 4, 2, 1, 3}));
  heap1.push_value(8);
  heap1.push_value(3);
  heap1.push_value(3);
  ASSERT_EQ(heap1.pop_max(), 8);
  heap1.insert_key_value(0, 11);
  ASSERT_EQ(heap1.pop_max(), 11);
  heap1.insert_key_value(7, 20);
  ASSERT_EQ(heap1.pop_max(), 20);
  ASSERT_EQ(heap1.get_heap(), std::vector<int>({6, 5, 3, 4, 3, 1, 3}));
  heap1.insert_key_value(4, -13);
  heap1.insert_key_value(4, 7);
  ASSERT_EQ(heap1.get_heap(), std::vector<int>({7, 6, 3, 4, 5, 1, 3}));

  BinHeap heap2({0});
  ASSERT_EQ(heap2.pop_max(), 0);
  ASSERT_ANY_THROW(heap2.pop_max());
  heap2.push_value(13);
  heap2.push_value(13);
  heap2.push_value(13);
  heap2.push_value(14);
  heap2.push_value(13);
  heap2.push_value(13);
  heap2.insert_key_value(0, 13);
  ASSERT_EQ(heap2.pop_max(), 13);
  ASSERT_EQ(heap2.get_heap(), std::vector<int>({13, 13, 13, 13, 13}));
}
