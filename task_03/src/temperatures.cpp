#include "temperatures.hpp"

// std libs:
#include <iostream>

// std usings:
using std::cout, std::cin, std::endl;

std::vector<size_t> DaysUntilWarmingSillyLooping(
    const std::vector<Temperature>& temperatures) {
  auto amount = temperatures.size();
  auto res = std::vector<size_t>(amount);
  for (size_t i = 0; i < temperatures.size(); i++) {
    res[i] = 0;
    for (size_t j = i; j < temperatures.size(); j++) {
      if (temperatures[i] >= temperatures[j])
        res[i]++;
      else
        break;
    }

    if (res[i] == amount - i) res[i] = 0;
  }
  return res;
}