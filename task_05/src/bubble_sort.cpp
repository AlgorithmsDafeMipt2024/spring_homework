#include "bubble_sort.hpp"

// O(n^2)
std::vector<int> BubbleSort(std::vector<int> massive) {
  for (int i = 0; i < massive.size(); i++) {
    for (int j = 0; j < massive.size() - i - 1; j++) {
      if (massive[j] > massive[j + 1]) {
        int temporary = massive[j];
        massive[j] = massive[j + 1];
        massive[j + 1] = temporary;
      }
    }
  }
  return massive;
}