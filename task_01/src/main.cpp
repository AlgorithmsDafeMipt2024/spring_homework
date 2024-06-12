#include <iostream>
#include <utility>
#include <vector>

#include "searching_sum.hpp"

int main() {
  int n, k;
  std::cin >> n >> k;
  std::vector<int> vec(n);
  for (int i = 0; i < n; i++) {
    std::cin >> vec[i];
  }
  std::pair<int, int> ans = SearchingSum(vec, k);
  std::cout << ans.first << " " << ans.second << std::endl;
  return 0;
}
