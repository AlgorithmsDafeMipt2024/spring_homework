// std libs:
#include <iostream>

// my libs:
#include "days_before_warming.hpp"
#include "temperatures.hpp"
#include "utilities.hpp"

// std usings:
using std::cout, std::cin, std::endl;

int main() {
  std::vector<Temperature> vec{1,  2,  3, 4,  4,  3,  2,  1, 0,
                               -1, -5, 8, 31, -9, 58, 36, 5};
  cout << vec << endl;

  cout << DaysUntilWarmingSillyLooping(vec) << endl;
  cout << endl;

  cout << DaysUntilWarmingSmarterLooping(vec) << endl;
  cout << endl;

  cout << DaysUntilWarmingStackLooping(vec) << endl;
  cout << endl;
}
