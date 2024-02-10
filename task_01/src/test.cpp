
#include <gtest/gtest.h>

#include <vector>

#include "utils.hpp"
std::vector<int> test_arr_1 = {1, 2, 3, 4, 5, 7, 8, 12};
std::vector<int> test_arr_2 = {1, 1, 1, 1};
std::vector<int> test_arr_3 = {};
TEST(TopologySort, Simple) {
  ASSERT_EQ(FindSummands(test_arr_1, 7), (std::pair<int, int>{2, 5}));
  ASSERT_EQ(FindSummands(test_arr_1, 13), (std::pair<int, int>{1, 12}));
  ASSERT_EQ(FindSummands(test_arr_1, 21), (std::pair<int, int>{NULL, NULL}));
  ASSERT_EQ(FindSummands(test_arr_1, -1), (std::pair<int, int>{NULL, NULL}));
  ASSERT_EQ(FindSummands(test_arr_2, 3), (std::pair<int, int>{NULL, NULL}));
  ASSERT_EQ(FindSummands(test_arr_2, 2), (std::pair<int, int>{1, 1}));
  ASSERT_EQ(FindSummands(test_arr_3, 0), (std::pair<int, int>{NULL, NULL}));
}
