#include <iostream>
#include <stdexcept>
#include <vector>

long long GetSize() {
  long long c;
  std::cout << "Enter a length of array: ";
  std::cin >> c;
  if (c <= 0) {
    std::cout << "You need to enter a number greater than 0\n";
    GetSize();
  }
  return c;
};

long long GetNumber() {
  long long n;
  std::cout << "Enter a number: ";
  std::cin >> n;
  return n;
};

std::vector<long long> GetArray(long long l) {
  std::vector<long long> nums;
  std::cout << "Enter the array: ";
  for (int i = 0; i < l; i++) {
    int c;
    std::cin >> c;
    nums.push_back(c);
  }
  return nums;
}

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

int main() {
  long long n = GetNumber();
  long long l = GetSize();
  std::vector<long long> nums = GetArray(l);
  std::pair<long long, long long> res = GetTwoNums(n, nums);
  std::cout << "Two numbers, which add up to a given number: " << res.first
            << ", " << res.second;
  return 0;
}
