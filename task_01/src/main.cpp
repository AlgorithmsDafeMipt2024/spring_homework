#include <iostream>
#include <vector>
#include "utils.hpp"

int main() {
  int size;
  std::cin >> size;
  std::vector<int> v(size);
  for (int i = 0; i < v.size(); i++)
    std::cin >> v[i];
  int targetSum;
  std::cin >> targetSum;
  std::pair<int, int> ans = FindTargetSumInArray(v, targetSum);
  if (ans.first != -1)
    std::cout << ans.first << " " << ans.second;
  else
    std::cout << "Not found";

  return 0;
}
