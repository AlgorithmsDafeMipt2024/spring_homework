#pragma once
#include <stack>
#include <vector>

struct Day {
  int index;
  double value;
  Day(int index, double value) : index(index), value(value) {}
};

std::vector<int> TemperatureCounter(std::vector<double> temps);