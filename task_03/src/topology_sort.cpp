#include "topology_sort.hpp"

#include <iostream>
#include <stack>
#include <vector>

class Day {
 public:
  int number_of_day;
  int temperature;
  Day(int number_of_day, int temperature)
      : number_of_day(number_of_day), temperature(temperature) {}
};

std::vector<int> RiseTemperature(std::vector<int> vec) {
  int size = int(vec.size());
  if (size == 0) {
    throw WrongVector("Wrong vector is too small");
  }
  std::stack<Day> stack_days;
  std::vector<int> answer_vec(size, 0);
  stack_days.emplace(0, vec[0]);
  int i = 1;
  while (i < size) {
    while (!stack_days.empty()) {
      if (vec[i] > stack_days.top().temperature) {
        answer_vec[stack_days.top().number_of_day] =
            i - stack_days.top().number_of_day;
        stack_days.pop();
      } else if (vec[i] < stack_days.top().temperature) {
        break;
      }
    }
    stack_days.emplace(i, vec[i]);
    ++i;
  }
  return answer_vec;
}
