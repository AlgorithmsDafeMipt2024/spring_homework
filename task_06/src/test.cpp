
#include <gtest/gtest.h>

#include <stdexcept>
#include <string>

#include "n_order_statistics.hpp"

using std::string;

TEST(k_ordinal_statistics, empty_array) {
  std::vector<int> vector1 = {};
  EXPECT_THROW(NthOrderStatistics(vector1, 0), std::logic_error);
}

TEST(k_ordinal_statistics, wrong_n) {
  std::vector<int> vector1 = {1, 2, 3};
  EXPECT_THROW(NthOrderStatistics(vector1, 3), std::logic_error);
}

TEST(k_ordinal_statistics, already_sorted) {
  std::vector<int> vector2 = {69, 228, 420, 1488};
  ASSERT_EQ(69, NthOrderStatistics(vector2, 0));
  ASSERT_EQ(420, NthOrderStatistics(vector2, 2));
  ASSERT_EQ(1488, NthOrderStatistics(vector2, 3));
}

TEST(k_ordinal_statistics, simple_1) {
  std::vector<int> vector3 = {45, 13, 5, 100, 120, 46, 10};
  ASSERT_EQ(46, NthOrderStatistics(vector3, 4));
  ASSERT_EQ(120, NthOrderStatistics(vector3, 6));
  ASSERT_EQ(5, NthOrderStatistics(vector3, 0));
}

TEST(k_ordinal_statistics, simple_2) {
  std::vector<int> vector4 = {24, 10, -1, -2, -3, -69, -420};
  ASSERT_EQ(-1, NthOrderStatistics(vector4, 4));
  ASSERT_EQ(-420, NthOrderStatistics(vector4, 0));
}