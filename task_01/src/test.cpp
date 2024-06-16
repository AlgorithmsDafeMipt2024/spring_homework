#include <gtest/gtest.h>

#include <utility>
#include <vector>

#include "searching_sum.hpp"

TEST(TopologySort, Simple) {
  int sum1 = 6;
  std::vector<int> vec1{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  std::pair<int, int> ans1{0, 6};
  ASSERT_EQ(SearchingSum(vec1, sum1), ans1);

  int sum2 = 6;
  std::vector<int> vec2{0};
  std::pair<int, int> ans2{-1, -1};
  ASSERT_EQ(SearchingSum(vec2, sum2), ans2);

  int sum3 = 4;
  std::vector<int> vec3{-11, -6, 0, 1, 2, 4, 10, 16};
  std::pair<int, int> ans3{1, 6};
  ASSERT_EQ(SearchingSum(vec3, sum3), ans3);

  int sum4 = 0;
  std::vector<int> vec4{-17, -8, -1, 1, 2, 4, 10};
  std::pair<int, int> ans4{2, 3};
  ASSERT_EQ(SearchingSum(vec4, sum4), ans4);

  int sum5 = -9;
  std::vector<int> vec5{-17, -8, -1, 1, 2, 4, 10};
  std::pair<int, int> ans5{1, 2};
  ASSERT_EQ(SearchingSum(vec5, sum5), ans5);

  int sum6 = 17;
  std::vector<int> vec6{-17, -8, -1, 1, 2, 4, 10};
  std::pair<int, int> ans6{-1, -1};
  ASSERT_EQ(SearchingSum(vec6, sum6), ans6);

  int sum7 = -1;
  std::vector<int> vec7{-18, -10, -1, -1, -1, 0, 3, 5, 10};
  std::pair<int, int> ans7{2, 5};
  ASSERT_EQ(SearchingSum(vec7, sum7), ans7);

  int sum8 = 5;
  std::vector<int> vec8(0);
  std::pair<int, int> ans8{-1, -1};
  ASSERT_EQ(SearchingSum(vec8, sum8), ans8);
}
