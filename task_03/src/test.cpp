
#include <gtest/gtest.h>

#include "temperature.hpp"

TEST(TemperatureCnt, Simple) {
  ASSERT_EQ(TemperatureCounter(std::vector<double>{5.8, 7.2, 4.1, 5.999}),
            (std::vector<int>{1, 0, 1, 0}));
  ASSERT_EQ(
      TemperatureCounter(std::vector<double>{5.99, 12, 4, 9.1, 5.15, 4, 2}),
      (std::vector<int>{1, 0, 1, 0, 0, 0, 0}));
  ASSERT_EQ(
      TemperatureCounter(std::vector<double>{2, 6, 17.512512, 7, 3, 4.412151}),
      (std::vector<int>{1, 1, 0, 0, 1, 0}));
  ASSERT_EQ(TemperatureCounter(std::vector<double>{}), std::vector<int>{});
}