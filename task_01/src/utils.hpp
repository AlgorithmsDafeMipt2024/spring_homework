#pragma once
#include <iostream>
#include <vector>
// Returns pair of indices, which gives in sum target sum
// If target sun is not presented returns pair -1; -1
// If we target sum presented in several ways returns i, j so that i is minimumal index and j is maximum index
std::pair<int, int> FindTargetSumInArray(std::vector<int> v, int targetSum);