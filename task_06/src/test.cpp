#include <gtest/gtest.h>

#include <vector>

#include "find_order_statistic.hpp"

TEST(OrderStats, Sorted) {
  std::vector<int> v{1, 2, 3, 4, 5, 6};
  ASSERT_EQ(FindOrderStatistic(v, 0), 1);
  ASSERT_EQ(FindOrderStatistic(v, 1), 2);
  ASSERT_EQ(FindOrderStatistic(v, 2), 3);
  ASSERT_EQ(FindOrderStatistic(v, 3), 4);
  ASSERT_EQ(FindOrderStatistic(v, 4), 5);
  ASSERT_EQ(FindOrderStatistic(v, 5), 6);
}
TEST(OrderStats, InverseSorted) {
  std::vector<int> v{6, 5, 4, 3, 2, 1};
  ASSERT_EQ(FindOrderStatistic(v, 0), 1);
  ASSERT_EQ(FindOrderStatistic(v, 1), 2);
  ASSERT_EQ(FindOrderStatistic(v, 2), 3);
  ASSERT_EQ(FindOrderStatistic(v, 3), 4);
  ASSERT_EQ(FindOrderStatistic(v, 4), 5);
  ASSERT_EQ(FindOrderStatistic(v, 5), 6);
}
//[8, 22, 37, 40, 60, 61, 63, 84, 97, 99]

TEST(OrderStats, Simple1) {
  std::vector<int> v{1, 10, 2, 9, 3, 8, 4, 7, 5, 6};
  ASSERT_EQ(FindOrderStatistic(v, 0), 1);
  ASSERT_EQ(FindOrderStatistic(v, 1), 2);
  ASSERT_EQ(FindOrderStatistic(v, 2), 3);
  ASSERT_EQ(FindOrderStatistic(v, 3), 4);
  ASSERT_EQ(FindOrderStatistic(v, 4), 5);
  ASSERT_EQ(FindOrderStatistic(v, 5), 6);
  ASSERT_EQ(FindOrderStatistic(v, 6), 7);
  ASSERT_EQ(FindOrderStatistic(v, 7), 8);
  ASSERT_EQ(FindOrderStatistic(v, 8), 9);
  ASSERT_EQ(FindOrderStatistic(v, 9), 10);
}
TEST(OrderStats, Simple2) {
  std::vector<double> v{37.75, 99.53, 63.24, 22.56, 37.74,
                        60.32, 61.48, 8.15,  84.52, 97.93};
  ASSERT_EQ(FindOrderStatistic(v, 0), 8.15);
  ASSERT_EQ(FindOrderStatistic(v, 1), 22.56);
  ASSERT_EQ(FindOrderStatistic(v, 2), 37.74);
  ASSERT_EQ(FindOrderStatistic(v, 3), 37.75);
  ASSERT_EQ(FindOrderStatistic(v, 4), 60.32);
  ASSERT_EQ(FindOrderStatistic(v, 5), 61.48);
  ASSERT_EQ(FindOrderStatistic(v, 6), 63.24);
  ASSERT_EQ(FindOrderStatistic(v, 7), 84.52);
  ASSERT_EQ(FindOrderStatistic(v, 8), 97.93);
  ASSERT_EQ(FindOrderStatistic(v, 9), 99.53);
}

TEST(OrderStats, Char) {
  std::vector<char> v{'d', 's', 'a', 'b'};
  ASSERT_EQ(FindOrderStatistic(v, 1), 'b');
}
