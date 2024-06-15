
#include <gtest/gtest.h>

#include <array>
#include <stdexcept>
#include <string>

using std::string;

#include "heap.hpp"

TEST(Heap, Empty) {
  Heap<int> hp1;
  ASSERT_EQ(hp1.Empty(), true);
  ASSERT_EQ(hp1.Size(), 0);
  hp1.Push(1);
  ASSERT_EQ(hp1.Empty(), false);
  ASSERT_EQ(hp1.Size(), 1);
  ASSERT_EQ(hp1.PopBottom(), 1);
  EXPECT_THROW(hp1.Bottom(), std::runtime_error);
  EXPECT_THROW(hp1.PopBottom(), std::runtime_error);
}
TEST(Heap, Comparable1) {
  Heap<std::array<int, 5>> hp2;
  hp2.Push({1, 1, 1, 1, 1});
  std::array<int, 5> test_array_1 = {1, 1, 1, 1, 1};
  std::array<int, 5> test_array_2 = {1, 1, 1, 1, 0};
  ASSERT_EQ(hp2.Bottom(), test_array_1);
  ASSERT_EQ(hp2.PopBottom() == test_array_2, false);
}

TEST(Heap, WithoutDuplicates) {
  Heap<int> hp3{};
  for (int value : {3, 1, 2, 4, 5}) hp3.Push(value);
  ASSERT_EQ(hp3.PopBottom(), 1);
  ASSERT_EQ(hp3.PopBottom(), 2);
  ASSERT_EQ(hp3.PopBottom(), 3);
  ASSERT_EQ(hp3.PopBottom(), 4);
  ASSERT_EQ(hp3.PopBottom(), 5);
}

TEST(Heap, WithDuplicates) {
  Heap<int> hp4{};
  for (int value : {6, 7, 7, 3, 3, 3, 1, 2}) hp4.Push(value);
  ASSERT_EQ(hp4.PopBottom(), 1);
  ASSERT_EQ(hp4.PopBottom(), 2);
  ASSERT_EQ(hp4.PopBottom(), 3);
  ASSERT_EQ(hp4.PopBottom(), 3);
  ASSERT_EQ(hp4.PopBottom(), 3);
  ASSERT_EQ(hp4.PopBottom(), 6);
  ASSERT_EQ(hp4.PopBottom(), 7);
  ASSERT_EQ(hp4.PopBottom(), 7);
}

TEST(Heap, InitListConstructor) {
  Heap<int> hp5{1, 2, 3};
  ASSERT_EQ(hp5.PopBottom(), 1);
  ASSERT_EQ(hp5.PopBottom(), 2);
  ASSERT_EQ(hp5.PopBottom(), 3);
}

TEST(StringHeap, SimpleTest) {
  Heap<string> hp6{"azz", "bzz", "zaa", "zab"};
  ASSERT_EQ(hp6.PopBottom(), "azz");
  ASSERT_EQ(hp6.PopBottom(), "bzz");
  ASSERT_EQ(hp6.PopBottom(), "zaa");
  ASSERT_EQ(hp6.PopBottom(), "zab");
}