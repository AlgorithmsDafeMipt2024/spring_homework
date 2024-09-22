#include <cstddef>
#include <vector>

struct Day {
  Day(size_t id, double temp) : id_{id}, temp_{temp} {}
  size_t id_;
  double temp_;
};

std::vector<size_t> DaysTillWarming(std::vector<double> temps);