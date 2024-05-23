#include "topology_sort.hpp"

std::vector<int> Task3(std::vector<int> temperature) {
  std::vector<int> result;
  for (int i = 0; i < temperature.size(); ++i) {
    int count_day = 0;
    bool flag = true;
    for (int j = i; j < temperature.size(); ++j) {
      if (temperature[j] <= temperature[i])
        count_day++;
      else {
        flag = false;
        break;
      }
    }
    if (flag) count_day = 0;
    result.push_back(count_day);
  }
  return result;
}