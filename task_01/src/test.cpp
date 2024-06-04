
#include <gtest/gtest.h>

#include "topology_sort.hpp"

TEST(find_pair_with_sum, Simple) {
  std::vector<int> test1 = {2, 3, 7, 12, 13, 28, 30, 60};

  ASSERT_EQ(find_pair_with_sum(test1, 14), {0, 4});
  ASSERT_EQ(find_pair_with_sum(test1, 20), {2, 4});
  ASSERT_EQ(find_pair_with_sum(test1, 21), {-1, -1});
  ASSERT_EQ(find_pair_with_sum(test1, 58), {6, 7});
  ASSERT_EQ(find_pair_with_sum(test1, 70), {-1, -1});
  ASSERT_EQ(find_pair_with_sum(test1, -12312), {-1, -1});

  std::vector<int> test2 = {};
  ASSERT_EQ(find_pair_with_sum(test2, 1), {-1, -1});
}