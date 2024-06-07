#pragma once

#include <vector>

int partition(std::vector<int>& arr, int left, int right) {
  int pivotIndex = left + (right - left) / 2;
  int pivotValue = arr[pivotIndex];
  std::swap(arr[pivotIndex], arr[right]);
  int storeIndex = left;
  for (int i = left; i < right; ++i) {
    if (arr[i] < pivotValue) {
      std::swap(arr[i], arr[storeIndex]);
      ++storeIndex;
    }
  }
  std::swap(arr[storeIndex], arr[right]);
  return storeIndex;
}

int quickSelect(std::vector<int>& arr, int left, int right, int k) {
  while (left <= right) {
    int pivotIndex = partition(arr, left, right);
    if (pivotIndex == k) {
      return arr[pivotIndex];
    } else if (pivotIndex < k) {
      left = pivotIndex + 1;
    } else {
      right = pivotIndex - 1;
    }
  }
  return -1;
}

int findNthOrder(std::vector<int> arr, int k) {
  return quickSelect(arr, 0, arr.size() - 1, k - 1);
}