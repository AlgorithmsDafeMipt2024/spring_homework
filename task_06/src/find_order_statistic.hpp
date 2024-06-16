#include <cstddef>
#include <stdexcept>
#include <vector>

#include "vector"

template <typename T>
size_t Partition(std::vector<T>& data, size_t left_index, size_t right_index) {
  T separator = data[(left_index + right_index) / 2];
  while (left_index <= right_index) {
    while (data[left_index] < separator) ++left_index;
    while (data[right_index] > separator) --right_index;
    if (left_index >= right_index) break;
    std::swap(data[left_index], data[right_index]);
    if (data[left_index] != separator) ++left_index;
    if (data[right_index] != separator) --right_index;
  }
  return right_index;
}

template <typename T>
T FindOrderStatistic(std::vector<T> data, size_t k) {
  if (k >= data.size())
    throw std::runtime_error("k is greater then array size");

  size_t left_index = 0;
  size_t right_index = data.size() - 1;
  while (true) {
    size_t mid_index = Partition(data, left_index, right_index);

    if (mid_index == k) {
      return data[mid_index];
    } else if (k < mid_index) {
      right_index = mid_index;
    } else {
      left_index = mid_index + 1;
    }
  }
}
