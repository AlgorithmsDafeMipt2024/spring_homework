#include <vector>
#pragma once

template <class T>
int Partition(std::vector<T>& v, int low, int high) {
  int pivot = v[high];
  int i = low - 1;

  for (int j = low; j <= high - 1; j++) {
    if (v[j] <= pivot) {
      i++;
      std::swap(v[i], v[j]);
    }
  }
  std::swap(v[i + 1], v[high]);
  return (i + 1);
}