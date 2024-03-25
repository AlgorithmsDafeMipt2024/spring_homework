#pragma once

#include <iostream>
#include <vector>

class Heap {
public:
    void sift_down(int i);
    void sift_up(int i);
    void insert(int value);
    int get_min();
    void build(std::vector<int> vec);
    int del_min();
    std::vector<int> copy();

private:
    std::vector<int> heap;
};

int find_min(std::vector<int> vec);

std::vector<int> result(std::vector<int> heap);
