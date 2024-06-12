
#include <gtest/gtest.h>

#include <string>
#include <utility>

#include "HashTable.hpp"

TEST(HashTable, Simple) {
  HashTable<std::string, int> table;
  std::vector<std::string> keys = {
      "Lobachevskiy", "Euler",  "Ferma",        "Lagrange", "Burbaki",
      "Kholmogorov",  "Landau", "Raigorodskiy", "Vinberg",  "Arnold"};
  std::vector<int> values = {1792, 1707, 1601, 1736, 1935,
                             1903, 1908, 1976, 1937, 1937};
  for (int i = 0; i < keys.size(); i++) {
    table.insert(keys[i], values[i]);
  }
  for (int i = 0; i < keys.size(); i++) {
    ASSERT_EQ(table.search(keys[i]), true);
  }
  ASSERT_EQ(table.search("Gauss"), false);
  ASSERT_EQ(table.search("Newton"), false);
  ASSERT_EQ(table.search("Bool"), false);
  ASSERT_EQ(table.search("Koshi"), false);
  ASSERT_EQ(table.search("Abele"), false);
  for (int i = 0; i < keys.size() / 2; i++) {
    table.erase(keys[i]);
  }
  for (int i = 0; i < keys.size() / 2; i++) {
    ASSERT_EQ(table.search(keys[i]), false);
  }
  for (int i = keys.size() / 2; i < keys.size(); i++) {
    ASSERT_EQ(table.search(keys[i]), true);
  }
}
