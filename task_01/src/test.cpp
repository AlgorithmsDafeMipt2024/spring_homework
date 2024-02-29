
#include <gtest/gtest.h>

#include <utility>
#include <vector>

#include "utils.hpp"

TEST(TopologySort, Simple) {
  std::vector<int> v1{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  ASSERT_EQ(FindTargetSumInArray(v1, 0), std::make_pair(-1, -1));
  ASSERT_EQ(FindTargetSumInArray(v1, 1), std::make_pair(0, 1));
  ASSERT_EQ(FindTargetSumInArray(v1, 9), std::make_pair(4, 5));
  ASSERT_EQ(FindTargetSumInArray(v1, 11), std::make_pair(1, 10));
  ASSERT_EQ(FindTargetSumInArray(v1, -5), std::make_pair(-1, -1));

  std::vector<int> v2{0};
  ASSERT_EQ(FindTargetSumInArray(v2, 0), std::make_pair(-1, -1));
  ASSERT_EQ(FindTargetSumInArray(v2, 47), std::make_pair(-1, -1));
  ASSERT_EQ(FindTargetSumInArray(v2, -47), std::make_pair(-1, -1));

  std::vector<int> v3{-11, -6, 0, 1, 2, 4, 10, 16};
  ASSERT_EQ(FindTargetSumInArray(v3, -6), std::make_pair(1, 2));
  ASSERT_EQ(FindTargetSumInArray(v3, -7), std::make_pair(0, 5));
  ASSERT_EQ(FindTargetSumInArray(v3, -8), std::make_pair(-1, -1));
  ASSERT_EQ(FindTargetSumInArray(v3, 5), std::make_pair(0, 7));
  ASSERT_EQ(FindTargetSumInArray(v3, 4), std::make_pair(1, 6));
  ASSERT_EQ(FindTargetSumInArray(v3, 10), std::make_pair(1, 7));
  ASSERT_EQ(FindTargetSumInArray(v3, -60), std::make_pair(-1, -1));
  ASSERT_EQ(FindTargetSumInArray(v3, -12), std::make_pair(-1, -1));
  ASSERT_EQ(FindTargetSumInArray(v3, 17), std::make_pair(-1, -1));
  ASSERT_EQ(FindTargetSumInArray(v3, 11), std::make_pair(3, 6));
}