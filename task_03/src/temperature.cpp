#include "temperature.hpp"

#include <stack>

std::vector<unsigned int> TemperatureSolution(std::vector<int> temperature) {
  std::vector<unsigned int> result(temperature.size());
  std::stack<unsigned int> check_days;
  for (unsigned int day_index = 0; day_index < temperature.size();
       day_index++) {
    result[day_index] = 0;
    while (!check_days.empty() &&
           temperature[day_index] > temperature[check_days.top()]) {
      result[check_days.top()] = day_index - check_days.top();
      check_days.pop();
    }
    check_days.push(day_index);
  }
  return result;
}