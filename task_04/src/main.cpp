#include <binary_heap.hpp>
#include <iostream>
#include <util.hpp>

int main() {
  auto bminh = BinaryMinHeap({3, 2, 1});
  bminh.Add(1);
  std::cout << bminh.Data() << std::endl;
  bminh.Add(4);
  std::cout << bminh.Data() << std::endl;
  bminh.Add(3);
  std::cout << bminh.Data() << std::endl;
  bminh.Add(2);
  std::cout << bminh.Data() << std::endl;
  bminh.Add(1);
  std::cout << bminh.Data() << std::endl;
  bminh.ExtractMin();
  std::cout << bminh.Data() << std::endl;

  std::cout << std::endl;

  auto bmaxh = BinaryMaxHeap({1, 2, 3});
  bmaxh.Add(1);
  std::cout << bmaxh.Data() << std::endl;
  bmaxh.Add(4);
  std::cout << bmaxh.Data() << std::endl;
  bmaxh.Add(3);
  std::cout << bmaxh.Data() << std::endl;
  bmaxh.Add(2);
  std::cout << bmaxh.Data() << std::endl;
  bmaxh.Add(1);
  std::cout << bmaxh.Data() << std::endl;
  bmaxh.ExtractMax();
  std::cout << bmaxh.Data() << std::endl;
}
