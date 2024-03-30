#pragma once
#include <vector>

struct Day {
  int index_;
  int temp_;
};

std::vector<int> TempUpDayCounter(std::vector<int> temps);
