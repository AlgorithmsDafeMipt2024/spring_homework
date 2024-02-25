#include "topology_sort.hpp"

std::pair<long long, long long> GetTwoNums(long long n,
                                           std::vector<long long> nums) {
  size_t l = 0;
  size_t r = nums.size() - 1;
  while (l != r) {
    if (nums[l] + nums[r] == n)
      return {nums[l], nums[r]};
    else if (nums[l] + nums[r] < n)
      l++;
    else if (nums[l] + nums[r] > n)
      r--;
  }
  throw std::logic_error(
      "There are no two elements, which add up to a given number.");
}