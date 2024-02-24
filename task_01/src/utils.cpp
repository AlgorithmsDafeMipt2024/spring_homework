#include "utils.hpp"

std::pair<int, int> Task1(int m, std::vector<int> a) {
  int i = 0;
  int j = a.size() - 1;
  while (a[i] + a[j] != m) {
    if (a[i] + a[j] < m) i++;
    if (a[i] + a[j] > m) j--;
  }
  return {a[i], a[j]};
}
