#include <gtest/gtest.h>

#include "days_amount_before_warming.h"

TEST(Temperature, Simple) {
  std::vector<size_t> days_data_1 = DaysAmountBeforeWarming({1, 2, 3, 4, 5});
  std::vector<size_t> answer_1 = {1, 1, 1, 1, 0};

  ASSERT_EQ(days_data_1, answer_1);

  std::vector<size_t> days_data_2 = DaysAmountBeforeWarming({5});
  std::vector<size_t> answer_2 = {0};

  ASSERT_EQ(days_data_2, answer_2);

  std::vector<size_t> days_data_3 = DaysAmountBeforeWarming({});
  std::vector<size_t> answer_3 = {};

  ASSERT_EQ(days_data_3, answer_3);

  std::vector<size_t> days_data_4 =
      DaysAmountBeforeWarming({-1, -1, 2, 2, -5, 3, 4, 1});
  std::vector<size_t> answer_4 = {2, 1, 3, 2, 1, 1, 0, 0};

  ASSERT_EQ(days_data_4, answer_4);

  std::vector<size_t> days_data_5 = DaysAmountBeforeWarming({6, 5, 4, 3, 2, 1});
  std::vector<size_t> answer_5 = {0, 0, 0, 0, 0, 0};

  ASSERT_EQ(days_data_3, answer_5);
}
