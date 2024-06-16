#pragma once

#include <vector>

int Partition(std::vector<int>& arr, int left, int right) {
  int pivot_index = left + (right - left) / 2;
  int pivot_value = arr[pivot_index];
  std::swap(arr[pivot_index], arr[right]);
  int store_index = left;
  for (int i = left; i < right; ++i) {
    if (arr[i] < pivot_value) {
      std::swap(arr[i], arr[store_index]);
      ++store_index;
    }
  }
  std::swap(arr[store_index], arr[right]);
  return store_index;
}

int QuickSelect(std::vector<int>& arr, int left, int right, int k) {
  while (left <= right) {
    int pivot_index = Partition(arr, left, right);
    if (pivot_index == k) {
      return arr[pivot_index];
    } else if (pivot_index < k) {
      left = pivot_index + 1;
    } else {
      right = pivot_index - 1;
    }
  }
  return -1;
}

int FindNthOrder(std::vector<int> arr, int k) {
  if (arr.size() == 0) {
    throw std::invalid_argument("vector must be not empty");
  }
  return QuickSelect(arr, 0, arr.size() - 1, k - 1);
}