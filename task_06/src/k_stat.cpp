#include "k_stat.hpp"
#include <iostream>
#include <vector>

int Partition(std::vector<int> &vec, int low, int high) {
  int pivot = vec[high];
  int i = low - 1;
  for (int j = low; j <= high; ++j) {
    if (vec[j] < pivot) {
      ++i;
      std::swap(vec[i], vec[j]);
    }
  }
  std::swap(vec[i + 1], vec[high]);
  return (i + 1);
}

int Quick_sort(std::vector<int> &vec, int low, int high, int k) {
  if (low < high) {
    int m = Partition(vec, low, high);
    if (m == k - 1) {
      return k;
    }
    Quick_sort(vec, low, m - 1, k);
    Quick_sort(vec, m + 1, high, k);
  }
  throw std::logic_error("There is no such element");
}
