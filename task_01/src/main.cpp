// std libs:
#include <algorithm>
#include <exception>
#include <iostream>
#include <utility>
#include <vector>

// my libs:
#include "two_sum.hpp"
#include "utilities.hpp"

// std usings:
using std::cout, std::cerr, std::endl, std::is_sorted;

int main() {
  cout << "That is the programm, that finds 2 numbers" << endl
       << "from sorted array that add up to your given number." << endl;

  // MEANS: вектор, который вводит пользователь
  std::vector<long long> vec{0, -1};

  while (!is_sorted(vec.begin(), vec.end())) {
    std::cin >> vec;
    if (!is_sorted(vec.begin(), vec.end()))
      cout << "Please, enter sorted array." << endl;
  }

  // cout << vec << std::endl;

  // MEANS: число, которое нужно представить суммой двух
  long long number;
  std::cout << "Enter number: ";
  std::cin >> number;
  if (!std::cin) std::cerr << "Invalid number input." << std::endl;

  try {
    // MEANS: пара чисел из вектора, которые в сумме дадут заданное число
    auto need_pair = TwoElemsGivingSum(vec, number);

    cout << "Given number is equal to the sum: ";
    cout << need_pair << std::endl;
  } catch (const std::exception& e) {
    cerr << e.what() << endl;
  }

  cout << endl;

  return 0;
}
