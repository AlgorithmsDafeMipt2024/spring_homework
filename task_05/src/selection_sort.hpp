#pragma once

#include <algorithm>
#include <cstddef>
#include <experimental/random>
#include <iostream>
#include <optional>
#include <valarray>
#include <vector>

int SearchMin(std::vector<int> massive);

// O(n^2)
std::vector<int> SelectionSort(std::vector<int> massive);