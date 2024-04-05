#include <gtest/gtest.h>

#include <cstddef>

#include "weather.h"

TEST(weather, Simple) {
  std::vector<size_t> data_vector_1 = weather_algorithm({1, 2, 3, 4, 5});
  std::vector<size_t> assert_vector_1 = {1, 1, 1, 1, 0};

  ASSERT_EQ(data_vector_1, assert_vector_1);

  std::vector<size_t> data_vector_2 = weather_algorithm({5});
  std::vector<size_t> assert_vector_2 = {0};

  ASSERT_EQ(data_vector_2, assert_vector_2);

  std::vector<size_t> data_vector_3 = weather_algorithm({});
  std::vector<size_t> assert_vector_3 = {};

  ASSERT_EQ(data_vector_3, assert_vector_3);

  std::vector<size_t> data_vector_4 =
      weather_algorithm({-1, -1, 2, 2, -5, 3, 4, 1});
  std::vector<size_t> assert_vector_4 = {2, 1, 3, 2, 1, 1, 0, 0};

  ASSERT_EQ(data_vector_4, assert_vector_4);

  std::vector<size_t> data_vector_5 = weather_algorithm({6, 5, 4, 3, 2, 1});
  std::vector<size_t> assert_vector_5 = {0, 0, 0, 0, 0, 0};

  ASSERT_EQ(data_vector_5, assert_vector_5);
}
