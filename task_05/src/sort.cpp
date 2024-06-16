#include "sort.hpp"

#include <iostream>
#include <vector>

int Partition(std::vector<int> &arr, int low, int high) {
  int pivot = arr[high];
  int i = low - 1;
  for (int j = low; j <= high; ++j) {
    if (arr[j] < pivot) {
      ++i;
      std::swap(arr[i], arr[j]);
    }
  }
  std::swap(arr[i + 1], arr[high]);
  return (i + 1);
}

std::vector<int> QuickSort(std::vector<int> &arr, int low, int high) {
  if (low < high) {
    int m = Partition(arr, low, high);
    QuickSort(arr, low, m - 1);
    QuickSort(arr, m + 1, high);
  }
  return arr;
}