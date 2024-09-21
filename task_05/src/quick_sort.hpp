#include <../lib/src/util.hpp>

template <typename T>
void QuickSort(std::vector<T>& data) {
  if (data.empty()) return;
  std::function<void(std::size_t, std::size_t)> QuickSortStep =
      [&](std::size_t l, std::size_t r) {
        if (l >= r) return;
        std::size_t pivot_index = Partition(data, l, r);
        if (pivot_index) QuickSortStep(l, pivot_index - 1);
        QuickSortStep(pivot_index + 1, r);
      };

  QuickSortStep(0, data.size() - 1);
}