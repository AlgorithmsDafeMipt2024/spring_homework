
#include <gtest/gtest.h>

#include <array>
#include <stdexcept>
#include <string>

#include "heap.hpp"

TEST(heap, empty) {
  heap<int> hp1;
  ASSERT_EQ(hp1.empty(), true);
  ASSERT_EQ(hp1.size(), 0);
  hp1.push(1);
  ASSERT_EQ(hp1.empty(), false);
  ASSERT_EQ(hp1.size(), 1);
  ASSERT_EQ(hp1.pop_bottom(), 1);
  EXPECT_THROW(hp1.bottom(), std::runtime_error);
  EXPECT_THROW(hp1.pop_bottom(), std::runtime_error);
}
TEST(heap, comparable_1) {
  heap<std::array<int, 5>> hp2;
  hp2.push({1, 1, 1, 1, 1});
  std::array<int, 5> test_array_1 = {1, 1, 1, 1, 1};
  std::array<int, 5> test_array_2 = {1, 1, 1, 1, 0};
  ASSERT_EQ(hp2.bottom(), test_array_1);
  ASSERT_EQ(hp2.pop_bottom() == test_array_2, false);
}

TEST(heap, without_duplicates) {
  heap<int> hp3{};
  for (int value : {3, 1, 2, 4, 5}) hp3.push(value);
  ASSERT_EQ(hp3.pop_bottom(), 1);
  ASSERT_EQ(hp3.pop_bottom(), 2);
  ASSERT_EQ(hp3.pop_bottom(), 3);
  ASSERT_EQ(hp3.pop_bottom(), 4);
  ASSERT_EQ(hp3.pop_bottom(), 5);
}

TEST(heap, with_duplicates) {
  heap<int> hp4{};
  for (int value : {6, 7, 7, 3, 3, 3, 1, 2}) hp4.push(value);
  ASSERT_EQ(hp4.pop_bottom(), 1);
  ASSERT_EQ(hp4.pop_bottom(), 2);
  ASSERT_EQ(hp4.pop_bottom(), 3);
  ASSERT_EQ(hp4.pop_bottom(), 3);
  ASSERT_EQ(hp4.pop_bottom(), 3);
  ASSERT_EQ(hp4.pop_bottom(), 6);
  ASSERT_EQ(hp4.pop_bottom(), 7);
  ASSERT_EQ(hp4.pop_bottom(), 7);
}

TEST(heap, init_list_constructor) {
  heap<int> hp5{1, 2, 3};
  ASSERT_EQ(hp5.pop_bottom(), 1);
  ASSERT_EQ(hp5.pop_bottom(), 2);
  ASSERT_EQ(hp5.pop_bottom(), 3);
}