#pragma once
#include <stdexcept>
#include <utility>
#include <vector>

class NoAnswer : public std::runtime_error {
 public:
  using std::runtime_error::runtime_error;
};

std::pair<int, int> FindSummands(const std::vector<int> array, int number);