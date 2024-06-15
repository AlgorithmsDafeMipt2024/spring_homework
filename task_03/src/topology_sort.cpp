#include "topology_sort.hpp"

std::vector<int> TopologySort(std::vector<int> temperature) {
  std::vector<int> result(0, temperature.size());
  std::stack<int> index;

  for (int i = 0; i < temperature.size(); ++i) {
    while (!index.empty() && temperature[index.top()] < temperature[i]) {
      int current_index = index.top();
      index.pop();
      result[current_index] = i - current_index;
    }
    index.push(i);
  }
  for (int i = 0; i < index.size(); ++i) {
    result.push_back(0);
  }

  return result;
}