#include "insertion_sort.hpp"

std::vector<int> Insert(std::vector<int> massive, int num) {
  std::vector<int> new_massive;
  if (num <= massive[0]) {
    new_massive.push_back(num);
    for (int i = 0; i < massive.size(); i++) {
      new_massive.push_back(massive[i]);
    }
    return new_massive;
  }

  else if (num >= massive[massive.size() - 1]) {
    massive.push_back(num);
    return massive;
  }

  int position = 0;
  for (int i = 0; num >= massive[i]; i++) {
    new_massive.push_back(massive[i]);
    position = i;
  }
  new_massive.push_back(num);

  for (int i = position + 1; i < massive.size(); i++) {
    new_massive.push_back(massive[i]);
  }
  return new_massive;
}

// O(n^2)y
std::vector<int> InsertionSort(std::vector<int> massive) {
  if (massive.size() == 0) {
    return massive;
  }
  std::vector<int> new_massive;
  new_massive.push_back(massive[0]);
  for (int i = 1; i < massive.size(); i++) {
    new_massive = Insert(new_massive, massive[i]);
  }
  return new_massive;
}