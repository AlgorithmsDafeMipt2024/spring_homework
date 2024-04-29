#include <heap_sort.hpp>
#include <iostream>
#include <util.hpp>

int main() {
  std::vector<int> a{5, 3, 4, 1, 2};
  HeapSort(a);
  std::cout << a << std::endl;
  std::cout << std::is_sorted(a.begin(), a.end()) << std::endl;
  return 0;
}
