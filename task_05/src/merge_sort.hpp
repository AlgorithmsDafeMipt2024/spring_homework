template <typename T>
void MergeTwoSortdedArrays(T* first_arr_begin, T* second_arr_begin, T* end) {
  int size = end - first_arr_begin;
  T array[size];
  int index = 0;
  T* middle = second_arr_begin;
  T* start = first_arr_begin;
  while ((start < second_arr_begin) || (middle < end)) {
    if ((start < second_arr_begin) && (middle < end))
      if (*start <= *middle) {
        array[index] = *(start++);
      } else {
        array[index] = *(middle++);
      }
    else if ((start < second_arr_begin) && (middle == end))
      array[index] = *(start++);
    else if ((start == second_arr_begin) && (middle < end))
      array[index] = *(middle++);
    ++index;
  }

  index = 0;
  for (T* element_ptr = first_arr_begin; element_ptr < end; ++element_ptr)
    *element_ptr = array[index++];
}

template <typename T>
void MergeSort(T* begin, T* end) {
  if ((begin == end) || ((end - begin) == 1)) return;
  int step = (end - begin) / 2;
  MergeSort(begin, begin + step);
  MergeSort(begin + step, end);
  MergeTwoSortdedArrays(begin, begin + step, end);
}