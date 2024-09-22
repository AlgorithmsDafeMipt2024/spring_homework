#ifndef SET_H
#define SET_H
#include <algorithm>
#include <cmath>
#include <iostream>
#include <memory>
#include <optional>
#include <string>

#include "binary_tree.hpp"


namespace s21 {

template <class Key>
class set {
 private:
  static Key const get_key(Key const key) { return key; }

 private:
  using key_type = Key const;
  using value_type = Key const;
  using reference = value_type &;
  using const_reference = value_type const &;
  using binary_tree = BinaryTree<value_type, key_type, set<Key>::get_key>;
  using iterator = typename binary_tree::iterator;
  using const_iterator = typename binary_tree::const_iterator;
  using size_type = size_t;

 private:
  binary_tree tree = nullptr;

 public:
  set() : tree{} {}

  set(std::initializer_list<value_type> const &items) : tree{items} {}

  set(const set &s) : tree{s.tree} {}

  set(set &&s) : tree{s.tree} {}

  set const &operator=(set &&s) {
    tree.clear();
    tree = s.tree;
    s.tree.clear();
    return *this;
  }

  set const &operator=(set const &other) {
    set<Key> temp = other;
    tree.clear();
    for (auto i = temp.cbegin(); i != temp.cend(); i++) insert(*i);
    return *this;
  }

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

  bool erase(key_type const &key) { return tree.erase(key); }

  bool erase(iterator const &pos) { return tree.erase(pos); }

  bool erase(const_iterator const &pos) { return tree.erase(pos); }

  void swap(set &other) {
    auto temp = tree;
    tree = other.tree;
    other.tree = temp;
  }

  void merge(set &other) {
    for (auto i = other.begin(); i != other.end(); i++) insert(*i);
  }

  iterator find(key_type const &key) { return tree.find(key); }

  bool contains(key_type const &key) { return tree.contains(key); }
};

}  // namespace s21

#endif