
#include <gtest/gtest.h>

#include "searching_sum.hpp"

TEST(SearchingSum, Simple) {
  int sum1 = 10;
  std::vector<int> arr1 = {1, 3, 4, 7, 14};
  std::pair<int, int> ans1 = {1, 3};
  ASSERT_EQ(ans1, SearchingSum(sum1, arr1));

  int sum2 = 19;
  std::vector<int> arr2 = {1, 2, 5, 5, 6, 7, 8, 9, 14};
  std::pair<int, int> ans2 = {2, 8};
  ASSERT_EQ(ans2, SearchingSum(sum2, arr2));

  int sum3 = 8;
  std::vector<int> arr3 = {};
  std::pair<int, int> ans3 = {-1, -1};
  ASSERT_EQ(ans3, SearchingSum(sum3, arr3));

  int sum4 = -1;
  std::vector<int> arr4 = {-7, -5, 0, 1, 3, 4, 6};
  std::pair<int, int> ans4 = {0, 6};
  ASSERT_EQ(ans4, SearchingSum(sum4, arr4));

  int sum5 = 0;
  std::vector<int> arr5 = {1, 2, 5, 5, 6, 7, 8, 9, 14};
  std::pair<int, int> ans5 = {-1, -1};
  ASSERT_EQ(ans2, SearchingSum(sum5, arr5));
}
