// test lib:
#include <gtest/gtest.h>

// my libs:
#include "binary_heap.hpp"

// std usings:
using std::cout, std::cin, std::endl;

TEST(BinaryMinHeap_test, Empty) {
  BinaryMinHeap<int> hp1;
  ASSERT_EQ(hp1.Empty(), true);
  ASSERT_EQ(hp1.Size(), 0);
  hp1.Add(1);
  ASSERT_EQ(hp1.Empty(), false);
  ASSERT_EQ(hp1.Size(), 1);
  ASSERT_EQ(hp1.ExtractRoot(), 1);
  EXPECT_THROW(hp1.GetRoot(), std::logic_error);
  EXPECT_THROW(hp1.ExtractRoot(), std::logic_error);
}

TEST(BinaryMinHeap_test, without_duplicates) {
  BinaryMinHeap<int> hp3{};
  for (int value : {3, 1, 2, 4, 5}) hp3.Add(value);
  ASSERT_EQ(hp3.ExtractRoot(), 1);
  ASSERT_EQ(hp3.ExtractRoot(), 2);
  ASSERT_EQ(hp3.ExtractRoot(), 3);
  ASSERT_EQ(hp3.ExtractRoot(), 4);
  ASSERT_EQ(hp3.ExtractRoot(), 5);
}

TEST(BinaryMinHeap_test, with_duplicates) {
  BinaryMinHeap<int> hp4{};
  for (int value : {6, 7, 7, 3, 3, 3, 1, 2}) hp4.Add(value);
  ASSERT_EQ(hp4.ExtractRoot(), 1);
  ASSERT_EQ(hp4.ExtractRoot(), 2);
  ASSERT_EQ(hp4.ExtractRoot(), 3);
  ASSERT_EQ(hp4.ExtractRoot(), 3);
  ASSERT_EQ(hp4.ExtractRoot(), 3);
  ASSERT_EQ(hp4.ExtractRoot(), 6);
  ASSERT_EQ(hp4.ExtractRoot(), 7);
  ASSERT_EQ(hp4.ExtractRoot(), 7);
}

TEST(BinaryMinHeap_test, init_list_constructor) {
  BinaryMinHeap<int> hp5{1, 2, 3};
  ASSERT_EQ(hp5.ExtractRoot(), 1);
  ASSERT_EQ(hp5.ExtractRoot(), 2);
  ASSERT_EQ(hp5.ExtractRoot(), 3);
}
