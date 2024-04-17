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

  // while ((begin < middle_reserve) || (middle < end)) {
  //   if ((begin < middle_reserve) && (middle < end)) {
  //     if (*begin <= *middle) {
  //       array[index] = *begin;
  //       index++;
  //       begin++;
  //     } else {
  //       array[index] = *middle;
  //       index++;
  //       middle++;
  //     }
  //   } else if ((begin < middle_reserve) && (middle == end)) {
  //     array[index] = *begin;
  //     index++;
  //     begin++;
  //   } else if ((begin == middle_reserve) && (middle < end)) {
  //     array[index] = *middle;
  //     index++;
  //     middle++;
  //   }
  // }

  // std::cout << "size = " << size << '\n';
  // std::cout << "result array = \n";
  // for (size_t ind = 0; ind < size; ind++) std::cout << array[ind] << ' ';
  // std::cout << '\n';

  index = 0;
  for (T* iterator = begin_reserve; iterator < end; iterator++) {
    *iterator = std::move(array[index]);
    index++;
  }
}

template <comparable T>
void merge_sort(T* begin, T* end) {
  if ((end == begin) || (end - begin == 1)) return;
  // std::cout << "___________________________\n";
  // std::cout << "begin = " << begin << '\n'
  //           << "end - begin = " << end - begin << '\n'
  //           << "(end - begin)/2 = " << (end - begin) / 2 << '\n'
  //           << "begin + (end - begin)/2 = " << begin + (end - begin) / 2 <<
  //           '\n'
  //           << "end = " << end << '\n';
  // std::cout << "vector = {" << *begin;
  // for (T* itr = ++begin; itr < end; itr++) std::cout << ", " << *itr;
  // std::cout << "}\n"
  //           << "___________________________\n\n";

  T* middle_begin = begin + (end - begin) / 2;
  merge_sort(begin, middle_begin);
  merge_sort(middle_begin, end);
  merge_two_sorted_arrays(begin, middle_begin, end);
}