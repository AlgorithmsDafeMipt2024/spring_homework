
#include <gtest/gtest.h>

#include "task_06.hpp"

TEST(MergeSortTests, Case1) {
  ASSERT_EQ(findNthOrder(std::vector<int>{73, 74, 75, 71, 69, 72, 76, 73}, 2),
            71);
}

TEST(MergeSortTests, Case2) {
  ASSERT_EQ(findNthOrder(std::vector<int>{30, 40, 50, 60}, 1), 30);
}

TEST(MergeSortTests, Case3) {
  ASSERT_EQ(findNthOrder(std::vector<int>{30, 60, 90, 70, 80, 40, 30}, 4), 60);
}

TEST(MergeSortTests, Case4) {
  ASSERT_EQ(findNthOrder(std::vector<int>{55, 55, 55, 55, 55}, 5), 55);
}
