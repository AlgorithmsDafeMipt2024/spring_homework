
#include <gtest/gtest.h>

#include "temperature.hpp"

TEST(DaysBeforeWarming, Test_1) {
  ASSERT_EQ(DaysBeforeWarming(vector<short>{}), vector<size_t>{});
}

TEST(DaysBeforeWarming, Test_2) {
  ASSERT_EQ(DaysBeforeWarming(vector<short>{1}), vector<size_t>{0});
}

TEST(DaysBeforeWarming, Test_3) {
  ASSERT_EQ(DaysBeforeWarming(vector<short>{1, 2}), (vector<size_t>{1, 0}));
}

TEST(DaysBeforeWarming, Test_4) {
  ASSERT_EQ(DaysBeforeWarming(vector<short>{1, 2, 3, 4, 5, 6}),
            (vector<size_t>{1, 1, 1, 1, 1, 0}));
}

TEST(DaysBeforeWarming, Test_5) {
  ASSERT_EQ(DaysBeforeWarming(vector<short>{6, 5, 4, 3, 2, 1}),
            (vector<size_t>{0, 0, 0, 0, 0, 0}));
}

TEST(DaysBeforeWarming, Test_6) {
  ASSERT_EQ(DaysBeforeWarming(vector<short>{-6, -5, -4, -3, -2, -1}),
            (vector<size_t>{1, 1, 1, 1, 1, 0}));
}

TEST(DaysBeforeWarming, Test_7) {
  ASSERT_EQ(DaysBeforeWarming(vector<short>{-1, 0, 2, -1, -5, 3, 6, 1}),
            (vector<size_t>{1, 1, 3, 1, 1, 1, 0, 0}));
}

TEST(DaysBeforeWarming, Test_8) {
  ASSERT_EQ(DaysBeforeWarming(vector<short>{
                -10, 5,  -3, 8,   -20, 12, 17, -15, 6,  -7,  25, -30, 19,
                4,   -2, 11, -18, 14,  -5, 9,  -13, 22, -35, 16, -40}),
            (vector<size_t>{1,  2, 4, 2,  7, 1,  4, 16, 2, 5, 0, 1, 9,
                            18, 3, 2, 10, 4, 13, 2, 8,  0, 1, 0, 0}));
}