#include "k_stat.hpp"
#include <gtest/gtest.h>
#include <stdexcept>

TEST(k_stat, Simple) {
  std::vector<int> vec_1{14, -1, 5, 21, 6, -3, 7, 93, 9, 0, 84};
  ASSERT_EQ(Find_Order_Statistic(vec_1, 8), 21);
  /*ASSERT_EQ(Find_Order_Statistic(vec, 3), 0);
  ASSERT_EQ(Find_Order_Statistic(vec, 10), 84);
  EXPECT_THROW(Find_Order_Statistic(vec, 13), std::logic_error);*/
}
