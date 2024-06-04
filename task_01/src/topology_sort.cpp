#include "topology_sort.hpp"

std::vector<int> find_pair_with_sum(std::vector<int> mass, int a) {
  if (!std::is_sorted(mass.begin(), mass.end())) {
    return {-1, -1};
  }
  int L = 0;
  int R = mass.size() - 1;

  while (L != R) {
    if (mass[L] + mass[R] == a) {
      return {L, R};
    }
    if (mass[L] + mass[R] < a) {
      L += 1;
    } else {
      R -= 1;
    }
  }

  return {-1, -1};
}
