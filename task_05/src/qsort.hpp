#pragma once

#include <iostream>
#include <util.hpp>
#include <vector>

template <typename T>
void QuickSort(std::vector<T>& arr, int l, int r) {
  if (l < r) {
    int q = Partition(arr, l, r);
    QuickSort(arr, l, q);
    QuickSort(arr, q + 1, r);
  }
}
