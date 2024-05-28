#include "heap.hpp"

int Heap::PopMin() {
  if (data_.size() != 0) {
    int minimum = data_[0];
    std::swap(data_[0], data_[data_.size() - 1]);
    data_.pop_back();  // min is already at last position

    // Sift Down
    int current_index = 0;
    int left_child_index = 1;
    int right_child_index = 2;

    while ((left_child_index<data_.size() & data_[current_index]>
                data_[left_child_index]) ||
           (right_child_index<data_.size() & data_[current_index]>
                data_[right_child_index])) {
      if (right_child_index < data_.size() &
          data_[right_child_index] < data_[left_child_index]) {
        std::swap(data_[right_child_index], data_[current_index]);
        current_index = right_child_index;
        left_child_index = 2 * current_index + 1;
        right_child_index = 2 * current_index + 2;
      } else {
        std::swap(data_[left_child_index], data_[current_index]);
        current_index = left_child_index;
        left_child_index = 2 * current_index + 1;
        right_child_index = 2 * current_index + 2;
      }
    }

    return minimum;
  } else {
    std::cout << "empty heap";
    return {};
  }
}

void Heap::Insert(int x) {
  data_.push_back(x);

  // Sift Up
  int current_index = data_.size() - 1;
  int parent_index = (current_index - 1) / 2;

  while (data_[current_index]<data_[parent_index] & current_index> 0) {
    std::swap(data_[current_index], data_[parent_index]);
    current_index = (current_index - 1) / 2;
    parent_index = (current_index - 1) / 2;
  }
}
