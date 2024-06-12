#include "temperature.hpp"

#include <stack>
#include <vector>

std::vector<int> days_before_warming(std::vector<int> daily_temp) {
  std::vector<int> days_amount(daily_temp.size());
  std::stack<int> previous_days;
  for (int day_index = 0; day_index < daily_temp.size(); ++day_index) {
    days_amount[day_index] = 0;
    while (!previous_days.empty() &&
           daily_temp[previous_days.top()] <= daily_temp[day_index]) {
      days_amount[previous_days.top()] = day_index - previous_days.top();
      previous_days.pop();
    }
    previous_days.push(day_index);
  }
  return days_amount;
}