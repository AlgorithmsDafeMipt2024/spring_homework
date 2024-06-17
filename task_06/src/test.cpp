#include <gtest/gtest.h>

#include "find_ordinal_statistic.hpp"

TEST(FindOrdinalStatistic, Test_1) {
  vector<int> v{1, 2, 3, 4, 5, 6};
  ASSERT_EQ(FindOrdinalStatistic(v, 5), 5);
}

TEST(FindOrdinalStatistic, Test_2) {
  vector<int> v{1};
  ASSERT_EQ(FindOrdinalStatistic(v, 1), 1);
}

TEST(FindOrdinalStatistic, Test_3) {
  vector<int> v{3, 1, 2};
  ASSERT_EQ(FindOrdinalStatistic(v, 2), 2);
}

TEST(FindOrdinalStatistic, Test_4) {
  vector<int> v{};
  EXPECT_THROW(FindOrdinalStatistic(v, 0), std::logic_error);
}

TEST(FindOrdinalStatistic, Test_5) {
  vector<int> v{8, 4};
  EXPECT_THROW(FindOrdinalStatistic(v, 3), std::logic_error);
}

TEST(FindOrdinalStatistic, Test_6) {
  vector<int> v{8, 4};
  ASSERT_EQ(FindOrdinalStatistic(v, 1), 4);
}

TEST(FindOrdinalStatistic, Test_7) {
  vector<int> v{2, 4, 6, 2, 2};
  ASSERT_EQ(FindOrdinalStatistic(v, 4), 4);
}

TEST(FindOrdinalStatistic, Test_8) {
  vector<int> v{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
  ASSERT_EQ(FindOrdinalStatistic(v, 7), 1);
}

TEST(FindOrdinalStatistic, Test_9) {
  vector<int> v{46, 58, 77, 16, 26, 36, 95, 80, 74, 39, 68, 72, 60,  61, 23,
                30, 52, 9,  78, 31, 5,  55, 27, 62, 73, 57, 79, 18,  11, 54,
                51, 90, 38, 6,  21, 29, 93, 94, 81, 22, 17, 71, 7,   76, 44,
                99, 84, 82, 85, 19, 91, 63, 87, 37, 25, 14, 47, 100, 86, 66,
                88, 13, 35, 2,  4,  10, 34, 20, 69, 59, 33, 45, 32,  98, 49,
                56, 83, 12, 40, 65, 1,  53, 41, 50, 96, 89, 8,  3,   75, 42,
                28, 67, 70, 48, 92, 43, 97, 24, 15, 64};
  ASSERT_EQ(FindOrdinalStatistic(v, 100), 100);
}

TEST(FindOrdinalStatistic, Test_10) {
  vector<int> v{46, 58, 77, 16, 26, 36, 95, 80, 74, 39, 68, 72, 60,  61, 23,
                30, 52, 9,  78, 31, 5,  55, 27, 62, 73, 57, 79, 18,  11, 54,
                51, 90, 38, 6,  21, 29, 93, 94, 81, 22, 17, 71, 7,   76, 44,
                99, 84, 82, 85, 19, 91, 63, 87, 37, 25, 14, 47, 100, 86, 66,
                88, 13, 35, 2,  4,  10, 34, 20, 69, 59, 33, 45, 32,  98, 49,
                56, 83, 12, 40, 65, 1,  53, 41, 50, 96, 89, 8,  3,   75, 42,
                28, 67, 70, 48, 92, 43, 97, 24, 15, 64};
  ASSERT_EQ(FindOrdinalStatistic(v, 24), 24);
}