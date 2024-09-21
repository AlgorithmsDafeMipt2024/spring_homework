#include <gtest/gtest.h>

#include "money.hpp"

TEST(ChangeMoney, Simple) {
  ASSERT_EQ(CoinExchange(14, std::vector<std::size_t>{4, 5, 1, 10}), 2);
  ASSERT_EQ(CoinExchange(21, std::vector<std::size_t>{11, 3, 9}), 3);
  ASSERT_EQ(CoinExchange(25, std::vector<std::size_t>{1, 2, 4, 5}), 5);
  ASSERT_EQ(CoinExchange(137, std::vector<std::size_t>{4, 3, 7, 19}), 8);

  ASSERT_EQ(CoinExchange(104, std::vector<std::size_t>{3, 2, 5, 8, 11}), 10);
}