#include "warming_prediction.hpp"

std::vector<unsigned int> DoWarmingPrediction(
    const std::vector<int>& temperature_data) {
  std::stack<unsigned int> unpredictable_days;
  std::vector<unsigned int> days_of_waiting(temperature_data.size());
  for (unsigned int current_day = 0; current_day != temperature_data.size();
       current_day++) {
    while (!unpredictable_days.empty() &&
           temperature_data[current_day] >
               temperature_data[unpredictable_days.top()]) {
      unsigned int last_unpredictable_day = unpredictable_days.top();
      days_of_waiting[last_unpredictable_day] =
          current_day - last_unpredictable_day;
      unpredictable_days.pop();
    }
    unpredictable_days.push(current_day);
  }
  return days_of_waiting;
}