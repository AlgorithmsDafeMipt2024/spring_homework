#include <functional>
#include <random>
#include <vector>

template <typename T>
static std::size_t Partition(std::vector<T>& data, std::size_t left,
                             std::size_t right) {
  std::function<std::size_t(std::size_t, std::size_t)> RandomPivotIndex =
      [&](std::size_t left, std::size_t right) {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dis(left, right);
        return dis(gen);
      };

  std::size_t pivot_index = RandomPivotIndex(left, right);
  std::swap(data[pivot_index], data[right]);
  std::size_t index = left;

  for (std::size_t i = left; i < right; i++) {
    if (data[i] < data[right]) {
      std::swap(data[i], data[index]);
      index++;
    }
  }

  std::swap(data[right], data[index]);
  return index;
}

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