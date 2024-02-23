#include <iostream>

#include "topology_sort.hpp"

int main() {
  int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  int m = 5;
  std::tuple<bool, int*, int*> b = topology_sort(a, 9, m);
  if (std::get<0>(b)) {
    std::cout << "found" << std::endl;
    std::cout << std::get<1>(b) << " : " << *std::get<1>(b) << std::endl;
    std::cout << std::get<2>(b) << " : " << *std::get<2>(b) << std::endl;
  } else
    std::cout << "NOT found" << std::endl;
}
