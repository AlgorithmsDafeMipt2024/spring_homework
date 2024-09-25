
#include <gtest/gtest.h>

#include <stdexcept>

#include "n_statistic.hpp"

TEST(N_th_Statistic, Simple) {
  std::vector<int> temp;

  std::vector<int> list1 = {1, 2, 6, 5, 3, 4};
  std::vector<int> list2 = {0, 5, 0, -1, -2, -3, 10, 7};
  std::vector<int> list3 = {};
  std::vector<int> list4 = {0};

  // HEAPSORT
  // -----------------------------------------------------------------
  ASSERT_EQ(findNstat(list1, 3), 4);
  ASSERT_EQ(list1, std::vector<int>({1, 2, 6, 5, 3, 4}));

  ASSERT_EQ(findNstat(list1, 1), 2);
  ASSERT_EQ(findNstat(list1, list1.size() - 1), 6);
  ASSERT_EQ(list1, std::vector<int>({1, 2, 6, 5, 3, 4}));

  ASSERT_EQ(findNstat(list2, 2), -1);
  ASSERT_EQ(list2, std::vector<int>({0, 5, 0, -1, -2, -3, 10, 7}));
  ASSERT_EQ(findNstat(list2, 7), 10);
  ASSERT_THROW(findNstat(list2, 10), std::out_of_range);
  ASSERT_EQ(findNstat(list2, 4), 0);

  ASSERT_THROW(findNstat(list3, 4), std::length_error);
  ASSERT_THROW(findNstat(list3, 0), std::length_error);

  ASSERT_EQ(findNstat(list4, 0), 0);
  ASSERT_THROW(findNstat(list4, 1), std::out_of_range);
}
