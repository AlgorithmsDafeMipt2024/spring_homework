#include "weather.h"

#include <stack>

std::vector<size_t> weather_algorithm(std::vector<int> days_array) {
  std::vector<size_t> result(days_array.size());
  std::stack<size_t> unchecked_days;
  for (size_t day_index = 0; day_index < days_array.size(); day_index++) {
    result[day_index] = 0;
    while (!unchecked_days.empty() &&
           days_array[day_index] > days_array[unchecked_days.top()]) {
      result[unchecked_days.top()] = day_index - unchecked_days.top();
      unchecked_days.pop();
    }
    unchecked_days.push(day_index);
  }
  return result;
}