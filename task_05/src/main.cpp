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

  //   std::vector<int> vector2 = {1, 4, 6, 2, 3, 5};
  //   int* begin1 = &vector2[0];
  //   int* begin2 = &vector2[3];
  //   int* end = &vector2[vector2.size()];
  //   for (size_t ind = 0; ind < vector2.size(); ind++)
  //     std::cout << vector2[ind] << ' ';
  //   std::cout << '\n';
  //   merge_two_sorted_arrays(begin1, begin2, end);
  //   for (size_t ind = 0; ind < vector2.size(); ind++)
  //     std::cout << vector2[ind] << ' ';
  //   std::cout << '\n';

  return 0;
}
