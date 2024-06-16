#include <gtest/gtest.h>

#include <cstddef>

#include "temperature.hpp"

TEST(temperature, Simple) {
  std::vector<int> daily_temp_1 = days_before_warming({1, 2, 3, 4, 5});
  std::vector<int> result_1 = {1, 1, 1, 1, 0};
  ASSERT_EQ(daily_temp_1, result_1);

  std::vector<int> daily_temp_2 = days_before_warming({0});
  std::vector<int> result_2 = {0};
  ASSERT_EQ(daily_temp_2, result_2);

  std::vector<int> daily_temp_3 = days_before_warming({});
  std::vector<int> result_3 = {};
  ASSERT_EQ(daily_temp_3, result_3);

  std::vector<int> daily_temp_4 =
      days_before_warming({1, 2, -4, -5, -6, -8, 9});
  std::vector<int> result_4 = {1, 5, 4, 3, 2, 1, 0};
  ASSERT_EQ(daily_temp_4, result_4);

  std::vector<int> daily_temp_5 = days_before_warming({1, 2, 1, 2, 1, 2, 1, 2});
  std::vector<int> result_5 = {1, 2, 1, 2, 1, 2, 1, 0};
  ASSERT_EQ(daily_temp_5, result_5);

  std::vector<int> daily_temp_6 =
      days_before_warming({2, 1, 3, 1, 4, 1, 3, 1, 2, 1, 5});
  std::vector<int> result_6 = {2, 1, 2, 1, 6, 1, 4, 1, 2, 1, 0};
  ASSERT_EQ(daily_temp_6, result_6);
}