#include "heap.hpp"

using namespace std;

void Heap::sift_down(int u) {
    while (2 * u + 1 < heap.size()) {
        int left = 2 * u + 1;
        int right = 2 * u + 2;
        int j = left;
        if ((right < heap.size()) && heap[right] < heap[left])
            j = right;
        if (heap[u] <= heap[j])
            break;
        std::swap(heap[u], heap[j]);
        u = j;
    }
}

void Heap::sift_up(int i) {
    while (heap[i] < heap[(i - 1) / 2]) {
        std::swap(heap[i], heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

int Heap::get_min() { return heap[0]; }

int Heap::del_min() {
    int minimum = heap[0];
    heap[0] = heap[heap.size() - 1];
    heap.erase(heap.begin());
    sift_down(0);
    return minimum;
}

std::vector<int> Heap::copy() { return heap; }

void Heap::insert(int x) {
    heap.push_back(x);
    sift_up(heap.size() - 1);
}

void Heap::build(std::vector<int> vec) {
    for (int i = 0; i < vec.size(); ++i) {
        insert(vec[i]);
    }
}

int find_min(std::vector<int> vec) {
    Heap heap;
    heap.build(vec);
    return heap.get_min();
}

std::vector<int> result(std::vector<int> vec) {
    Heap heap;
    heap.build(vec);
    return heap.copy();
}