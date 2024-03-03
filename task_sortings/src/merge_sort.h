#pragma once

#include <algorithm>
#include <cstddef>
#include <experimental/random>
#include <iostream>
#include <optional>
#include <valarray>
#include <vector>

std::vector<int> Merge(std::vector<int> part1, std::vector<int> part2);

// O(NlogN)
std::vector<int> MergeSort_topbottom(std::vector<int> massive);
// O(NlogN)
std::vector<int> MergeSort_bottomup(std::vector<int> massive);