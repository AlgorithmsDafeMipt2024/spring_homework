#include "topology_sort.hpp"

#include <optional>

std::optional<std::tuple<int *, int *>> SummanddsInArray(int *arr, int n,
                                                         int sum) {
  int *begin = arr;
  int *end = arr + (n - 1);
  while (begin && end && begin < end && *begin + *end != sum)
    if ((*begin + *end) > sum)
      end--;
    else
      begin++;
  if ((!begin) || (!end) || (begin >= end) || (*begin + *end != sum))
    begin = end = nullptr;

  std::optional<std::tuple<int *, int *>> result = std::nullopt;
  if (begin != nullptr && end != nullptr)
    result = std::tuple<int *, int *>{begin, end};
  return result;
}
