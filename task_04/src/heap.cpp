#include "heap.hpp"

#include <iostream>
#include <vector>

void Heap::SiftDown(int cur_node) {
  while (2 * cur_node + 1 < vec_.size()) {
    int left = 2 * cur_node + 1;
    int right = 2 * cur_node + 2;
    int next_node = left;
    if ((right < vec_.size()) && vec_[right] < vec_[left]) next_node = right;
    if (vec_[cur_node] <= vec_[next_node]) break;
    std::swap(vec_[cur_node], vec_[next_node]);
    cur_node = next_node;
  }
}

void Heap::SiftUp(int i) {
  while (vec_[i] < (vec_[(i - 1) / 2])) {
    std::swap(vec_[i], vec_[(i - 1) / 2]);
    i = (i - 1) / 2;
  }
}

int Heap::FindMin() { return vec_[0]; }

int Heap::ExtractMin() {
  int min = vec_[0];
  vec_[0] = vec_[vec_.size() - 1];
  vec_.pop_back();
  SiftDown(0);
  return min;
}

std::vector<int> Heap::CopyHeap() { return vec_; }

void Heap::Insert(int value) {
  vec_.push_back(value);
  SiftUp(vec_.size() - 1);
}

void Heap::BuildHeap(std::vector<int> vec) {
  for (int i = 0; i < vec.size(); ++i) {
    Insert(vec[i]);
  }
}

int FindMinimum(std::vector<int> vec) {
  Heap heap;
  heap.BuildHeap(vec);
  return heap.FindMin();
}

std::vector<int> HeapReady(std::vector<int> vec) {
  Heap heap;
  heap.BuildHeap(vec);
  return heap.CopyHeap();
}
