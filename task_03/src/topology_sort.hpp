#pragma once
#include <iostream>
#include <vector>

class WrongVector : public std::runtime_error {
  using std::runtime_error::runtime_error;
};

std::vector<int> RiseTemperature(std::vector<int> vec);
