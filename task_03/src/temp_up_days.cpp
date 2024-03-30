#include "temp_up_days.hpp"

#include <stack>

std::vector<int> TempUpDayCounter(std::vector<int> temps) {
  std::stack<Day> days;
  std::vector<int> result(temps.size(), 0);
  for (int i = 0; i < temps.size(); i++) {
    Day d;
    d.index_ = i;
    d.temp_ = temps[i];
    while (!days.empty()) {
      if (days.top().temp_ < d.temp_) {
        result[days.top().index_] = d.index_ - days.top().index_;
        days.pop();
      } else {
        break;
      }
    }
    days.push(d);
  }
  return result;
}