#include "topology_sort.hpp"

pair<long long, long long> solve(vector<long long> a, long long sum) {
    long long n = a.size();
    long long i = 0, j = n - 1;
    while(i < j) {
        if (a[i] + a[j] == sum) {
            return {a[i], a[j]};
        } else if (a[i] + a[j] > sum) {
            j--;
        } else {
            i++;
        }
    }
    return {-1, -1};
}
