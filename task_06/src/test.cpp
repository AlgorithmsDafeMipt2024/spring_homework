#include "k_stat.hpp"
#include <gtest/gtest.h>
#include <stdexcept>

TEST(k_stat, Simple) {
  std::vector<int> vec1{14, -1, 5, 21, 6, -3, 7, 93, 9, 0, 84};
  ASSERT_EQ(FindOrderStatistic(vec1, 8), 21);
  ASSERT_EQ(FindOrderStatistic(vec1, 3), 5);
  ASSERT_EQ(FindOrderStatistic(vec1, 10), 93);
  EXPECT_THROW(FindOrderStatistic(vec1, 13), std::logic_error);
  std::vector<int> vec2{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  ASSERT_EQ(FindOrderStatistic(vec2, 4), 5);
  vec2.pop_back();
  vec2.pop_back();
  vec2.push_back(-12);
  vec2.push_back(100);
  vec2.push_back(134);
  ASSERT_EQ(FindOrderStatistic(vec2, 9), 100);
}
