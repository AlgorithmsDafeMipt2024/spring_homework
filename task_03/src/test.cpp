
#include <gtest/gtest.h>

#include "temp_up_days.hpp"

TEST(TempUpDays, Simple) {
  ASSERT_EQ(TempUpDayCounter(std::vector<int>{5, 7, 4, 5}),
            (std::vector<int>{1, 0, 1, 0}));
  ASSERT_EQ(TempUpDayCounter(std::vector<int>{5, 12, 4, 9, 5, 4, 2}),
            (std::vector<int>{1, 0, 1, 0, 0, 0, 0}));
  ASSERT_EQ(TempUpDayCounter(std::vector<int>{2, 6, 17, 7, 3, 4}),
            (std::vector<int>{1, 1, 0, 0, 1, 0}));
  ASSERT_EQ(TempUpDayCounter(std::vector<int>{}), std::vector<int>{});
}
