#pragma once

#include <algorithm>
#include <cstddef>
#include <experimental/random>
#include <iostream>
#include <optional>
#include <valarray>
#include <vector>

std::vector<int> Insert(std::vector<int> massive, int num);

// O(n^2)
std::vector<int> InsertionSort(std::vector<int> massive);