
#include <gtest/gtest.h>

#include <map>
#include <set>

#include "map.hpp"
#include "set.hpp"

template <class Key, class Data>
void compare_s21_std_map(s21::map<Key, Data> s21map,
                         std::map<Key, Data> stdmap) {
  ASSERT_EQ(s21map.size(), stdmap.size());
  auto s21i = s21map.begin();
  auto stdi = stdmap.begin();
  for (; s21i != s21map.end(); s21i++, stdi++)
    ASSERT_EQ(s21i->first, stdi->first);
}

template <class Key, class Data>
void compare_s21_std_map(std::map<Key, Data> stdmap,
                         s21::map<Key, Data> s21map) {
  ASSERT_EQ(s21map.size(), stdmap.size());
  auto s21i = s21map.begin();
  auto stdi = stdmap.begin();
  for (; s21i != s21map.end(); s21i++, stdi++)
    ASSERT_EQ(s21i->first, stdi->first);
}

template <class Key, class Data>
void compare_s21_s21_map(s21::map<Key, Data> s21map_1,
                         s21::map<Key, Data> s21map_2) {
  ASSERT_EQ(s21map_1.size(), s21map_2.size());
  auto s21_i_1 = s21map_1.begin();
  auto s21_i_2 = s21map_2.begin();
  for (; s21_i_1 != s21map_1.end(); s21_i_1++, s21_i_2++)
    ASSERT_EQ(s21_i_1->first, s21_i_2->first);
}

template <class Key>
void compare_s21_std_set(s21::set<Key> s21set, std::set<Key> stdset) {
  ASSERT_EQ(s21set.size(), stdset.size());
  auto s21i = s21set.begin();
  auto stdi = stdset.begin();
  for (; s21i != s21set.end(); s21i++, stdi++) ASSERT_EQ(*s21i, *stdi);
}

template <class Key>
void compare_s21_std_set(std::set<Key> stdset, s21::set<Key> s21set) {
  ASSERT_EQ(s21set.size(), stdset.size());
  auto s21i = s21set.begin();
  auto stdi = stdset.begin();
  for (; s21i != s21set.end(); s21i++, stdi++) ASSERT_EQ(*s21i, *stdi);
}

template <class Key>
void compare_s21_s21_set(s21::set<Key> s21set_1, s21::set<Key> s21set_2) {
  ASSERT_EQ(s21set_1.size(), s21set_2.size());
  auto s21_i_1 = s21set_1.begin();
  auto s21_i_2 = s21set_2.begin();
  for (; s21_i_1 != s21set_1.end(); s21_i_1++, s21_i_2++)
    ASSERT_EQ(*s21_i_1, *s21_i_2);
}

TEST(map, size1) {
  s21::map<int, double> s21map = {};
  ASSERT_EQ(s21map.size(), 0);
}

TEST(map, size2) {
  s21::map<int, double> s21map = {{1, 1.3}};
  ASSERT_EQ(s21map.size(), 1);
}

TEST(map, size3) {
  s21::map<int, double> s21map = {{1, 1.3}, {2, 2.3}};
  ASSERT_EQ(s21map.size(), 2);
}

TEST(map, simple1) {
  s21::map<int, double> s21map = {{1, 1.3}, {2, 2.3}, {3, 3.3},
                                  {4, 4.3}, {5, 5.3}, {6, 6.3},
                                  {7, 7.3}, {8, 8.3}, {9, 9.3}};
  std::map<int, double> stdmap = {{1, 1.3}, {2, 2.3}, {3, 3.3},
                                  {4, 4.3}, {5, 5.3}, {6, 6.3},
                                  {7, 7.3}, {8, 8.3}, {9, 9.3}};
  compare_s21_std_map(stdmap, s21map);
}

TEST(map, simple2) {
  s21::map<int, double> s21map = {
      {1, 1.3}, {2, 2.3}, {3, 3.3}, {4, 4.3}, {5, 5.3}, {6, 6.3},
      {7, 7.3}, {8, 8.3}, {9, 9.3}, {1, 1.5}, {2, 2.5}, {3, 3.5},
      {4, 4.3}, {5, 5.3}, {6, 6.5}, {7, 7.5}, {8, 8.5}, {9, 9.5}};
  std::map<int, double> stdmap = {
      {1, 1.3}, {2, 2.3}, {3, 3.3}, {4, 4.3}, {5, 5.3}, {6, 6.3},
      {7, 7.3}, {8, 8.3}, {9, 9.3}, {1, 1.5}, {2, 2.5}, {3, 3.5},
      {4, 4.3}, {5, 5.3}, {6, 6.5}, {7, 7.5}, {8, 8.5}, {9, 9.5}};
  compare_s21_std_map(stdmap, s21map);
}

TEST(map, simple3) {
  s21::map<int, double> s21map = {{3, 3.3}, {1, 1.3}, {4, 4.3},
                                  {7, 7.3}, {8, 8.3}, {9, 9.3},
                                  {5, 5.3}, {6, 6.3}, {2, 2.3}};
  std::map<int, double> stdmap = {{1, 1.3}, {2, 2.3}, {3, 3.3},
                                  {4, 4.3}, {5, 5.3}, {6, 6.3},
                                  {7, 7.3}, {8, 8.3}, {9, 9.3}};
  compare_s21_std_map(stdmap, s21map);
}

TEST(map, simple4) {
  s21::map<int, double> s21map_orig = {{1, 1.3}, {2, 2.3}, {3, 3.3},
                                       {4, 4.3}, {5, 5.3}, {6, 6.3},
                                       {7, 7.3}, {8, 8.3}, {9, 9.3}};
  s21::map<int, double> s21map_target = s21map_orig;
  compare_s21_s21_map(s21map_target, s21map_orig);
}

TEST(map, simple5) {
  s21::map<int, double> s21map = {{1, 1.3}, {2, 2.3}, {3, 3.3},
                                  {4, 4.3}, {5, 5.3}, {6, 6.3},
                                  {7, 7.3}, {8, 8.3}, {9, 9.3}};
  std::map<int, double> stdmap = {{1, 1.3}, {2, 2.3}, {3, 3.3},
                                  {4, 4.3}, {5, 5.3}, {6, 6.3},
                                  {7, 7.3}, {8, 8.3}, {9, 9.3}};
  s21map = s21map;
  compare_s21_std_map(stdmap, s21map);
}

TEST(map, empty1) {
  s21::map<int, double> s21map = {};
  ASSERT_EQ(s21map.empty(), true);
}

TEST(map, empty2) {
  s21::map<int, double> s21map = {{1, 1.3}};
  ASSERT_EQ(s21map.empty(), false);
}

TEST(map, clear) {
  s21::map<int, double> s21map = {{1, 1.3}, {2, 2.3}, {3, 3.3}};
  s21map.clear();
  ASSERT_EQ(s21map.empty(), true);
}

TEST(map, max_size) {
  s21::map<int, double> s21map = {};
  std::map<int, double> stdmap = {};
  std::cout << "s21 max_size: " << s21map.max_size() << std::endl
            << "std max_size: " << stdmap.max_size() << std::endl;
  ASSERT_EQ(s21map.empty(), true);
}

TEST(map, swap) {
  s21::map<int, double> s21map_1 = {{5, 5.3}, {3, 3.3}};
  s21::map<int, double> s21map_2 = {{7, 7.3}, {8, 8.3}, {9, 9.3}};
  std::map<int, double> stdmap_1 = {{5, 5.3}, {3, 3.3}};
  std::map<int, double> stdmap_2 = {{7, 7.3}, {8, 8.3}, {9, 9.3}};
  stdmap_1.swap(stdmap_2);
  s21map_1.swap(s21map_2);
  compare_s21_std_map(stdmap_1, s21map_1);
  compare_s21_std_map(stdmap_2, s21map_2);
}

TEST(map, merge1) {
  s21::map<int, double> s21map_1 = {{5, 5.3}, {3, 3.3}};
  s21::map<int, double> s21map_2 = {{7, 7.3}, {8, 8.3}, {9, 9.3}};
  std::map<int, double> stdmap = {
      {5, 5.3}, {3, 3.3}, {7, 7.3}, {8, 8.3}, {9, 9.3}};
  s21map_1.merge(s21map_2);
  compare_s21_std_map(s21map_1, stdmap);
}

TEST(map, merge2) {
  s21::map<int, double> s21map_1 = {{5, 5.3}, {3, 3.3}};
  s21::map<int, double> s21map_2 = {{7, 7.3}, {8, 8.3}, {9, 9.3}};
  std::map<int, double> stdmap = {
      {5, 5.3}, {3, 3.3}, {7, 7.3}, {8, 8.3}, {9, 9.3}};
  s21map_1.merge(s21map_2);
  compare_s21_std_map(s21map_1, stdmap);
}

TEST(map, insert1) {
  s21::map<int, double> s21map_1 = {{1, 1.3}};
  s21::map<int, double> s21map_2 = {};
  auto pair = s21map_2.insert({1, 1.3});
  ASSERT_EQ(pair.second, true);
  ASSERT_EQ(pair.first->first, 1);
  pair = s21map_2.insert({1, 1.5});
  ASSERT_EQ(pair.second, false);
  ASSERT_EQ(pair.first->first, 1);
  compare_s21_s21_map(s21map_1, s21map_2);
}

TEST(map, insert2) {
  s21::map<int, double> s21map_1 = {{1, 1.3}, {2, 2.3}, {3, 3.3}, {4, 4.3},
                                    {5, 5.3}, {6, 6.3}, {7, 7.3}};
  s21::map<int, double> s21map_2 = {{2, 2.3}, {4, 4.3}, {7, 7.3}};
  s21map_2.insert({3, 3.3});
  s21map_2.insert({4, 4.3});
  s21map_2.insert({3, 3.5});
  s21map_2.insert({2, 2.5});
  s21map_2.insert({5, 5.3});
  s21map_2.insert({7, 7.5});
  s21map_2.insert({6, 6.3});
  auto pair = s21map_2.insert({1, 1.3});
  ASSERT_EQ(pair.second, true);
  ASSERT_EQ(pair.first->first, 1);
  pair = s21map_2.insert({1, 1.5});
  ASSERT_EQ(pair.second, false);
  ASSERT_EQ(pair.first->first, 1);
  compare_s21_s21_map(s21map_1, s21map_2);
}

TEST(map, insert3) {
  std::map<int, double> s21map_1 = {
      {0, 0.3},     {-100, -100.3}, {100, 100.3}, {-50, -50.3}, {50, 50.3},
      {-25, -25.3}, {25, 25.3},     {-12, -12.3}, {12, 12.3},   {-6, -6.3},
      {6, 6.3},     {-3, -3.3},     {3, 3.3},     {-1, -1.3},   {1, 1.3}};
  s21::map<int, double> s21map_2 = {};
  s21map_2.insert({0, 0.3});
  s21map_2.insert({-100, -100.3});
  s21map_2.insert({100, 100.3});
  s21map_2.insert({-50, -50.3});
  s21map_2.insert({50, 50.3});
  s21map_2.insert({-25, -25.3});
  s21map_2.insert({25, 25.3});
  s21map_2.insert({-12, -12.3});
  s21map_2.insert({12, 12.3});
  s21map_2.insert({-6, -6.3});
  s21map_2.insert({6, 6.3});
  s21map_2.insert({-3, -3.3});
  s21map_2.insert({3, 3.3});
  s21map_2.insert({-1, -1.3});
  s21map_2.insert({1, 1.3});
  compare_s21_std_map(s21map_1, s21map_2);
}

TEST(map, insert4) {
  std::map<int, double> s21map_1 = {{0, 0.3},     {-100, -100.3}, {100, 100.3},
                                    {-50, -50.3}, {50, 50.3},     {-75, -75.3},
                                    {75, 75.3}};
  s21::map<int, double> s21map_2 = {};
  s21map_2.insert({0, 0.3});
  s21map_2.insert({-100, -100.3});
  s21map_2.insert({100, 100.3});
  s21map_2.insert({-50, -50.3});
  s21map_2.insert({50, 50.3});
  s21map_2.insert({-75, -75.3});
  s21map_2.insert({75, 75.3});
  compare_s21_std_map(s21map_1, s21map_2);
}

TEST(map, insert_or_assign1) {
  s21::map<int, double> s21map_1 = {{1, 1.3}, {2, 2.3}, {3, 3.3},
                                    {4, 4.3}, {5, 5.3}, {6, 6.3},
                                    {7, 7.3}, {8, 8.3}, {9, 9.3}};
  s21::map<int, double> s21map_2 = {{1, 1.5}, {2, 2.5}, {3, 3.5},
                                    {4, 4.3}, {5, 5.3}, {6, 6.5},
                                    {7, 7.5}, {8, 8.5}, {9, 9.5}};
  s21::map<int, double> s21map_target = {};
  s21map_target.insert_or_assign(1, 1.3);
  s21map_target.insert_or_assign(2, 2.3);
  s21map_target.insert_or_assign(3, 3.3);
  s21map_target.insert_or_assign(4, 4.3);
  s21map_target.insert_or_assign(5, 5.3);
  s21map_target.insert_or_assign(6, 6.3);
  s21map_target.insert_or_assign(7, 7.3);
  s21map_target.insert_or_assign(8, 8.3);
  s21map_target.insert_or_assign(9, 9.3);
  compare_s21_s21_map(s21map_1, s21map_target);
  s21map_target.insert_or_assign(1, 1.5);
  s21map_target.insert_or_assign(2, 2.5);
  s21map_target.insert_or_assign(3, 3.5);
  s21map_target.insert_or_assign(4, 4.5);
  s21map_target.insert_or_assign(5, 5.3);
  s21map_target.insert_or_assign(6, 6.5);
  s21map_target.insert_or_assign(7, 7.5);
  s21map_target.insert_or_assign(8, 8.5);
  s21map_target.insert_or_assign(9, 9.5);
  compare_s21_s21_map(s21map_1, s21map_target);
}

TEST(map, erase1) {
  s21::map<int, double> s21map_1 = {};
  s21::map<int, double> s21map_2 = {{1, 1.3}};
  s21map_2.erase(s21map_2.begin());
  compare_s21_s21_map(s21map_1, s21map_2);
}

TEST(map, erase2) {
  s21::map<int, double> s21map_1 = {};
  s21::map<int, double> s21map_2 = {};
  s21map_2.erase(s21map_2.begin());
  compare_s21_s21_map(s21map_1, s21map_2);
}

TEST(map, erase3) {
  std::map<int, double> stdmap = {
      {1, 1.3}, {2, 2.3}, {4, 4.3}, {5, 5.3}, {6, 6.3}};
  s21::map<int, double> s21map = {{1, 1.3}, {2, 2.3}, {3, 3.3},
                                  {4, 4.3}, {5, 5.3}, {6, 6.3}};
  auto i = s21map.begin();
  i++;
  i++;
  s21map.erase(i);
  compare_s21_std_map(stdmap, s21map);
}

TEST(map, at1) {
  std::map<int, double> stdmap = {
      {0, 0.3},     {-100, -100.3}, {100, 100.3}, {-50, -50.3}, {50, 50.3},
      {-25, -25.3}, {25, 25.3},     {-12, -12.3}, {12, 12.3},   {-6, -6.3},
      {6, 6.3},     {-3, -3.3},     {3, 3.3},     {-1, -1.3},   {1, 1.3}};
  s21::map<int, double> s21map = {
      {0, 0.3},     {-100, -100.3}, {100, 100.3}, {-50, -50.3}, {50, 50.3},
      {-25, -25.3}, {25, 25.3},     {-12, -12.3}, {12, 12.3},   {-6, -6.3},
      {6, 6.3},     {-3, -3.3},     {3, 3.3},     {-1, -1.3},   {1, 1.3}};
  ASSERT_EQ(stdmap.at(-100), s21map.at(-100));
  ASSERT_EQ(stdmap.at(50), s21map.at(50));
  ASSERT_EQ(stdmap.at(-25), s21map.at(-25));
  ASSERT_EQ(stdmap.at(12), s21map.at(12));
  ASSERT_EQ(stdmap.at(-6), s21map.at(-6));
  ASSERT_EQ(stdmap.at(3), s21map.at(3));
  ASSERT_EQ(stdmap.at(-1), s21map.at(-1));
  ASSERT_EQ(stdmap.at(0), s21map.at(0));
}

TEST(map, at2) {
  std::map<int, double> stdmap = {{0, 0.3},     {-100, -100.3}, {100, 100.3},
                                  {-50, -50.3}, {50, 50.3},     {-75, -75.3},
                                  {75, 75.3}};
  s21::map<int, double> s21map = {{0, 0.3},     {-100, -100.3}, {100, 100.3},
                                  {-50, -50.3}, {50, 50.3},     {-75, -75.3},
                                  {75, 75.3}};
  ASSERT_EQ(stdmap.at(-100), s21map.at(-100));
  ASSERT_EQ(stdmap.at(50), s21map.at(50));
  ASSERT_EQ(stdmap.at(-75), s21map.at(-75));
  ASSERT_EQ(stdmap.at(0), s21map.at(0));
}

TEST(map, at3) {
  s21::map<int, double> s21map = {{0, 0.3},     {-100, -100.3}, {100, 100.3},
                                  {-50, -50.3}, {50, 50.3},     {-75, -75.3},
                                  {75, 75.3}};
  ASSERT_ANY_THROW(s21map.at(25));
  EXPECT_ANY_THROW(s21map.at(-25));
  EXPECT_ANY_THROW(s21map.at(10));
}

TEST(map, contains1) {
  s21::map<int, double> s21map = {
      {0, 0.3},     {-100, -100.3}, {100, 100.3}, {-50, -50.3}, {50, 50.3},
      {-25, -25.3}, {25, 25.3},     {-12, -12.3}, {12, 12.3},   {-6, -6.3},
      {6, 6.3},     {-3, -3.3},     {3, 3.3},     {-1, -1.3},   {1, 1.3}};
  ASSERT_EQ(s21map.contains(-100), true);
  ASSERT_EQ(s21map.contains(100), true);
  ASSERT_EQ(s21map.contains(-50), true);
  ASSERT_EQ(s21map.contains(50), true);
  ASSERT_EQ(s21map.contains(-25), true);
  ASSERT_EQ(s21map.contains(25), true);
  ASSERT_EQ(s21map.contains(-12), true);
  ASSERT_EQ(s21map.contains(12), true);
  ASSERT_EQ(s21map.contains(-6), true);
  ASSERT_EQ(s21map.contains(6), true);
  ASSERT_EQ(s21map.contains(-3), true);
  ASSERT_EQ(s21map.contains(3), true);
  ASSERT_EQ(s21map.contains(-1), true);
  ASSERT_EQ(s21map.contains(1), true);
  ASSERT_EQ(s21map.contains(0), true);
}

TEST(map, contains2) {
  s21::map<int, double> s21map = {{0, 0.3},     {-100, -100.3}, {100, 100.3},
                                  {-50, -50.3}, {50, 50.3},     {-75, -75.3},
                                  {75, 75.3}};
  ASSERT_EQ(s21map.contains(-100), true);
  ASSERT_EQ(s21map.contains(100), true);
  ASSERT_EQ(s21map.contains(-50), true);
  ASSERT_EQ(s21map.contains(50), true);
  ASSERT_EQ(s21map.contains(-75), true);
  ASSERT_EQ(s21map.contains(75), true);
  ASSERT_EQ(s21map.contains(0), true);
}

TEST(map, contains3) {
  s21::map<int, double> s21map = {{0, 0.3},     {-100, -100.3}, {100, 100.3},
                                  {-50, -50.3}, {50, 50.3},     {-75, -75.3},
                                  {75, 75.3}};
  ASSERT_EQ(s21map.contains(0), true);
  ASSERT_EQ(s21map.contains(100), true);
  ASSERT_EQ(s21map.contains(-100), true);
  ASSERT_EQ(s21map.contains(11), false);
  ASSERT_EQ(s21map.contains(-1000), false);
  ASSERT_EQ(s21map.contains(1000), false);
}

TEST(set, size1) {
  s21::set<int> s21set = {};
  ASSERT_EQ(s21set.size(), 0);
}

TEST(set, size2) {
  s21::set<int> s21set = {1};
  ASSERT_EQ(s21set.size(), 1);
}

TEST(set, size3) {
  s21::set<int> s21set = {1, 2};
  ASSERT_EQ(s21set.size(), 2);
}

TEST(set, simple1) {
  s21::set<int> s21set = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  std::set<int> stdset = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  compare_s21_std_set(stdset, s21set);
}

TEST(set, simple2) {
  s21::set<int> s21set = {1, 2, 3, 4, 5, 6, 7, 8, 9, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  std::set<int> stdset = {1, 2, 3, 4, 5, 6, 7, 8, 9, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  compare_s21_std_set(stdset, s21set);
}

TEST(set, simple3) {
  s21::set<int> s21set = {3, 1, 4, 7, 8, 9, 5, 6, 2};
  std::set<int> stdset = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  compare_s21_std_set(stdset, s21set);
}

TEST(set, simple4) {
  s21::set<int> s21set_orig = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  s21::set<int> s21set_target = s21set_orig;
  compare_s21_s21_set(s21set_target, s21set_orig);
}

TEST(set, simple5) {
  s21::set<int> s21set = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  std::set<int> stdset = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  s21set = s21set;
  compare_s21_std_set(stdset, s21set);
}

TEST(set, empty1) {
  s21::set<int> s21set = {};
  ASSERT_EQ(s21set.empty(), true);
}

TEST(set, empty2) {
  s21::set<int> s21set = {1};
  ASSERT_EQ(s21set.empty(), false);
}

TEST(set, clear) {
  s21::set<int> s21set = {1, 2, 3};
  s21set.clear();
  ASSERT_EQ(s21set.empty(), true);
}

TEST(set, max_size) {
  s21::set<int> s21set = {};
  std::set<int> stdset = {};
  std::cout << "s21 max_size: " << s21set.max_size() << std::endl
            << "std max_size: " << stdset.max_size() << std::endl;
  ASSERT_EQ(s21set.empty(), true);
}

TEST(set, swap) {
  s21::set<int> s21set_1 = {5, 3};
  s21::set<int> s21set_2 = {7, 8, 9};
  std::set<int> stdset_1 = {5, 3};
  std::set<int> stdset_2 = {7, 8, 9};
  stdset_1.swap(stdset_2);
  s21set_1.swap(s21set_2);
  compare_s21_std_set(stdset_1, s21set_1);
  compare_s21_std_set(stdset_2, s21set_2);
}

TEST(set, merge1) {
  s21::set<int> s21set_1 = {5, 3};
  s21::set<int> s21set_2 = {7, 8, 9};
  std::set<int> stdset = {5, 3, 7, 8, 9};
  s21set_1.merge(s21set_2);
  compare_s21_std_set(s21set_1, stdset);
}

TEST(set, merge2) {
  s21::set<int> s21set_1 = {5, 3};
  s21::set<int> s21set_2 = {7, 8, 9};
  std::set<int> stdset = {5, 3, 7, 8, 9};
  s21set_1.merge(s21set_2);
  compare_s21_std_set(s21set_1, stdset);
}

TEST(set, insert1) {
  s21::set<int> s21set_1 = {1};
  s21::set<int> s21set_2 = {};
  auto pair = s21set_2.insert(1);
  ASSERT_EQ(pair.second, true);
  ASSERT_EQ(*(pair.first), 1);
  pair = s21set_2.insert(1);
  ASSERT_EQ(pair.second, false);
  ASSERT_EQ(*(pair.first), 1);
  compare_s21_s21_set(s21set_1, s21set_2);
}

TEST(set, insert2) {
  s21::set<int> s21set_1 = {1, 2, 3, 4, 5, 6, 7};
  s21::set<int> s21set_2 = {2, 4, 7};
  s21set_2.insert(3);
  s21set_2.insert(4);
  s21set_2.insert(3);
  s21set_2.insert(2);
  s21set_2.insert(5);
  s21set_2.insert(7);
  s21set_2.insert(6);
  auto pair = s21set_2.insert(1);
  ASSERT_EQ(pair.second, true);
  ASSERT_EQ(*(pair.first), 1);
  pair = s21set_2.insert(1);
  ASSERT_EQ(pair.second, false);
  ASSERT_EQ(*(pair.first), 1);
  compare_s21_s21_set(s21set_1, s21set_2);
}

TEST(set, insert3) {
  std::set<int> s21set_1 = {0,  -100, 100, -50, 50, -25, 25, -12,
                            12, -6,   6,   -3,  3,  -1,  1};
  s21::set<int> s21set_2 = {};
  s21set_2.insert(0);
  s21set_2.insert(-100);
  s21set_2.insert(100);
  s21set_2.insert(-50);
  s21set_2.insert(50);
  s21set_2.insert(-25);
  s21set_2.insert(25);
  s21set_2.insert(-12);
  s21set_2.insert(12);
  s21set_2.insert(-6);
  s21set_2.insert(6);
  s21set_2.insert(-3);
  s21set_2.insert(3);
  s21set_2.insert(-1);
  s21set_2.insert(1);
  compare_s21_std_set(s21set_1, s21set_2);
}

TEST(set, insert4) {
  std::set<int> s21set_1 = {0, -100, 100, -50, 50, -75, 75};
  s21::set<int> s21set_2 = {};
  s21set_2.insert(0);
  s21set_2.insert(-100);
  s21set_2.insert(100);
  s21set_2.insert(-50);
  s21set_2.insert(50);
  s21set_2.insert(-75);
  s21set_2.insert(75);
  compare_s21_std_set(s21set_1, s21set_2);
}

TEST(set, erase1) {
  s21::set<int> s21set_1 = {};
  s21::set<int> s21set_2 = {1};
  s21set_2.erase(s21set_2.begin());
  compare_s21_s21_set(s21set_1, s21set_2);
}

TEST(set, erase2) {
  s21::set<int> s21set_1 = {};
  s21::set<int> s21set_2 = {};
  s21set_2.erase(s21set_2.begin());
  compare_s21_s21_set(s21set_1, s21set_2);
}

TEST(set, erase3) {
  std::set<int> stdset = {1, 2, 4, 5, 6};
  s21::set<int> s21set = {1, 2, 3, 4, 5, 6};
  auto i = s21set.begin();
  i++;
  i++;
  s21set.erase(i);
  compare_s21_std_set(stdset, s21set);
}

TEST(set, find1) {
  std::set<int> stdset = {0,  -100, 100, -50, 50, -25, 25, -12,
                          12, -6,   6,   -3,  3,  -1,  1};
  s21::set<int> s21set = {0,  -100, 100, -50, 50, -25, 25, -12,
                          12, -6,   6,   -3,  3,  -1,  1};
  ASSERT_EQ(*(stdset.find(-100)), *(s21set.find(-100)));
  ASSERT_EQ(*(stdset.find(50)), *(s21set.find(50)));
  ASSERT_EQ(*(stdset.find(-25)), *(s21set.find(-25)));
  ASSERT_EQ(*(stdset.find(12)), *(s21set.find(12)));
  ASSERT_EQ(*(stdset.find(-6)), *(s21set.find(-6)));
  ASSERT_EQ(*(stdset.find(3)), *(s21set.find(3)));
  ASSERT_EQ(*(stdset.find(-1)), *(s21set.find(-1)));
  ASSERT_EQ(*(stdset.find(0)), *(s21set.find(0)));
}

TEST(set, find2) {
  std::set<int> stdset = {0, -100, 100, -50, 50, -75, 75};
  s21::set<int> s21set = {0, -100, 100, -50, 50, -75, 75};
  ASSERT_EQ(*(stdset.find(-100)), *(s21set.find(-100)));
  ASSERT_EQ(*(stdset.find(50)), *(s21set.find(50)));
  ASSERT_EQ(*(stdset.find(-75)), *(s21set.find(-75)));
  ASSERT_EQ(*(stdset.find(0)), *(s21set.find(0)));
}

TEST(set, find3) {
  s21::set<int> s21set = {0, -100, 100, -50, 50, -75, 75};
  ASSERT_EQ(s21set.find(25) == s21set.end(), true);
  ASSERT_EQ(s21set.find(-25) == s21set.end(), true);
  ASSERT_EQ(s21set.find(10) == s21set.end(), true);
}

TEST(set, contains1) {
  s21::set<int> s21set = {0,  -100, 100, -50, 50, -25, 25, -12,
                          12, -6,   6,   -3,  3,  -1,  1};
  ASSERT_EQ(s21set.contains(-100), true);
  ASSERT_EQ(s21set.contains(100), true);
  ASSERT_EQ(s21set.contains(-50), true);
  ASSERT_EQ(s21set.contains(50), true);
  ASSERT_EQ(s21set.contains(-25), true);
  ASSERT_EQ(s21set.contains(25), true);
  ASSERT_EQ(s21set.contains(-12), true);
  ASSERT_EQ(s21set.contains(12), true);
  ASSERT_EQ(s21set.contains(-6), true);
  ASSERT_EQ(s21set.contains(6), true);
  ASSERT_EQ(s21set.contains(-3), true);
  ASSERT_EQ(s21set.contains(3), true);
  ASSERT_EQ(s21set.contains(-1), true);
  ASSERT_EQ(s21set.contains(1), true);
  ASSERT_EQ(s21set.contains(0), true);
}

TEST(set, contains2) {
  s21::set<int> s21set = {0, -100, 100, -50, 50, -75, 75};
  ASSERT_EQ(s21set.contains(-100), true);
  ASSERT_EQ(s21set.contains(100), true);
  ASSERT_EQ(s21set.contains(-50), true);
  ASSERT_EQ(s21set.contains(50), true);
  ASSERT_EQ(s21set.contains(-75), true);
  ASSERT_EQ(s21set.contains(75), true);
  ASSERT_EQ(s21set.contains(0), true);
}

TEST(set, contains3) {
  s21::set<int> s21set = {0, -100, 100, -50, 50, -75, 75};
  ASSERT_EQ(s21set.contains(0), true);
  ASSERT_EQ(s21set.contains(100), true);
  ASSERT_EQ(s21set.contains(-100), true);
  ASSERT_EQ(s21set.contains(11), false);
  ASSERT_EQ(s21set.contains(-1000), false);
  ASSERT_EQ(s21set.contains(1000), false);
}
