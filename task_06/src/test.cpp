#include "k_stat.hpp"
#include <gtest/gtest.h>
#include <stdexcept>

TEST(k_stat, Simple) {
  std::vector<int> vec{14, -1, 5, 21, 6, -3, 7, 93, 9, 0, 84};
  ASSERT_EQ(Quick_Sort(vec, 0, 10, 8), 14);
  ASSERT_EQ(Quick_Sort(vec, 0, 10, 3), 0);
  ASSERT_EQ(Quick_Sort(vec, 0, 10, 10), 84);
  EXPECT_THROW(Quick_Sort(vec, 0, 10, 13), std::logic_error);
}
