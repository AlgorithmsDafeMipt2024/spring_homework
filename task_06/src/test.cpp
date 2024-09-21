#include <gtest/gtest.h>

#include <vector>

#include "statistics.hpp"

TEST(OrderStats, Simple1) {
  std::vector<int> v{51, 83, 11, 64, 66, 57, 55};
  ASSERT_EQ(FindStatistics(v, 3), 57);
}
TEST(OrderStats, Simple2) {
  std::vector<int> v{
      41, 99, 43, 22, 33, 60, 61, 8, 1, 97,
  };
  ASSERT_EQ(FindStatistics(v, 5), 43);
}
TEST(OrderStats, Simple3) {
  std::vector<double> v{21.468, 19.642, 46.517, 17.44,
                        464.22, 66.171, 57.68,  19.58};
  ASSERT_EQ(FindStatistics(v, 2), 19.642);
}

TEST(OrderStats, Simple4) {
  std::vector<char> v{'d', 's', 't', 'b'};
  ASSERT_EQ(FindStatistics(v, 1), 'd');
}