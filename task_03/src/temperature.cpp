#include "temperature.hpp"

std::vector<int> Solve(std::vector<int> temperature) {
  int max_temp = -10000000;
  std::vector<int> result(temperature.size(), 0);

  for (int i = temperature.size() - 1; i >= 0; i--) {
    int cur_temperature = temperature[i];

    if (max_temp < cur_temperature) {
      max_temp = cur_temperature;
    } else {
      int days_to_up = 1;

      while (temperature[i + days_to_up] <= cur_temperature) {
        days_to_up += result[i + days_to_up];
      }

      result[i] = days_to_up;
    }
  }
  return result;
}