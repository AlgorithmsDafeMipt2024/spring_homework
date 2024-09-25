
#include <gtest/gtest.h>

#include <vector>

#include "change_cash.hpp"

TEST(ChangeCahs, Simple) {
  std::vector<unsigned int> nominals_1 = {1, 2, 5, 10, 100};
  std::vector<unsigned int> nominals_2 = {2, 16, 64, 1024};
  std::vector<unsigned int> nominals_3 = {};

  ASSERT_EQ(min_change_count(nominals_1, 1), 1);
  ASSERT_EQ(min_change_count(nominals_2, 1), -1);
  ASSERT_EQ(min_change_count(nominals_3, 1), -1);

  ASSERT_EQ(min_change_count(nominals_1, 86), 10);
  ASSERT_EQ(min_change_count(nominals_2, 86), 5);
  ASSERT_EQ(min_change_count(nominals_3, 86), -1);

  ASSERT_EQ(min_change_count(nominals_1, 13), 3);
  ASSERT_EQ(min_change_count(nominals_2, 13), -1);
  ASSERT_EQ(min_change_count(nominals_3, 13), -1);

  ASSERT_EQ(min_change_count(nominals_1, 0), 0);
  ASSERT_EQ(min_change_count(nominals_2, 0), 0);
  ASSERT_EQ(min_change_count(nominals_3, 0), 0);
}
