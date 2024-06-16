#include "days_amount_before_warming.h"

#include <stack>

std::vector<std::size_t> DaysAmountBeforeWarming(
    std::vector<int> temperatures) {
  std::vector<std::size_t> result(temperatures.size());
  std::stack<std::size_t> remaining_days;
  for (std::size_t i = 0; i < temperatures.size(); ++i) {
    result[i] = 0;
    while (!remaining_days.empty() &&
           temperatures[i] > temperatures[remaining_days.top()]) {
      result[remaining_days.top()] = i - remaining_days.top();
      remaining_days.pop();
    }
    remaining_days.push(i);
  }
  return result;
}