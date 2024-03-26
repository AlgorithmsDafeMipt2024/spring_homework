#include <stdexcept>
#include <vector>
template <typename T>
T FindSortedSequence(std::vector<T> array, int k) {
  int begin = 0, end = array.size() - 1;
  if (k > end) throw std::out_of_range("k should be less then size of array");
  while (true) {
    int first = begin;
    int pivot = (rand() % (end - begin) + 1) + begin;
    std::swap(array[pivot], array[end]);

    while (array[begin] <= array[end] && begin < end) ++begin;

    for (int start = begin + 1; start < end; ++start)
      if (array[start] <= array[end]) std::swap(array[start], array[begin++]);
    std::swap(array[begin], array[end]);

    if (k == begin)
      return array[begin];
    else if (k < begin) {
      end = begin - 1;
      if (end == first) return array[begin - 1];
      begin = 0;
    } else if (k > begin) {
      ++begin;
      if (begin == end) return array[begin];
    }
  }
}