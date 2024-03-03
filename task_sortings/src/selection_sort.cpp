#include "selection_sort.h"

int SearchMin(std::vector<int> massive) {
  int min = massive[0];
  int index = 0;
  for (int i = 0; i < massive.size(); i++) {
    if (massive[i] < min) {
      min = massive[i];
      index = i;
    }
  }
  return index;
}

// O(n^2)
std::vector<int> SelectionSort(std::vector<int> massive) {
  for (int i = 0; i < massive.size(); i++) {
    std::vector<int> cutted_massive =
        std::vector<int>(massive.begin() + i, massive.end());
    int min_element_index = SearchMin(cutted_massive) + i;
    std::swap(massive[i], massive[min_element_index]);
  }
  return massive;
}