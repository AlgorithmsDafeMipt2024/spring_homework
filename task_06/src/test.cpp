#include <gtest/gtest.h>

#include <stdexcept>
#include <vector>

#include "nth_ordinal_statistics.hpp"

TEST(Nth_ordinal_statistics, Simple) {
  std::vector<int> vec = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  ASSERT_EQ(nth_ordinal_statistics(vec, 1), 1);
  ASSERT_EQ(nth_ordinal_statistics(vec, 9), 9);
  ASSERT_EQ(nth_ordinal_statistics(vec, 3), 3);
  ASSERT_EQ(nth_ordinal_statistics(vec, 5), 5);
  ASSERT_EQ(nth_ordinal_statistics(vec, 4), 4);
  ASSERT_EQ(nth_ordinal_statistics(vec, 0), 0);
  ASSERT_EQ(nth_ordinal_statistics(vec, 8), 8);
}

TEST(Nth_ordinal_statistics, Unsorted) {
  std::vector<int> vec = {9, 2, 3, 0, 7, 1, 6, 4, 8, 5};
  ASSERT_EQ(nth_ordinal_statistics(vec, 0), 0);
  ASSERT_EQ(nth_ordinal_statistics(vec, 4), 4);
  ASSERT_EQ(nth_ordinal_statistics(vec, 8), 8);
}

TEST(Nth_ordinal_statistics, Bacwards) {
  std::vector<int> vec = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
  ASSERT_EQ(nth_ordinal_statistics(vec, 0), 0);
  ASSERT_EQ(nth_ordinal_statistics(vec, 4), 4);
  ASSERT_EQ(nth_ordinal_statistics(vec, 8), 8);
}

TEST(Nth_ordinal_statistics, Empty) {
  std::vector<int> vec;
  ASSERT_THROW(nth_ordinal_statistics(vec, 0), std::runtime_error);
}

TEST(Nth_ordinal_statistics, OutOfRange) {
  std::vector<int> vec = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  ASSERT_THROW(nth_ordinal_statistics(vec, 12), std::runtime_error);
}
