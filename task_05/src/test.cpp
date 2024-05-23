
#include <gtest/gtest.h>
#include "sort.hpp"

TEST(MergeSortTests, Case1) {
    ASSERT_EQ(mergeSort(std::vector<int>{73, 74, 75, 71, 69, 72, 76, 73}), (std::vector<int>{69, 71, 72, 73, 73, 74, 75, 76}));
}

TEST(MergeSortTests, Case2) {
    ASSERT_EQ(mergeSort(std::vector<int>{30, 40, 50, 60}), (std::vector<int>{30, 40, 50, 60}));
}

TEST(MergeSortTests, Case3) {
    ASSERT_EQ(mergeSort(std::vector<int>{30, 60, 90, 70, 80, 40, 30}), (std::vector<int>{30, 30, 40, 60, 70, 80, 90}));
}

TEST(MergeSortTests, Case4) {
    ASSERT_EQ(mergeSort(std::vector<int>{55, 55, 55, 55, 55}), (std::vector<int>{55, 55, 55, 55, 55}));
}

TEST(MergeSortTests, Case5) {
    ASSERT_EQ(mergeSort(std::vector<int>{76, 75, 74, 73, 72, 71, 70}), (std::vector<int>{70, 71, 72, 73, 74, 75, 76}));
}

TEST(MergeSortTests, Case6) {
    ASSERT_EQ(mergeSort(std::vector<int>{75, 72, 71, 70, 74, 76}), (std::vector<int>{70, 71, 72, 74, 75, 76}));
}