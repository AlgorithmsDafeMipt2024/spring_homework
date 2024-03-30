#pragma once
#include <iostream>
#include <vector>

class WrongVector : public std::runtime_error {
  using std::runtime_error::runtime_error;
};

std::pair<int, int> SumOfElements(int num, const std::vector<int> arr);
