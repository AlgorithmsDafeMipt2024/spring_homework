#include "temperature.hpp"

std::vector<int> TemperatureCounter(std::vector<double> temps) {
  std::stack<Day> days;
  std::vector<int> result(temps.size(), 0);
  for (int i = 0; i < temps.size(); i++) {
    while (!days.empty() && days.top().value < temps[i]) {
      result[days.top().index] = i - days.top().index;
      days.pop();
    }
    days.push(Day(i, temps[i]));
  }
  return result;
}