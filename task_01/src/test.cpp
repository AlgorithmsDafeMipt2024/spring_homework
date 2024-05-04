
#include <gtest/gtest.h>

#include "solution.h"

TEST(solution, simple) {
  std::vector<int> v1 = {-2, 2, 3, 3, 5, 9, 11, 13, 14, 15};
  std::pair<int, int> p1 = {-1, -1};
  ASSERT_EQ(p1, solution(10, v1));

  std::vector<int> v2 = {-2, 2, 3, 3, 5, 8, 11, 13, 14, 15};
  std::pair<int, int> p2 = {1, 5};
  ASSERT_EQ(p2, solution(10, v2));

  std::vector<int> v3 = {};
  std::pair<int, int> p3 = {-1, -1};
  ASSERT_EQ(p3, solution(0, v3));

  std::vector<int> v4 = {1};
  std::pair<int, int> p4 = {-1, -1};
  ASSERT_EQ(p4, solution(1, v4));

  std::vector<int> v5 = {1, 2};
  std::pair<int, int> p5 = {0, 1};
  ASSERT_EQ(p5, solution(3, v5));

  // if there are multiple solutions, the algorithm
  // will pick the one, in which sum of i and j is the least,
  // where i and j are indices of numbers, which sum is equal to needed number
  std::vector<int> v6 = {1, 1, 1, 1, 1, 1, 1, 1, 1};
  std::pair<int, int> p6 = {0, 1};
  ASSERT_EQ(p6, solution(2, v6));

  // in case there are multiple solutions in which i+j is the least,
  // the algorithm will pick the one, in which i is greater
  std::vector<int> v7 = {1, 2, 1, 1, 4, 5, 1, 1, 1};
  std::pair<int, int> p7 = {1, 4};
  ASSERT_EQ(p7, solution(6, v7));
}