#ifndef MAP_H
#define MAP_H
#include <algorithm>
#include <cmath>

#include "binary_tree.hpp"

// #include <functional>
#include <iostream>
#include <memory>
#include <optional>
#include <string>

namespace s21 {

template <class Key, class Data>
class map {
 private:
  static Key const get_key(std::pair<Key const, Data> pair) {
    return pair.first;
  }

 private:
  using key_type = Key const;
  using value_type = std::pair<key_type, Data>;
  using reference = value_type &;
  using const_reference = value_type const &;
  using binary_tree = BinaryTree<value_type, key_type, map<Key, Data>::get_key>;
  using iterator = typename binary_tree::iterator;
  using const_iterator = typename binary_tree::const_iterator;
  using size_type = size_t;

 private:
  binary_tree tree = nullptr;

 public:
  // map(map *map) { this->tree = map->tree; }
  map() : tree{} {}

  map(std::initializer_list<value_type> const &items) : tree{items} {}

  map(const map &s) : tree{s.tree} {}

  map(map &&s) : tree{s.tree} {}

  map const &operator=(map &&s) {
    tree.clear();
    tree = s.tree;
    s.tree.clear();
    return *this;
  }

  map const &operator=(map const &other) {
    map<Key, Data> temp = other;
    tree.clear();
    for (auto i = temp.cbegin(); i != temp.cend(); i++) insert(*i);
    return *this;
  }

  Data &at(Key const &key) { return tree.find(key)->second; }

  Data &operator[](const Key &key) { return tree.find(key)->second; }

  iterator begin() { return iterator{tree.begin()}; }

  iterator end() { return iterator{tree.end()}; }

  const_iterator cbegin() const { return const_iterator{tree.cbegin()}; }

  const_iterator cend() const { return const_iterator{tree.cend()}; }

  bool empty() { return tree.empty(); }

  size_type size() { return tree.size(); }

  size_type max_size() { return tree.max_size(); }

  void clear() { tree.clear(); }

  std::pair<iterator, bool> insert(value_type const &key) {
    return tree.insert(key);
  }

  std::pair<iterator, bool> insert(const Key &key, const Data &obj) {
    return tree.insert(value_type(key, obj));
  }

  std::pair<iterator, bool> insert_or_assign(const Key &key, const Data &obj) {
    auto result = tree.insert(value_type(key, obj));
    if (!(result.second)) result.first->second = obj;
    return result;
  }

  bool erase(key_type const &key) { return tree.erase(key); }

  bool erase(iterator const &pos) { return tree.erase(pos); }

  bool erase(const_iterator const &pos) { return tree.erase(pos); }

  void swap(map &other) {
    auto temp = tree;
    tree = other.tree;
    other.tree = temp;
  }

  void merge(map &other) {
    for (auto i = other.begin(); i != other.end(); i++) insert(*i);
  }

  bool contains(Key const &key) { return tree.contains(key); }
};

}  // namespace s21

#endif