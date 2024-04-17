
#include <gtest/gtest.h>

#include <stdexcept>
#include <string>

#include "k_ordinal_statistics.hpp"

using std::string;

TEST(k_ordinal_statistics, wrong_data) {
  std::vector<int> vector1 = {};
  EXPECT_THROW(find_ordinal_statistic(vector1, 0), std::runtime_error);
}

TEST(k_ordinal_statistics, already_sorted) {
  std::vector<int> vector2 = {1, 2, 3, 4, 5, 6};
  int answer2_1 = 1;
  int answer2_2 = 4;
  int answer2_3 = 6;
  ASSERT_EQ(answer2_1, find_ordinal_statistic(vector2, 0));
  ASSERT_EQ(answer2_2, find_ordinal_statistic(vector2, 3));
  ASSERT_EQ(answer2_3, find_ordinal_statistic(vector2, 5));
}

TEST(k_ordinal_statistics, unsorted_1) {
  std::vector<int> vector3 = {10, 5, 6, 3, 4, 1, 2, 7, 8, 9};
  int answer3_1 = 5;
  int answer3_2 = 10;
  int answer3_3 = 1;
  ASSERT_EQ(answer3_1, find_ordinal_statistic(vector3, 4));
  ASSERT_EQ(answer3_2, find_ordinal_statistic(vector3, 9));
  ASSERT_EQ(answer3_3, find_ordinal_statistic(vector3, 0));
}

TEST(k_ordinal_statistics, unsorted_2) {
  std::vector<int> vector4 = {111, 201, 50, -10, -405};
  int answer4_1 = 50;
  int answer4_2 = -405;
  ASSERT_EQ(answer4_1, find_ordinal_statistic(vector4, 2));
  ASSERT_EQ(answer4_2, find_ordinal_statistic(vector4, 0));
}

TEST(k_ordinal_statistics, string_array) {
  std::vector<string> vector5 = {"bbb", "bab", "aaa", "caa", "cab"};
  string answer5_1 = "aaa";
  string answer5_2 = "bbb";
  ASSERT_EQ(answer5_1, find_ordinal_statistic(vector5, 0));
  ASSERT_EQ(answer5_2, find_ordinal_statistic(vector5, 2));
}