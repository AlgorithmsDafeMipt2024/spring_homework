#include "topology_sort.hpp"

std::pair<int, int> find_pair_with_sum(std::vector<int> mass, int a) {
  if (!std::is_sorted(mass.begin(), mass.end()) or mass.size() == 0) {
    return std::pair<int, int>(-1, -1);
  }
  int L = 0;
  int R = mass.size() - 1;

  while (L != R) {
    if (mass[L] + mass[R] == a) {
      return std::pair<int, int>(L, R);
    }
    if (mass[L] + mass[R] < a) {
      L += 1;
    } else {
      R -= 1;
    }
  }

  return std::pair<int, int>(-1, -1);
}
