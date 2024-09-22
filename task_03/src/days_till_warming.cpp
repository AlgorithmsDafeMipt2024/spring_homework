#include "days_till_warming.hpp"

std::vector<size_t> DaysTillWarming(std::vector<double> temps) {
  std::vector<Day> days;
  std::vector<size_t> result(temps.size(), 0);
  for (size_t i = 0; i < temps.size(); i++) {
    while (!days.empty() && (days.back().temp_ < temps[i])) {
      result[days.back().id_] = i - days.back().id_;
      days.pop_back();
    }
    days.push_back(Day(i, temps[i]));
  }
  return result;
}