#pragma once
#include <concepts>
#include <cstddef>
#include <functional>
#include <iostream>
#include <stdexcept>
#include <utility>

// concept to check if the type is comparable (now obsolete)
template <typename CustomType>
concept comparable = requires(CustomType a, CustomType b) {
  a < b;
  a <= b;
  a == b;
  a >= b;
  a > b;
  a != b;
};

// concept to check if the type is comparable with a concrete function
template <typename Function, typename CustomType>
concept comparing = requires(CustomType a, CustomType b, Function f) {
  f(a, b);
};

// function, that merges two sorted arrays, time complexity is O(n+m),
// where n - length of first array, m - length of second array
template <typename CustomType, comparing<CustomType> Function = std::function<
                                   bool(const CustomType&, const CustomType&)>>
void MergeTwoSortedArrays(
    CustomType* begin, CustomType* middle, CustomType* end,
    Function comparing_function = [](const CustomType& a, const CustomType& b) {
      return a < b;
    }) {
  size_t size = end - begin;
  // array where sorted data is stored temporary
  CustomType array[size];
  size_t index = 0;

  CustomType* begin_reserve = begin;
  CustomType* middle_reserve = middle;

  while ((begin < middle_reserve) || (middle < end)) {
    if ((begin < middle_reserve) && (middle < end))
      (comparing_function(*begin, *middle))
          ? array[index++] = std::move(*(begin++))    // this line
          : array[index++] = std::move(*(middle++));  // is cursed

    else if ((begin < middle_reserve) && (middle == end))
      array[index++] = std::move(*(begin++));

    // else if for more explicit code
    else if ((begin == middle_reserve) && (middle < end))
      array[index++] = std::move(*(middle++));
  }

  index = 0;
  for (CustomType* iterator = begin_reserve; iterator < end; iterator++) {
    *iterator = std::move(array[index]);
    index++;
  }
}

// time complexity - O(nlogn) where n - length of an array
template <typename CustomType, comparing<CustomType> Function = std::function<
                                   bool(const CustomType&, const CustomType&)>>
void MergeSort(
    CustomType* begin, CustomType* end,
    Function comparing_function = [](CustomType a, CustomType b) {
      return a < b;
    }) {
  if ((end == begin) || (end - begin == 1)) return;

  CustomType* middle_begin = begin + (end - begin) / 2;
  MergeSort(begin, middle_begin, comparing_function);
  MergeSort(middle_begin, end, comparing_function);
  MergeTwoSortedArrays(begin, middle_begin, end, comparing_function);
}

// this took way too long