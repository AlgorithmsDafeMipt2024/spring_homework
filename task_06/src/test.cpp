
#include <gtest/gtest.h>

#include "find_order_statistic.hpp"

TEST(TopologySort, Simple) {
  ASSERT_EQ(1, 1);  // Stack []
}

TEST(k_ordinal_statistics, empty_array) {
  std::vector<int> vector1 = {};
  ASSERT_EQ(FindOrderStatistic(vector1, 0), -1);
}

TEST(k_ordinal_statistics, wrong_n) {
  std::vector<int> vector1 = {1, 2, 3};
  ASSERT_EQ(FindOrderStatistic(vector1, 3), -1);
}

TEST(k_ordinal_statistics, already_sorted) {
  std::vector<int> vector2 = {69, 228, 420, 1488};
  ASSERT_EQ(69, FindOrderStatistic(vector2, 0));
  ASSERT_EQ(420, FindOrderStatistic(vector2, 2));
  ASSERT_EQ(1488, FindOrderStatistic(vector2, 3));
}

TEST(k_ordinal_statistics, simple_1) {
  std::vector<int> vector3 = {45, 13, 5, 100, 120, 46, 10};
  ASSERT_EQ(46, FindOrderStatistic(vector3, 4));
  ASSERT_EQ(120, FindOrderStatistic(vector3, 6));
  ASSERT_EQ(5, FindOrderStatistic(vector3, 0));
}

TEST(k_ordinal_statistics, simple_2) {
  std::vector<int> vector4 = {24, 10, -1, -2, -3, -69, -420};
  ASSERT_EQ(-1, FindOrderStatistic(vector4, 4));
  ASSERT_EQ(-420, FindOrderStatistic(vector4, 0));
}