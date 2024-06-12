#include "sorts.hpp"

#include <stdexcept>
#include <vector>

void SORT::swap(std::vector<int> &A, int i, int j) {
  int i_val = A[i];
  A[i] = A[j];
  A[j] = i_val;
}

void SORT::heapify(std::vector<int> &A, int h_size, int i) {
  int l = 2 * i + 1;
  int r = 2 * i + 2;
  int largest = i;
  if (l < h_size and A[l] > A[largest]) {
    largest = l;
  }
  if (r < h_size and A[r] > A[largest]) {
    largest = r;
  }
  if (largest != i) {
    swap(A, i, largest);
    heapify(A, h_size, largest);
  }
}

void SORT::heapsort(std::vector<int> &list) {
  // build_heap

  int h_size = list.size();
  for (int i = h_size / 2 - 1; i >= 0; i--) {
    heapify(list, h_size, i);
  }

  for (int i = h_size - 1; i >= 0; i--) {
    swap(list, 0, i);
    h_size--;
    heapify(list, h_size, 0);
  }
}

std::vector<int> SORT::heapsorted(std::vector<int> list) {
  heapsort(list);
  return list;
}

int SORT::partition(std::vector<int> &A, int start, int end) {
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

void SORT::quicksort(std::vector<int> &list) {
  quicksort(list, 0, list.size() - 1);
}

void SORT::quicksort(std::vector<int> &list, int start, int end) {
  if (start >= end) {
    return;
  }

  int pivot = partition(list, start, end);

  quicksort(list, start, pivot - 1);

  quicksort(list, pivot + 1, end);
}

std::vector<int> SORT::quicksorted(std::vector<int> list) {
  quicksort(list);
  return list;
}

void SORT::sort_and_merge(std::vector<int> &A, int start, int end) {
  if (start >= end) {
    throw std::range_error(
        "sort_and_merge: start of a vector must be before an end");
  }

  int mid = (start + end) / 2;
  std::vector<int> left(A.begin() + start, A.begin() + mid + 1);
  std::vector<int> right(A.begin() + mid + 1, A.begin() + end + 1);

  int L = 0;
  int R = 0;
  for (int i = start; i <= end; i++) {
    if (!(mid + 1 + R <= end) or (left[L] <= right[R] and start + L <= mid)) {
      A[i] = left[L];
      L++;
    } else {
      A[i] = right[R];
      R++;
    }
  }
}

void SORT::mergesort(std::vector<int> &list) {
  mergesort(list, 0, list.size() - 1);
}

void SORT::mergesort(std::vector<int> &list, int start, int end) {
  if (start >= end) {
    return;
  }

  int mid = (start + end) / 2;
  mergesort(list, start, mid);
  mergesort(list, mid + 1, end);
  sort_and_merge(list, start, end);
}

std::vector<int> SORT::mergesorted(std::vector<int> list) {
  mergesort(list);
  return list;
}