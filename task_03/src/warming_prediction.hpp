#pragma once
#include <stack>
#include <stdexcept>
#include <vector>

template <typename T>
std::vector<unsigned int> DoWarmingPrediction(
    const std::vector<T>& temperature_data) {
  if (!std::is_arithmetic<T>::value)
    throw std::logic_error("Invalid data type");
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