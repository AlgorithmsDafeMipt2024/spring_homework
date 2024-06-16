
#include <gtest/gtest.h>

#include <cstddef>

#include "coin_exchange.hpp"

TEST(CoinExchange, Test1) {
  long long sum = 11;
  std::vector<size_t> nominals = {1, 2, 5, 10};
  ASSERT_EQ(2, CoinExchange(sum, nominals));
}

TEST(CoinExchange, Test2) {
  long long sum = 28;
  std::vector<size_t> nominals = {1, 2, 5, 10};
  ASSERT_EQ(5, CoinExchange(sum, nominals));
}

TEST(CoinExchange, Test3) {
  long long sum = 1;
  std::vector<size_t> nominals = {10};
  ASSERT_EQ(-1, CoinExchange(sum, nominals));
}

TEST(CoinExchange, Test4) {
  long long sum = 14;
  std::vector<size_t> nominals = {1, 2, 5, 7, 10};
  ASSERT_EQ(2, CoinExchange(sum, nominals));
}

TEST(CoinExchange, Test5) {
  long long sum = 10;
  std::vector<size_t> nominals = {1, 2, 5, 7};
  ASSERT_EQ(2, CoinExchange(sum, nominals));
}

TEST(CoinExchange, WrongTest1) {
  long long sum = -1;
  std::vector<size_t> nominals = {1, 2, 3, 4, 5};
  ASSERT_EQ(-1, CoinExchange(sum, nominals));
}

TEST(CoinExchange, WrongTest2) {
  long long sum = 8;
  std::vector<size_t> nominals = {};
  ASSERT_EQ(-1, CoinExchange(sum, nominals));
}