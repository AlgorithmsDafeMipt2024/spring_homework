
#include <gtest/gtest.h>

#include "days_till_warming.hpp"

TEST(DaysTillWarming, Simple) {
  ASSERT_EQ((DaysTillWarming(std::vector<double>{
                +24, +22, +27, +21, +20, +20, +20, +20, +23, +24, +24, +25, +19,
                +19, +22, +28, +21, +21, +22})),
            (std::vector<size_t>{2, 1, 13, 5, 4, 3, 2, 1, 1, 2, 1, 4, 2, 1, 1,
                                 0, 2, 1, 0}));
  ASSERT_EQ((DaysTillWarming(std::vector<double>{-12, -5, -9, 0, +2, +1})),
            (std::vector<size_t>{1, 2, 1, 1, 0, 0}));
}
