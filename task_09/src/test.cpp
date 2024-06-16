#include <gtest/gtest.h>

#include <vector>

#include "change_money.hpp"

TEST(ChangeMoney, Simple) {
  ASSERT_EQ(CoinExchange(14, std::vector<int>{1, 2, 5, 10}), 3);
  ASSERT_EQ(CoinExchange(21, std::vector<int>{1, 3, 6}), 4);
  ASSERT_EQ(CoinExchange(25, std::vector<int>{1, 2, 3, 5}), 5);
  ASSERT_EQ(CoinExchange(137, std::vector<int>{1, 3, 7, 19}), 9);

  ASSERT_EQ(CoinExchange(14, std::vector<int>{1, 2, 5, 7, 10}), 2);
}
