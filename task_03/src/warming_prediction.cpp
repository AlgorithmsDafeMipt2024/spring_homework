#include "warming_prediction.hpp"

std::vector<int> DoWarmingPrediction(std::vector<int>& temperature_data) {
  std::stack<int> unpredictable_days;
  std::vector<int> days_of_waiting(temperature_data.size());
  for (int day = 0; day != temperature_data.size(); day++) {
    while (!unpredictable_days.empty() &&
           temperature_data[day] > temperature_data[unpredictable_days.top()]) {
      int last_day = unpredictable_days.top();
      days_of_waiting[last_day] = day - last_day;
      unpredictable_days.pop();
    }
    unpredictable_days.push(day);
  }
  return days_of_waiting;
}