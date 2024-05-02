
#include <gtest/gtest.h>

#include <cstddef>

#include "solution.hpp"

TEST(MoneyTest, Simple_1) {
  long long numbah1 = 14;
  std::vector<size_t> nominals1 = {1, 2, 5, 10};
  ASSERT_EQ(3, coin_change(numbah1, nominals1));
}

TEST(MoneyTest, Simple_2) {
  long long numbah2 = 19;
  std::vector<size_t> nominals2 = {1, 2, 5, 10};
  ASSERT_EQ(4, coin_change(numbah2, nominals2));
}

TEST(MoneyTest, Simple_3) {
  long long numbah3 = 31;
  std::vector<size_t> nominals3 = {10};
  ASSERT_EQ(-1, coin_change(numbah3, nominals3));
}

TEST(MoneyTest, Wrong_numbah) {
  long long numbah4 = -1;
  std::vector<size_t> nominals4 = {1, 2, 3};
  ASSERT_EQ(-1, coin_change(numbah4, nominals4));
}

TEST(MoneyTest, Empty_array) {
  long long numbah5 = 40;
  std::vector<size_t> nominals5 = {};
  ASSERT_EQ(-1, coin_change(numbah5, nominals5));
}