#pragma once

#include <algorithm>
#include <cstddef>
#include <experimental/random>
#include <iostream>
#include <optional>
#include <valarray>
#include <vector>

// O*(NlogN) (but upper limit is O(n^2) if pivat is bad)
std::vector<int> QuickSort(std::vector<int> massive);