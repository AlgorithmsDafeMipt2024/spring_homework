#include "heap.hpp"

#include <iostream>
#include <vector>

void Heap::SiftDown(int i) {
  while (2 * i + 1 < vec_.size()) {
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int j = left;
    if ((right < vec_.size()) && vec_[right] < vec_[left]) j = right;
    if (vec_[i] <= vec_[j]) break;
    std::swap(vec_[i], vec_[j]);
    i = j;
  }
}

void Heap::SiftUp(int i) {
  while (vec_[i] < (vec_[(i - 1) / 2])) {
    std::swap(vec_[i], vec_[(i - 1) / 2]);
    i = (i - 1) / 2;
  }
}

int Heap::Find_Min() { return vec_[0]; }

int Heap::Extract_Min() {
  int min = vec_[0];
  vec_[0] = vec_[vec_.size() - 1];
  vec_.erase(vec_.begin());
  SiftDown(0);
  return min;
}

std::vector<int> Heap::Copy_Heap() { return vec_; }

void Heap::Insert(int value) {
  vec_.push_back(value);
  SiftUp(vec_.size() - 1);
}

void Heap::Build_heap(std::vector<int> vec) {
  for (int i = 0; i < vec.size(); ++i) {
    Insert(vec[i]);
  }
}

int Find_Minimum(std::vector<int> vec) {
  Heap heap;
  heap.Build_heap(vec);
  return heap.Find_Min();
}

std::vector<int> Heap_Ready(std::vector<int> vec) {
  Heap heap;
  heap.Build_heap(vec);
  return heap.Copy_Heap();
}