#pragma once

#include <ctime>
#include <vector>

template <class T>
int Partition(std::vector<T>& data, int l, int r) {
  std::srand(std::time(nullptr));
  int pivotPos = l + std::rand() % (r - l);
  if (pivotPos != r - 1) {
    std::swap(data[r - 1], data[pivotPos]);
  }

  int i = l, j = l;
  T pivot = data[r - 1];
  while (j < r - 1) {
    if (data[j] <= pivot) {
      std::swap(data[i++], data[j]);
    }
    j++;
  }
  if (i != r - 1) {
    std::swap(data[i], data[r - 1]);
  }
  return i;
}

template <class T>
T FindKStatistics(std::vector<T>& data, int l, int r, int k) {
  int lastPivotPos = 0, left = l, right = r;
  while (left < right) {
    if ((lastPivotPos = Partition(data, left, right)) == k) {
      return data[lastPivotPos];
    } else if (lastPivotPos > k) {
      right = lastPivotPos;
    } else {
      left = lastPivotPos + 1;
    }
  }
  return data[lastPivotPos];
}
