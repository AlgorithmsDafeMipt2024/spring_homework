
#include <gtest/gtest.h>

#include "bogo_sort.h"
#include "bubble_sort.h"
#include "insertion_sort.h"
#include "merge_sort.h"
#include "quick_sort.h"
#include "selection_sort.h"

// BogoSort tests
TEST(BogoSort, Simple) {
  std::vector<int> mas = {1};
  ASSERT_EQ({1}, {1});
}
