
#include <gtest/gtest.h>

#include "topology_sort.hpp"

TEST(find_pair_with_sum, Simple) {
  std::vector<int> test1 = {2, 3, 7, 12, 13, 28, 30, 60};

  ASSERT_EQ(find_pair_with_sum(test1, 14), std::make_pair(0, 3));
  ASSERT_EQ(find_pair_with_sum(test1, 20), std::make_pair(2, 4));
  ASSERT_EQ(find_pair_with_sum(test1, 21), std::make_pair(-1, -1));
  ASSERT_EQ(find_pair_with_sum(test1, 58), std::make_pair(5, 6));
  ASSERT_EQ(find_pair_with_sum(test1, 70), std::make_pair(-1, -1));
  ASSERT_EQ(find_pair_with_sum(test1, -12312), std::make_pair(-1, -1));

  std::vector<int> test2 = {};
  ASSERT_EQ(find_pair_with_sum(test2, 1), std::make_pair(-1, -1));

}