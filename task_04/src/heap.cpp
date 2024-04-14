#include "heap.hpp"

int Heap::pop_min() {
  int minimum = data[0];
  std::swap(data[0], data[data.size()]);
  data.pop_back();  // min is already at last position

  // Sift Down
  int current_index = 0;
  int left_child_index = 1;
  int right_child_index = 2;

  while (left_child_index < data.size() & right_child_index < data.size()) {
    if (data[left_child_index] < data[right_child_index]) {
      std::swap(data[left_child_index], data[current_index]);
      current_index = left_child_index;
    } else {
      std::swap(data[right_child_index], data[current_index]);
      current_index = right_child_index;
    }
  }

  return minimum;
}

void Heap::insert(int x) {
  data.push_back(x);

  // Sift Up
  int current_index = data.size();
  int parent_index = (current_index - 1) / 2;

  while (data[current_index]<data[parent_index] & current_index> 0) {
    std::swap(data[current_index], data[parent_index]);
    current_index = (current_index - 1) / 2;
  }
}
