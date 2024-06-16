#include <iostream>

#include "merge_sort.hpp"

int main() {
  constexpr int size = 8;
  int arr[size] = {6, 5, 3, 1, 8, 7, 2, 4};
  MergeSort(arr, arr + size);
  for (int i = 0; i < size; ++i) std::cout << arr[i] << " ";
  return 0;
}
