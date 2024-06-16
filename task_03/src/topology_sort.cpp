#include "topology_sort.hpp"

std::vector<int> DaysUntilWarmer(std::vector<int> temperature) {
  std::vector<int> result(temperature.size(), 0);
  std::stack<int> index;

  for (int i = 0; i < temperature.size(); ++i) {
    while (!index.empty() && temperature[index.top()] < temperature[i]) {
      int current_index = index.top();
      index.pop();
      result[current_index] = i - current_index;
    }
    index.push(i);
  }

  return result;
}