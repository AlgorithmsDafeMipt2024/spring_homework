#include <gtest/gtest.h>

#include <limits>
#include <merge_sort.hpp>
#include <random>
#include <string>

TEST(Sort, Simple) {
  std::vector<int> b{5, 3, 4, 1, 2};
  MergeSort(b);
  EXPECT_TRUE(std::is_sorted(b.begin(), b.end()));
}

TEST(Sort, Empty) {
  std::vector<int> b;
  MergeSort(b);
  EXPECT_TRUE(b.empty());
}

TEST(Sort, Sorted) {
  std::vector<int> b{1, 2, 3, 4, 5};
  MergeSort(b);
  EXPECT_TRUE(std::is_sorted(b.begin(), b.end()));
}

TEST(Sort, Double) {
  std::vector<double> b{5.3, 3.1, 4.7, 1.2, 2.8};
  MergeSort(b);
  EXPECT_TRUE(std::is_sorted(b.begin(), b.end()));
}

TEST(Sort, Strings) {
  std::vector<std::string> b{"apple", "banana", "cherry", "date", "elderberry"};
  MergeSort(b);
  EXPECT_TRUE(std::is_sorted(b.begin(), b.end()));
}

TEST(Sort, Duplicates) {
  std::vector<int> b{5, 3, 4, 1, 2, 3, 1, 4};
  MergeSort(b);
  EXPECT_TRUE(std::is_sorted(b.begin(), b.end()));
}

TEST(Sort, NegativeNumbers) {
  std::vector<int> b{-5, -3, -4, -1, -2};
  MergeSort(b);
  EXPECT_TRUE(std::is_sorted(b.begin(), b.end()));
}

TEST(Sort, Characters) {
  std::vector<char> b{'e', 'a', 'c', 'b', 'd'};
  MergeSort(b);
  EXPECT_TRUE(std::is_sorted(b.begin(), b.end()));
}

struct TestType {
  int value;
  auto operator<=>(const TestType& other) const = default;
};

TEST(Sort, CustomTestType) {
  std::vector<TestType> b{{5}, {3}, {4}, {1}, {2}};
  MergeSort(b);
  EXPECT_TRUE(std::is_sorted(b.begin(), b.end()));
}

struct NegativeTestType {
  int value;
  auto operator<=>(const NegativeTestType& other) const = default;
};

TEST(Sort, CustomNegativeTestType) {
  std::vector<NegativeTestType> b{{-5}, {-3}, {-4}, {-1}, {-2}};
  MergeSort(b);
  EXPECT_TRUE(std::is_sorted(b.begin(), b.end()));
}

struct FloatTestType {
  float value;
  auto operator<=>(const FloatTestType& other) const = default;
};

TEST(Sort, CustomFloatTestType) {
  std::vector<FloatTestType> b{{5.3f}, {3.1f}, {4.7f}, {1.2f}, {2.8f}};
  MergeSort(b);
  EXPECT_TRUE(std::is_sorted(b.begin(), b.end()));
}

struct PairTestType {
  int first;
  double second;
  auto operator<=>(const PairTestType& other) const = default;
};

TEST(Sort, CustomPairTestType) {
  std::vector<PairTestType> b{
      {5, 3.14}, {3, 2.71}, {4, 1.62}, {1, 0.57}, {2, 6.28}};
  MergeSort(b);
  EXPECT_TRUE(std::is_sorted(b.begin(), b.end()));
}

struct BoolTestType {
  bool value;
  auto operator<=>(const BoolTestType& other) const = default;
};

TEST(Sort, CustomBoolTestType) {
  std::vector<BoolTestType> b{{true}, {false}, {true}, {false}, {true}};
  MergeSort(b);
  EXPECT_TRUE(std::is_sorted(b.begin(), b.end()));
}

struct CharTestType {
  char value;
  auto operator<=>(const CharTestType& other) const = default;
};

TEST(Sort, CustomCharTestType) {
  std::vector<CharTestType> b{{'e'}, {'a'}, {'c'}, {'b'}, {'d'}};
  MergeSort(b);
  EXPECT_TRUE(std::is_sorted(b.begin(), b.end()));
}

TEST(Sort, VeryLargeNumbers_MergeSort) {
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<int64_t> dis(
      std::numeric_limits<int64_t>::min(), std::numeric_limits<int64_t>::max());

  std::vector<int64_t> a;

  for (int i = 0; i < 1000000; ++i) {
    int64_t num = dis(gen);
    a.push_back(num);
  }

  MergeSort(a);
  EXPECT_TRUE(std::is_sorted(a.begin(), a.end()));
}

TEST(Sort, VeryLongStrings_MergeSort) {
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<char> dis('a', 'z');

  std::vector<std::string> a;

  for (int i = 0; i < 10000; ++i) {
    std::string str(1000, 'a');
    for (char& c : str) {
      c = dis(gen);
    }
    a.push_back(str);
  }

  MergeSort(a);
  EXPECT_TRUE(std::is_sorted(a.begin(), a.end()));
}
