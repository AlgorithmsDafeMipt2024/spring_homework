
#include <gtest/gtest.h>

#include "n_statistics.hpp"

TEST(NStatistic, Simple) {
  std::vector<int> empty;
  ASSERT_EQ(FindNthStatistic(empty, 5), -1);
  std::vector<int> v1 = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  for (int i = 0; i < v1.size(); i++) {
    ASSERT_EQ(FindNthStatistic(v1, i), i);
  }
  std::vector<int> v2 = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
  for (int i = 0; i < v2.size(); i++) {
    ASSERT_EQ(FindNthStatistic(v2, i), i);
  }
  std::vector<int> v3 = {-1, 7, 1, 9, 2, 0, -3, 10, -7, 3};
  std::vector<int> ans = {-7, -3, -1, 0, 1, 2, 3, 7, 9, 10};
  for (int i = 0; i < v3.size(); i++) {
    ASSERT_EQ(FindNthStatistic(v3, i), ans[i]);
  }
}
