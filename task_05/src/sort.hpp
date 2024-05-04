#pragma once
#include <concepts/comparable.hpp>
#include <concepts/constructable.hpp>
#include <cstddef>
#include <functional>
#include <iostream>
#include <stdexcept>
#include <utility>

template <constructable CustomClass>
void merge_two_sorted_arrays(CustomClass* array_start,
                             CustomClass* array_middle,
                             CustomClass* array_end) {
  size_t array_size = array_end - array_start;

  CustomClass array[array_size];
  size_t index = 0;

  CustomClass* start_reserve = array_start;
  CustomClass* middle_reserve = array_middle;

  while ((array_start < middle_reserve) || (array_middle < array_end)) {
    if ((array_start < middle_reserve) && (array_middle < array_end))
      if (*array_start < *array_middle) {
        array[index] = *(array_start);
        ++index;
        ++array_start;
      } else {
        array[index] = *(array_middle);
        ++index;
        ++array_middle;
      }
    else if ((array_start < middle_reserve) && (array_middle == array_end)) {
      array[index] = *(array_start);
      ++index;
      ++array_start;
    } else {
      array[index] = *(array_middle);
      ++index;
      ++array_middle;
    }
  }

  index = 0;
  for (CustomClass* iterator = start_reserve; iterator < array_end;
       iterator++) {
    *iterator = array[index];
    index++;
  }
}

template <constructable CustomClass>
void merge_sort(CustomClass* array_start, CustomClass* array_end) {
  if ((array_end == array_start) || (array_end - array_start == 1)) return;

  merge_sort(array_start, array_start + (array_end - array_start) / 2);
  merge_sort(array_start + (array_end - array_start) / 2, array_end);
  merge_two_sorted_arrays(
      array_start, array_start + (array_end - array_start) / 2, array_end);
}