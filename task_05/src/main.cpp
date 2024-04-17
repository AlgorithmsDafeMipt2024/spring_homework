#include <cstddef>
#include <iostream>

#include "sort.hpp"

int main() {
  std::vector<int> vector = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
  for (size_t ind = 0; ind < vector.size(); ind++)
    std::cout << vector[ind] << ' ';
  std::cout << '\n';
  int* begin = &vector[0];
  int* end = &vector[vector.size()];
  merge_sort(begin, end);
  for (size_t ind = 0; ind < vector.size(); ind++)
    std::cout << vector[ind] << ' ';
  std::cout << '\n';

  return 0;
}
