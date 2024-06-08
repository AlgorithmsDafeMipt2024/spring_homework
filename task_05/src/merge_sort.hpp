#ifndef MERGE_SORT_HPP
#define MERGE_SORT_HPP
#include <vector>

template <typename T>
void merge_sort(std::vector<T>& array) {
  if (array.size() > 1) {
    std::size_t size = array.size();
    std::size_t const left_size = size / 2;
    auto left = std::vector<T>(array.begin(), array.begin() + left_size);
    auto right = std::vector<T>(array.begin() + left_size, array.end());
    merge_sort(left);
    merge_sort(right);

    std::size_t lidx = 0;
    std::size_t ridx = 0;
    std::vector<T> tmp_array;

    while (lidx < left.size() || ridx < right.size()) {
      if (left[lidx] < right[ridx])
        tmp_array.push_back(left[lidx++]);
      else
        tmp_array.push_back(right[ridx++]);
      if (lidx == left.size()) {
        for (; ridx < right.size(); ++ridx) tmp_array.push_back(right[ridx]);
      } else if (ridx == right.size()) {
        for (; lidx < left.size(); ++lidx) tmp_array.push_back(left[lidx]);
      }
    }
    array = tmp_array;
  }
}
#endif