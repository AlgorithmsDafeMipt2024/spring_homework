#include <heap_sort.hpp>
#include <iostream>
#include <merge_sort.hpp>
#include <util.hpp>

int main() {
  std::vector<int> a{5, 3, 4, 1, 2};
  HeapSort(a);
  std::cout << a << std::endl;
  std::cout << std::is_sorted(a.begin(), a.end()) << std::endl;

  std::vector<int> b{5, 3, 4, 1, 2};
  MergeSort(b);
  std::cout << b << std::endl;
  std::cout << std::is_sorted(b.begin(), b.end()) << std::endl;
  return 0;
}
