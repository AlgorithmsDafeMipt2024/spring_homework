#pragma once
#include <iostream>
#include <vector>

std::pair<int,int> FindSum(int number, std::vector<int> array);
class SmallVector : public std::runtime_error{
    using std::runtime_error::runtime_error;
};