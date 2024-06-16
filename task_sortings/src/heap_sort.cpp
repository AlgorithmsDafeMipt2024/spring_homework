#include "heap_sort.hpp"

#include <vector>

std::vector<int> HeapSort(std::vector<int> massive) {
  Heap heap;

  // put all elems into heap one by one
  for (int i = 0; i < massive.size(); i++) {
    heap.Insert(massive[i]);
  }

  // push back with mins
  for (int i = 0; i < massive.size(); i++) {
    massive[i] = heap.PopMin();
  }

  return massive;
}