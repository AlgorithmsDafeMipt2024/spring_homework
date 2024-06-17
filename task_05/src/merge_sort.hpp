#include <deque>
#include <vector>
using namespace std;

template <typename T>
void Merge(T* begin, T* middle, T* end) {
  std::vector<T> sorted_array;

  T* begin_copy = begin;
  T* middle_copy = middle;

  while ((begin < middle_copy) || (middle < end)) {
    if ((begin < middle_copy) && (middle < end)) {
      if (*begin <= *middle) {
        sorted_array.push_back(*begin);
        ++begin;
      } else {
        sorted_array.push_back(*middle);
        ++middle;
      }
    } else {
      if (begin < middle_copy) {
        sorted_array.push_back(*begin);
        ++begin;
      } else {
        sorted_array.push_back(*middle);
        ++middle;
      }
    }
  }
  size_t index = 0;
  for (T* i = begin_copy; i < end; i++) {
    *i = sorted_array[index];
    index++;
  }
}

template <typename T>
void MergeSort(T* begin, T* end) {
  if ((begin == end) || (end - begin < 2)) return;

  T* middle = begin + (end - begin) / 2;

  MergeSort(begin, middle);
  MergeSort(middle, end);

  Merge(begin, middle, end);
}
