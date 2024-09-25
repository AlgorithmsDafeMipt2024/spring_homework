#include "topology_sort.hpp"

#include <stack>
#include <stdexcept>
#include <vector>

std::vector<int> find_higher_temp(std::vector<int> temp_list) {
  if (temp_list.size() == 0) {
    return {};
  }

  std::vector<int> ans_vect = std::vector<int>(temp_list.size(), 0);
  std::stack<int> day_stack;

  for (int i_day = temp_list.size() - 1; i_day >= 0; i_day--) {
    while (!day_stack.empty()) {
      if (temp_list[day_stack.top()] <= temp_list[i_day]) {
        day_stack.pop();
      } else {
        break;
      }
    }
    if (!day_stack.empty()) {
      ans_vect[i_day] = day_stack.top() - i_day;
    }
    day_stack.push(i_day);
  }
  return ans_vect;
}