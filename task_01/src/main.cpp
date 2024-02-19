// std libs:
#include <exception>
#include <iostream>
#include <vector>

// my libs:
#include "two_sum.hpp"
#include "utilities.hpp"

// std usings:
using std::cout, std::cerr, std::endl;

int main() {
  cout << "That is the programm, that finds 2 numbers" << endl
       << "from sorted array that add up to your given number." << endl;

  long long number;
  ReadNumberFromConsole(number);

  // MEANS: вектор, который вводит пользователь
  std::vector<long long> vec{0, -1};

  while (!IsSorted(vec)) {
    ReadFromConsole(vec);
    if (!IsSorted(vec)) cout << "Please, enter sorted array." << endl;
  }

  try {
    // MEANS: пара чисел из вектора, которые в сумме дадут заданное число
    auto need_pair = TwoElemsGivingSum(vec, number);

    cout << "Given number is equal to the sum: ";
    PrintToConsole(need_pair);
  } catch (const std::exception& e) {
    cerr << e.what() << endl;
  }

  cout << endl;

  return 0;
}
