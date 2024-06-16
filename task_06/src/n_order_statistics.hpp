#pragma once
#include <concepts/comparable.hpp>
#include <cstddef>
#include <stdexcept>
#include <vector>

template <comparable CustomClass>
size_t Partition(std::vector<CustomClass>& data_array, size_t left_index,
                 size_t right_index) {
  CustomClass& separator = data_array[(left_index + right_index) / 2];
  while (left_index <= right_index) {
    while (data_array[left_index] < separator) left_index++;
    while (data_array[right_index] > separator) right_index--;
    if (left_index >= right_index) break;
    std::swap(data_array[left_index++], data_array[right_index--]);
  }
  return right_index;
}

template <comparable CustomClass>
CustomClass NthOrderStatistics(std::vector<CustomClass> data_array,
                               size_t nth_statistics) {
  if (nth_statistics >= data_array.size())
    throw std::logic_error(
        "nth_statistics is greater than the size of the array\n");
  size_t left_index = 0;
  size_t right_index = data_array.size() - 1;
  while (true) {
    size_t middle = Partition(data_array, left_index, right_index);

    if (middle == nth_statistics) return data_array[middle];
    (nth_statistics < middle) ? right_index = middle : left_index = middle + 1;
  }
}