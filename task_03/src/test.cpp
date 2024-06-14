
#include <gtest/gtest.h>

#include <stdexcept>
#include <vector>

#include "topology_sort.hpp"

TEST(TopologySort, Simple) {
  ASSERT_EQ(find_higher_temp({0, 2, 6, 4, 8, 4, 6, 0, 3, -3, -2, -6, 1}),
            std::vector<int>({1, 1, 2, 1, 0, 1, 0, 1, 0, 1, 2, 1, 0}));
  ASSERT_EQ(find_higher_temp({0, 1, 2, 3, 4, 5, 4, 3, 2, 1, 0}),
            std::vector<int>({1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0}));
  ASSERT_EQ(find_higher_temp({0, 1, -1, 0, 1, -1, 0, 1}),
            std::vector<int>({1, 0, 1, 1, 0, 1, 1, 0}));
  ASSERT_EQ(find_higher_temp({1}), std::vector<int>({0}));
  ASSERT_EQ(find_higher_temp({-1, -1, -1, -3, -3, -3, -2, -2, -2, 0, 0, 0}),
            std::vector<int>({9, 8, 7, 3, 2, 1, 3, 2, 1, 0, 0, 0}));
  ASSERT_EQ(find_higher_temp({0, 0, 0, 0, 0, 0, 0}),
            std::vector<int>({0, 0, 0, 0, 0, 0, 0}));
  ASSERT_EQ(find_higher_temp({}), std::vector<int>({}));
  ASSERT_EQ(find_higher_temp({1, 5, 2, 3, 4, 0}),
            std::vector<int>({1, 0, 1, 1, 0, 0}));
}
