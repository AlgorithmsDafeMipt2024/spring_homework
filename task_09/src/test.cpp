#include "minimum_moneys.hpp"
#include <gtest/gtest.h>
#include <stdexcept>

TEST(MinMoney, Simple) {
  ASSERT_EQ(MinMoney(std::vector<int>{1, 2, 5, 10}, 14), (3));
  ASSERT_EQ(MinMoney(std::vector<int>{1, 2, 5, 10}, 19), (4));
  ASSERT_EQ(MinMoney(std::vector<int>{1, 3, 4}, 6), (2));
  ASSERT_EQ(MinMoney(std::vector<int>{1, 2, 3, 4, 5, 6, 7, 8, 9}, 152), (17));
  ASSERT_EQ(MinMoney(std::vector<int>{1, 3, 4}, 34), (9));
  ASSERT_EQ(MinMoney(std::vector<int>{4, 5, 6, 7, 8, 9}, 3), (0));
  ASSERT_EQ(MinMoney(std::vector<int>{14, 25}, 12), (0));
  ASSERT_EQ(MinMoney(std::vector<int>{1, 2, 6, 7}, 12), (2));
}
