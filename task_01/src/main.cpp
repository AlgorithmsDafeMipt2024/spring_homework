#include <iostream>

#include "summandds_in_array.hpp"

int main() {
  int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  int m = 5;
  std::optional<std::tuple<int*, int*>> b = SummanddsInArray(a, 9, m);
  if (b) {
    std::cout << "found" << std::endl;
    std::cout << std::get<0>(b.value()) << " : " << *std::get<0>(b.value())
              << std::endl;
    std::cout << std::get<1>(b.value()) << " : " << *std::get<1>(b.value())
              << std::endl;
  } else
    std::cout << "NOT found" << std::endl;
}
