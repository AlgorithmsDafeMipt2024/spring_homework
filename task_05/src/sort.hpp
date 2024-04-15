#pragma once
#include <concepts>
#include <functional>
#include <iostream>
#include <stdexcept>

// try to deduce if type is comparable (naive solution)
template <typename T>
constexpr bool is_comparable() {
  T a{};
  try {
    bool attempt_to_compate = a < a;
  } catch (...) {
    return false;
  }
  return true;
}

template <typename T>
requires(is_comparable<T>()) void merge_two_sorted_arrays(T* begin1, T* begin2,
                                                          T* end) {
  if (begin1 == end) throw std::runtime_error("merge two empty arrays\n");

  size_t size = end - begin1;
  T array[size];
  size_t index = 0;

  while ((begin1 < begin2) || (begin2 < end)) {
    if ((begin1 < begin2) && (begin2 < end))
      (*begin1 <= *begin2) ? array[index++] = *(begin1++)   // this line
                           : array[index++] = *(begin2++);  // is cursed
    else if ((begin1 < begin2) && (begin2 == end))
      array[index++] = *(begin1++);
    else if ((begin1 == begin2) && (begin2 < end))
      array[index++] = *(begin1++);
  }

  index = 0;
  for (T* iterator = begin1; iterator < end; iterator++)
    *iterator = array[index++];
}

template <typename T>
requires(is_comparable<T>()) void merge_sort(T* begin, T* end) {
  if ((end == begin) || (end - begin == 1)) return;
  merge_sort(begin, begin + (end - begin) / 2);
  merge_sort(begin + (end - begin) / 2, end);
  merge_two_sorted_arrays(begin, begin + (end - begin) / 2, end);
}