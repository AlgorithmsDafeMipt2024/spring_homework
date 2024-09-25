#pragma once

#include <numeric>
#include <stdexcept>
#include <vector>

class BinHeap {
 public:
  std::vector<int> heap;
  int size;

  BinHeap();
  BinHeap(std::vector<int> list);

  std::vector<int> get_heap();

  void insert_key_value(int key, int value);
  void push_value(int value);
  int pop_max();

 private:
  void swap(int i, int j);  // heap[i] <-> heap[j]
  void swap(
      int i,
      char key);  // swaps heap[i] with his left ('l') or right ('r') child

  void heapify();       // make whole heap a binary heap
  void heapify(int i);  // fix heap to be a binart heap (at 'i')
};
