#include <cstddef>
#include <stdexcept>
#include <vector>

template <typename T>
size_t Division(std::vector<T>& data, size_t left, size_t right) {
  T pivot = data[(left + right) / 2];
  while (left <= right) {
    while (data[left] < pivot) ++left;
    while (data[right] > pivot) --right;
    if (left >= right) break;
    std::swap(data[left], data[right]);
    if (data[left] != pivot) ++left;
    if (data[right] != pivot) --right;
  }
  return right;
}

template <typename T>
T NthElement(std::vector<T> data, size_t n) {
  if (n >= data.size())
    throw std::runtime_error("N is greater then array size");

  size_t left = 0;
  size_t right = data.size() - 1;
  while (true) {
    size_t mid_index = Division(data, left, right);

    if (mid_index == n) {
      return data[mid_index];
    } else if (n < mid_index) {
      right = mid_index;
    } else {
      left = mid_index + 1;
    }
  }
}