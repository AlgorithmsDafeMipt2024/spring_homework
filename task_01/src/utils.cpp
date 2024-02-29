#include "utils.hpp"

std::pair<int, int> FindTargetSumInArray(std::vector<int> v, int targetSum) {
  int i = 0, j = v.size() - 1;
  while (v[i] < v[j]) {
    if (v[i] + v[j] > targetSum)
      j--;
    else if (v[i] + v[j] < targetSum)
      i++;
    else
      return std::pair<int, int>(i, j);
  }
  return std::pair<int, int>(-1, -1);
}