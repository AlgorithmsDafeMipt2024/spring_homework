#ifndef BINARY_TREE_H
#define BINARY_TREE_H
#include <memory>

#include "node.hpp"
namespace s21 {
template <class Value, class Key, Key (*get_key)(Value)>
class BinaryTree {
 public:
  class iterator;
  class const_iterator;

 private:
  using key_type = Key;
  using value_type = Value;
  using node = Node<value_type, key_type, get_key>;

  std::shared_ptr<node> root = nullptr;

 public:
  BinaryTree(std::initializer_list<value_type> const &items) {
    for (auto item : items) node::add(root, item);
  }

  BinaryTree() : root{} {}

  BinaryTree(BinaryTree const &other) : root{} {
    for (auto i = other.cbegin(); i != other.cend(); i++) node::add(root, *i);
  }

  BinaryTree(BinaryTree &&other) : root{other.root} { other.root.reset(); }

  ~BinaryTree() = default;

  BinaryTree const &operator=(BinaryTree &&other) {
    // root.reset(); // leacks possible
    root = other.root;
    other.root.reset();
    return *this;
  }

  BinaryTree const &operator=(BinaryTree const &other) {
    BinaryTree temp = other;
    clear();
    for (auto i = temp.cbegin(); i != temp.cend(); i++) insert(*i);
    return *this;
  }

  iterator begin() { return iterator{node::begin(root, this)}; }

  iterator end() { return iterator{node::end(root, this)}; }

  const_iterator cbegin() const {
    return const_iterator{node::cbegin(root, this)};
  }

  const_iterator cend() const { return const_iterator{node::cend(root, this)}; }

  bool empty() const { return !root; }

  size_t size() const { return node::size(root); }

  size_t max_size() {
    std::allocator<char> alloc;
    return alloc.max_size() / sizeof(node);
  }

  void clear() { root.reset(); }

  std::pair<iterator, bool> insert(value_type const &key) {
    return node::add(root, key, this);
  }

  bool erase(key_type const &key) { return bool(node::remove(root, key)); }

  bool erase(iterator const &pos) {
    return bool(node::remove(root, pos.__M_iter, this));
  }

  bool erase(const_iterator const &pos) {
    return bool(node::remove(root, pos.__M_const_iter, this));
  }

  iterator find(key_type const &key) { return node::find(root, key, this); }

  bool contains(key_type const &key) const { return node::exists(root, key); }
};

template <class Value, class Key, Key (*get_key)(Value)>
class BinaryTree<Value, Key, get_key>::iterator {
 private:
  using node = Node<Value, Key, get_key>;
  using NodeIterator = typename node::NodeIterator;

 public:
  NodeIterator __M_iter;

  iterator() = delete;
  iterator(NodeIterator const &__M_iter) { this->__M_iter = __M_iter; }
  iterator(iterator const &other) { this->__M_iter = other.__M_iter; }

  iterator operator++() {
    ++__M_iter;
    return *this;
  }
  iterator operator--() {
    --__M_iter;
    return *this;
  }
  iterator operator++(int) {
    __M_iter++;
    return *this;
  }
  iterator operator--(int) {
    __M_iter--;
    return *this;
  }
  bool operator==(iterator other) { return __M_iter == other.__M_iter; }
  bool operator!=(iterator other) { return __M_iter != other.__M_iter; }
  Value &operator*() { return *__M_iter; }
  Value *operator->() { return __M_iter.operator->(); }
};

template <class Value, class Key, Key (*get_key)(Value)>
class BinaryTree<Value, Key, get_key>::const_iterator {
 private:
  using node = Node<Value, Key, get_key>;
  using ConstNodeIterator = typename node::ConstNodeIterator;

 public:
  ConstNodeIterator __M_const_iter;
  const_iterator() = delete;
  const_iterator(ConstNodeIterator const &__M_const_iter) {
    this->__M_const_iter = __M_const_iter;
  }
  const_iterator(const_iterator const &other) {
    this->__M_const_iter = other.__M_const_iter;
  }

  const_iterator operator++() {
    ++__M_const_iter;
    return *this;
  }
  const_iterator operator--() {
    --__M_const_iter;
    return *this;
  }
  const_iterator operator++(int) {
    __M_const_iter++;
    return *this;
  }
  const_iterator operator--(int) {
    __M_const_iter--;
    return *this;
  }
  bool operator==(const_iterator other) {
    return __M_const_iter == other.__M_const_iter;
  }
  bool operator!=(const_iterator other) {
    return __M_const_iter != other.__M_const_iter;
  }
  Value const &operator*() { return *__M_const_iter; }
  Value const *operator->() { return __M_const_iter.operator->(); }
};

}  // namespace s21
#endif