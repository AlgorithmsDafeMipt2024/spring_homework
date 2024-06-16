#include <gtest/gtest.h>

#include <vector>

#include "order_stats.hpp"

TEST(OrderStats, Simple1) {
  std::vector<int> v{50, 82, 11, 64, 66, 57, 35};
  ASSERT_EQ(FindKStatistics(v, 0, v.size(), 3), 57);
}
TEST(OrderStats, Simple2) {
  std::vector<int> v{
      40, 99, 63, 22, 37, 60, 61, 8, 84, 97,
  };
  ASSERT_EQ(FindKStatistics(v, 0, v.size(), 5), 61);
}
TEST(OrderStats, Simple3) {
  std::vector<int> v{69, 91, 69, 64, 18, 76, 28, 9, 59, 40, 22, 48};
  ASSERT_EQ(FindKStatistics(v, 0, v.size(), 0), 9);
}
TEST(OrderStats, Simple4) {
  std::vector<double> v{84.68, 39.62, 36.57, 17.44, 34.22, 66.11, 57.68, 1.58};
  ASSERT_EQ(FindKStatistics(v, 0, v.size(), 2), 34.22);
}

TEST(OrderStats, Simple5) {
  std::vector<char> v{'d', 's', 'a', 'b'};
  ASSERT_EQ(FindKStatistics(v, 0, v.size(), 1), 'b');
}
