#pragma once

#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>

template <typename T>
int Partition(std::vector<T>& arr, int l, int r) {
  std::srand(std::time(nullptr));
  int pv_index = l + std::rand() % (r - l + 1);
  T pivot = arr[pv_index];
  std::swap(arr[pv_index], arr[(l + r) / 2]);
  int i = l, j = r;
  while (i <= j) {
    while (arr[i] < pivot) {
      i++;
    }
    while (arr[j] > pivot) {
      j--;
    }
    if (i >= j) {
      break;
    }
    std::swap(arr[i++], arr[j--]);
  }
  return j;
}

template <typename T>
void QuickSort(std::vector<T>& arr, int l, int r) {
  if (l < r) {
    int q = Partition(arr, l, r);
    QuickSort(arr, l, q);
    QuickSort(arr, q + 1, r);
  }
}
