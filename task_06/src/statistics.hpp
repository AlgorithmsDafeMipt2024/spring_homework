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