#include "topology_sort.hpp"

std::tuple<int, int> MySearch(std::vector<int> list, int n) {
  int left = 0;
  int right = list.size() - 1;
  while (left != right) {
    int sum = list[left] + list[right];
    if (sum == n)
      return {list[left], list[right]};
    else if (sum < n)
      left++;
    else if (sum > n)
      right--;
  }
  // testtest;
  return {-1, -1};
}