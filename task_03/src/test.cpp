
#include <gtest/gtest.h>

#include "warming_prediction.hpp"
TEST(warming_prediction, Simple) {
  std::vector<int> temperatures_data_1 = {23, 29,  12, 16, 45, 10,
                                          -8, -39, 35, 6,  4,  -11};
  std::vector<int> prediction_1 = {1, 3, 1, 1, 0, 3, 2, 1, 0, 0, 0, 0};
  ASSERT_EQ(DoWarmingPrediction(temperatures_data_1),
            prediction_1);  // Stack []

  std::vector<int> temperatures_data_2 = {-32, -5, 34, -37, -48, -17,
                                          33,  27, 18, -36, 22,  32};
  std::vector<int> prediction_2 = {1, 1, 0, 2, 1, 1, 0, 4, 2, 1, 1, 0};
  ASSERT_EQ(DoWarmingPrediction(temperatures_data_2), prediction_2);

  std::vector<int> temperatures_data_3 = {34,  -49, 7, -44, 25, -45,
                                          -29, -14, 2, -30, 34, -36};
  std::vector<int> prediction_3 = {0, 1, 2, 1, 6, 1, 1, 1, 2, 1, 0, 0};
  ASSERT_EQ(DoWarmingPrediction(temperatures_data_3), prediction_3);

  std::vector<int> temperatures_data_4 = {};
  std::vector<int> prediction_4 = {};
  ASSERT_EQ(DoWarmingPrediction(temperatures_data_4), prediction_4);

  std::vector<int> temperatures_data_5 = {32, 11, 11, 10, 9, 7, 5, 3, 1};
  std::vector<int> prediction_5 = {0, 0, 0, 0, 0, 0, 0, 0, 0};
  ASSERT_EQ(DoWarmingPrediction(temperatures_data_5), prediction_5);

  std::vector<int> temperatures_data_6 = {4,  12, 8, 7,  9,  1,
                                          11, 9,  9, 10, 11, 12};
  std::vector<int> prediction_6 = {1, 0, 2, 1, 2, 1, 5, 2, 1, 1, 1, 0};
  ASSERT_EQ(DoWarmingPrediction(temperatures_data_6), prediction_6);
}
