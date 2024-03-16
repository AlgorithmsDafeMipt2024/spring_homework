#include <iostream>
#include <stdexcept>
#include <vector>

#include "topology_sort.hpp"

size_t GetSize() {
  size_t length;
  std::cout << "Enter a length of array: ";
  std::cin >> length;
  if (length <= 1) {
    std::cout << "You need to enter a number greater than 1\n";
    GetSize();
  }
  return length;
};

long long GetNumber() {
  long long number;
  std::cout << "Enter a number: ";
  std::cin >> number;
  return number;
};

std::vector<long long> GetArray(size_t length) {
  std::vector<long long> nums;
  std::cout << "Enter the array: ";
  for (int i = 0; i < length; i++) {
    int number;
    std::cin >> number;
    nums.push_back(number);
  }
  return nums;
}

int main() {
  long long number = GetNumber();
  size_t length = GetSize();
  std::vector<long long> nums = GetArray(length);
  std::pair<long long, long long> res = GetTwoNums(number, nums);
  std::cout << "Two numbers, which add up to a given number: " << res.first
            << ", " << res.second;
  return 0;
}
