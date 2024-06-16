#pragma once

#include <algorithm>
#include <cstddef>
#include <experimental/random>
#include <iostream>
#include <optional>
#include <valarray>
#include <vector>

int Search(std::vector<int> massive, int num);
bool IsSorted(std::vector<int> massive);

std::vector<int> ShuffleIndexes(int n);
std::vector<int> ShuffleMassive(std::vector<int> massive);

// O(n!)
std::vector<int> BogoSort(std::vector<int> massive);