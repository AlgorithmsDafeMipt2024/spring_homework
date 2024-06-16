#pragma once

#include <iostream>
#include <tuple>
#include <vector>

// O(logn)
int BinSearch(std::vector<int> mas, int num);

// O(n^2)
std::tuple<int, int> NSquareSearch(std::vector<int> massive, int num);

// O(nlogn)
std::tuple<int, int> NLogNSearch(std::vector<int> massive, int num);

// O(n)
std::tuple<int, int> NSearch(std::vector<int> massive, int num);