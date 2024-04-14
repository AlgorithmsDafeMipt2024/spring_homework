
#include <gtest/gtest.h>

#include "topology_sort.hpp"

TEST(DaysBeforeWarming, Simple) {
  std::vector<int> temperatures = {1, 2, 3, 4, 5};
  std::vector<int> correct_answer = {1, 1, 1, 1, 0};
  ASSERT_EQ(DaysBeforeWarming(temperatures), correct_answer);

  temperatures = {1};
  correct_answer = {0};
  ASSERT_EQ(DaysBeforeWarming(temperatures), correct_answer);

  temperatures = {0, 0, 0, 0, 0, 5};
  correct_answer = {5, 4, 3, 2, 1, 0};
  ASSERT_EQ(DaysBeforeWarming(temperatures), correct_answer);

  temperatures = {0, 0, 0, 0, 0, 0};
  correct_answer = {0, 0, 0, 0, 0, 0};
  ASSERT_EQ(DaysBeforeWarming(temperatures), correct_answer);

  temperatures = {3, 12, 4, 4, 6, 2, 1, 9, 2};
  correct_answer = {1, 0, 2, 1, 3, 2, 1, 0, 0};
  ASSERT_EQ(DaysBeforeWarming(temperatures), correct_answer);
}
