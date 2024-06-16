#include "search_task.hpp"

#include <algorithm>
#include <optional>

std::optional<std::pair<LL, LL>> SearchInList(std::vector<LL> list, LL n) {
  if (list.empty()) return std::nullopt;
  if (!std::is_sorted(list.cbegin(), list.cend())) return std::nullopt;
  LL left = 0;
  LL right = list.size() - 1;
  while (left != right) {
    LL sum = list[left] + list[right];
    if (sum == n)
      return std::pair<LL, LL>{list[left], list[right]};
    else if (sum < n)
      left++;
    else if (sum > n)
      right--;
  }
  return std::nullopt;
}