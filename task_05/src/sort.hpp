#pragma once
#include <concepts>
#include <cstddef>
#include <functional>
#include <iostream>
#include <stdexcept>
#include <utility>

template <typename T>
concept comparable = requires(T a, T b) {
  a < b;
  a <= b;
  a == b;
  a >= b;
  a > b;
  a != b;
};

template <comparable T>
void merge_two_sorted_arrays(T* begin, T* middle, T* end) {
  if (begin == end) throw std::runtime_error("merge two empty arrays\n");

  size_t size = end - begin;
  T array[size];
  size_t index = 0;

  T* begin_reserve = begin;
  T* middle_reserve = middle;

  while ((begin < middle_reserve) || (middle < end)) {
    if ((begin < middle_reserve) && (middle < end))
      (*begin < *middle)
          ? array[index++] = std::move(*(begin++))    // this line
          : array[index++] = std::move(*(middle++));  // is cursed

    else if ((begin < middle_reserve) && (middle == end))
      array[index++] = std::move(*(begin++));

    // else if for more explicit code
    else if ((begin == middle_reserve) && (middle < end))
      array[index++] = std::move(*(middle++));
  }

  index = 0;
  for (T* iterator = begin_reserve; iterator < end; iterator++) {
    *iterator = std::move(array[index]);
    index++;
  }
}

template <comparable T>
void merge_sort(T* begin, T* end) {
  if ((end == begin) || (end - begin == 1)) return;

  T* middle_begin = begin + (end - begin) / 2;
  merge_sort(begin, middle_begin);
  merge_sort(middle_begin, end);
  merge_two_sorted_arrays(begin, middle_begin, end);
}