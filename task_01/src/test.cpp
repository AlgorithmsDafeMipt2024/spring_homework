
#include <gtest/gtest.h>

#include <vector>

#include "topology_sort.hpp"

std::pair<int, int> solution(int number, std::vector<int> v) {
  bool flag = false;  // in case there are no such numbers
  std::unordered_map<int, int> mp;

  for (int i = 0; i < v.size(); i++) {
    if (mp.find(number - v[i]) !=
        mp.end()) {  // if key "number - t" exists, we have found the solution
      return {mp[number - v[i]], i};
      flag = true;
      break;
    }

    if (mp.find(v[i]) == mp.end())
      mp[v[i]] = i;  // We only add keys that weren't in the map before (that
                     // way we get the least possible sum of i and j)
  }

  if (!flag) return {-1, -1};
}

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