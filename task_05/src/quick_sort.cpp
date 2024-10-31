#include "quick_sort.hpp"

#include <vector>

// O*(NlogN) (but upper limit is O(n^2) if pivat is always bad)
std::vector<int> QuickSort(std::vector<int> massive) {
  if (massive.empty()) return std::vector<int>{};
  int pivat_index = massive.size() / 2;
  int pivat = massive[pivat_index];

  std::vector<int> smaller_part;
  std::vector<int> bigger_part;

  if (massive.size() > 1) {
    for (int i = 0; i < massive.size(); i++) {
      if (i != pivat_index) {
        if (massive[i] <= pivat) {
          smaller_part.push_back(massive[i]);
        } else {
          bigger_part.push_back(massive[i]);
        }
      }
    }
  } else {
    return massive;
  }
  if (smaller_part.size() > 1) {
    smaller_part = QuickSort(smaller_part);
  }

  if (bigger_part.size() > 1) {
    bigger_part = QuickSort(bigger_part);
  }

  std::vector<int> result = smaller_part;
  result.push_back(pivat);
  for (int i = 0; i < bigger_part.size(); i++) {
    result.push_back(bigger_part[i]);
  }
  return result;
}