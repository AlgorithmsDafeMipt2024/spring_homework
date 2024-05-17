#pragma once
#include <cstddef>
#include <stdexcept>
#include <vector>

template <typename CustomType>
concept comparable = requires(CustomType a, CustomType b) {
  a < b;
  a <= b;
  a == b;
  a >= b;
  a > b;
  a != b;
};

template <comparable CustomType>
size_t Partition(std::vector<CustomType>& data_array, size_t left_index,
                 size_t right_index) {
  // Seperate by the middle element
  CustomType& separator = data_array[(left_index + right_index) / 2];
  size_t left = left_index;
  size_t right = right_index;
  while (left <= right) {
    while (data_array[left] < separator) left++;
    while (data_array[right] > separator) right--;
    if (left >= right) break;
    std::swap(data_array[left++], data_array[right--]);
  }
  return right;
}

template <comparable CustomType>
CustomType FindOrdinalStatistic(std::vector<CustomType> data_array, size_t k) {
  if (k >= data_array.size())
    throw std::runtime_error("k is greater than the size of the array\n");
  size_t left = 0;
  size_t right = data_array.size() - 1;
  for (;;) {
    size_t middle = Partition(data_array, left, right);

    if (middle == k)
      return data_array[middle];
    else if (k < middle)
      right = middle;
    else
      left = middle + 1;
  }
}