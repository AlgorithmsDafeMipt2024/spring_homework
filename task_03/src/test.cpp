
#include <gtest/gtest.h>

#include <vector>

#include "topology_sort.hpp"

TEST(DaysUntilWarmer, MultipleCases) {
  ASSERT_EQ(DaysUntilWarmer(std::vector<int>{73, 74, 75, 71, 69, 72, 76, 73}),
            (std::vector<int>{1, 1, 4, 2, 1, 1, 0, 0}));
  ASSERT_EQ(DaysUntilWarmer(std::vector<int>{30, 40, 50, 60}),
            (std::vector<int>{1, 1, 1, 0}));
  ASSERT_EQ(DaysUntilWarmer(std::vector<int>{30, 60, 90, 70, 80, 40, 30}),
            (std::vector<int>{1, 1, 0, 1, 0, 0, 0}));
  ASSERT_EQ(DaysUntilWarmer(std::vector<int>{55, 55, 55, 55, 55}),
            (std::vector<int>{0, 0, 0, 0, 0}));
  ASSERT_EQ(DaysUntilWarmer(std::vector<int>{76, 75, 74, 73, 72, 71, 70}),
            (std::vector<int>{0, 0, 0, 0, 0, 0, 0}));
  ASSERT_EQ(DaysUntilWarmer(std::vector<int>{75, 72, 71, 70, 74, 76}),
            (std::vector<int>{5, 3, 2, 1, 1, 0}));
}
