#include <heap_sort.hpp>
#include <iostream>
#include <util.hpp>

int main() {
  std::vector<int> a{3, 4, 6, 1, 8};
  HeapSort(a);
  std::cout << a << std::endl;
  return 0;
}
