#include <../lib/src/util.hpp>

template <class T>
T FindStatistics(std::vector<T>& data, int order) {
  int pivot_pos = 0, left = 0, right = data.size();
  while (left < right) {
    pivot_pos = Partition(data, left, right - 1);
    if (pivot_pos == order) return data[pivot_pos];
    pivot_pos > order ? right = pivot_pos : left = pivot_pos + 1;
  }
  return data[pivot_pos];
}