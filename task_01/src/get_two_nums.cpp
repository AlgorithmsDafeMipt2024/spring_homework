#include "get_two_nums.hpp"

std::pair<long long, long long> GetTwoNums(long long number,
                                           std::vector<long long> nums) {
  if (nums.size() <= 1) {
    throw std::length_error("The array size must be greater than 1.");
  }
  size_t left = 0;
  size_t right = nums.size() - 1;
  while (left != right) {
    if (nums[left] + nums[right] == number)
      return {nums[left], nums[right]};
    else if (nums[left] + nums[right] < number)
      left++;
    else if (nums[left] + nums[right] > number)
      right--;
  }
  throw std::logic_error(
      "There are no two elements, which add up to a given number.");
}
