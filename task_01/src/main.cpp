#include <iostream>

#include "solution.h"

int main() {
  int sum, arr_size, t;
  std::vector<int> input_vector;
  std::unordered_map<int, int> indices_map;  // keeps array numbers as keys and
                                             // indices as values behind keys

  std::cin >> sum >> arr_size;

  for (int i = 0; i < arr_size; i++) {
    std::cin >> t;
    input_vector.push_back(t);
  }

  std::pair<int, int> sol = solution(sum, input_vector);
  std::cout << sol.first << ' ' << sol.second;

  return 0;
}