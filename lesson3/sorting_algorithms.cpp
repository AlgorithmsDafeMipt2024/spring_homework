#include <vector>

// bubble_sort: O*(n^2), O(n^2)
// bogo_sort: O*(n!), O(+inf)
// insertion_sort: O*(n^2), O(n^2)
// selection_sort: O*(n^2), O(n^2)
// merge_sort (top_down/bottom_up): O*(nlogn), O(nlogn)
// quick_sort: O*(nlogn), (O(n^2) - ineffective, O(nlogn) - effective)

// qsort [] = []
// qsort(x : xs) = qsort(filter(<x) xs) ++ [x] (filter(=x) xs) ++
// qsort(filter(>x) xs)

void bubble_sort(std::vector<int>& v) {}

void td_merge_sort(std::vector<int>& v) {
  for (int l = 1; l < v.size(); l++) {
    for (int i = 0; i + l < v.size(); i += 2 * l) {
    }
  }
}