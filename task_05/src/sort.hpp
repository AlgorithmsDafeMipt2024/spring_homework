#include <concepts>
#include <functional>

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
requires(is_comparable<T>()) void sort_two_sorted_arrays(T* begin1, T* begin2,
                                                         T* end) {
  T array[(end - begin1)];
  size_t index = 0;
  while (begin1 < begin2 || begin2 < end)
    if (begin1 < begin2 && begin2 < end)
      (*begin1 <= *begin2) ? array[index++] = *(begin1++)   // this line
                           : array[index++] = *(begin2++);  // is cursed
    else
      (begin1 < begin2 && begin2 == end)
          ? array[index++] = *(begin1++)   // this line
          : array[index++] = *(begin2++);  // as well
  index = 0;
  for (T* iterator = begin1; iterator < end; iterator++)
    *iterator = array[index++];
}

template <typename T>
requires(is_comparable<T>()) void merge_sort(const T* begin, const T* end) {}