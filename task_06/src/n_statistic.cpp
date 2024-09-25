#include "n_statistic.hpp"

#include <stdexcept>

int findNstat(std::vector<int> list, int n) {
  if (list.size() == 0) {
    throw std::length_error("findNstat: empty vector given");
  }

  if (n >= list.size() or n < 0) {
    throw std::out_of_range("findNstat: n must be in range of given vector");
  }

  int start = 0;
  int end = list.size() - 1;

  while (true) {
    int mid = partition(list, start, end);

    if (mid == n) {
      return list[mid];
    } else if (n < mid) {
      end = mid - 1;
    } else {
      start = mid;
    }
  }
}

void swap(std::vector<int> &A, int i, int j) {
  int i_val = A[i];
  A[i] = A[j];
  A[j] = i_val;
}

int partition(std::vector<int> &A, int start, int end) {
  int pivot = A[end];

  int swapIndex = start;

  for (int i = start; i < end; i++) {
    if (A[i] <= pivot) {
      swap(A, i, swapIndex);
      swapIndex++;
    }
  }

  swap(A, swapIndex, end);

  return swapIndex;
}