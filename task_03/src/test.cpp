
#include <gtest/gtest.h>

#include <stdexcept>

#include "warming_prediction.hpp"
TEST(warming_prediction, Simple) {
  ASSERT_EQ(DoWarmingPrediction(std::vector<int>{23, 29, 12, 16, 45, 10, -8,
                                                 -39, 35, 6, 4, -11}),
            (std::vector<unsigned int>{1, 3, 1, 1, 0, 3, 2, 1, 0, 0, 0, 0}));

  ASSERT_EQ(DoWarmingPrediction(std::vector<int>{-32, -5, 34, -37, -48, -17, 33,
                                                 27, 18, -36, 22, 32}),
            (std::vector<unsigned int>{1, 1, 0, 2, 1, 1, 0, 4, 2, 1, 1, 0}));

  ASSERT_EQ(DoWarmingPrediction(std::vector<int>{34, -49, 7, -44, 25, -45, -29,
                                                 -14, 2, -30, 34, -36}),
            (std::vector<unsigned int>{0, 1, 2, 1, 6, 1, 1, 1, 2, 1, 0, 0}));

  ASSERT_EQ(DoWarmingPrediction(std::vector<int>{}),
            (std::vector<unsigned int>{}));

  ASSERT_EQ(
      DoWarmingPrediction(std::vector<int>{32, 11, 11, 10, 9, 7, 5, 3, 1}),
      (std::vector<unsigned int>{0, 0, 0, 0, 0, 0, 0, 0, 0}));

  ASSERT_EQ(DoWarmingPrediction(
                std::vector<float>{4, 12, 8, 7, 9, 1, 11, 9, 9, 10, 11, 12}),
            (std::vector<unsigned int>{1, 0, 2, 1, 2, 1, 5, 2, 1, 1, 1, 0}));

  EXPECT_THROW(DoWarmingPrediction(std::vector<std::string>{"1"}),
               std::logic_error);
}
