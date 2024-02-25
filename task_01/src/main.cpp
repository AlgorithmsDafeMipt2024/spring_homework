#include <iostream>
#include <stdexcept>
#include <vector>

#include "topology_sort.hpp"

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

int main() {
  long long n = GetNumber();
  long long l = GetSize();
  std::vector<long long> nums = GetArray(l);
  std::pair<long long, long long> res = GetTwoNums(n, nums);
  std::cout << "Two numbers, which add up to a given number: " << res.first
            << ", " << res.second;
  return 0;
}
