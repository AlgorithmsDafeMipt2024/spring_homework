
#include <gtest/gtest.h>

#include "task_06.hpp"

TEST(FindNthOrder, Case1) {
  ASSERT_EQ(FindNthOrder(std::vector<int>{73, 74, 75, 71, 69, 72, 76, 73}, 2),
            71);
}

TEST(findNthOrder, Case2) {
  ASSERT_EQ(FindNthOrder(std::vector<int>{30, 40, 50, 60}, 1), 30);
}

TEST(findNthOrder, Case3) {
  ASSERT_EQ(FindNthOrder(std::vector<int>{30, 60, 90, 70, 80, 40, 30}, 4), 60);
}

TEST(findNthOrder, Case4) {
  ASSERT_EQ(FindNthOrder(std::vector<int>{55, 55, 55, 55, 55}, 5), 55);
}

TEST(findNthOrder, Case5) {
  EXPECT_THROW(FindNthOrder(std::vector<int>{}, 5), std::invalid_argument);
}
