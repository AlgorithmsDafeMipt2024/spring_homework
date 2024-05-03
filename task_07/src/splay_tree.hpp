#pragma once
#include <cstddef>
#include <initializer_list>
#include <iostream>
#include <queue>
#include <stdexcept>
#include <vector>

#include "tree_node.hpp"

enum class ParentsType : char {
  orphan,
  left,
  right,
  left_left,
  right_right,
  left_right,
  right_left
};

template <typename Key>
concept comparable = requires(Key a, Key b) {
  a < b;
  a <= b;
  a == b;
  a >= b;
  a > b;
  a != b;
};

template <typename CustomType>
concept printable = requires(CustomType a) {
  std::cout << a;
};

template <constructable CustomType, comparable Key = int>
class SplayTree {
 public:
  SplayTree() : tree_root{nullptr} {}
  SplayTree(TreeNode<std::pair<Key, CustomType>>* tree_root_)
      : tree_root{tree_root_} {}
  // time complexity - O(nlogn)
  explicit SplayTree(
      std::initializer_list<std::pair<Key, CustomType>> init_list);

  // time complexity - O(logn)
  CustomType& operator[](Key key);
  // time complexity - O(logn)
  void merge(SplayTree& tree);
  // time complexity - O(logn)
  SplayTree split(Key key);
  // time complexity - O(logn)
  void add(Key key, CustomType value);
  // time complexity - O(logn)
  void remove(Key key);
  // time complexity - O(1)
  TreeNode<std::pair<Key, CustomType>>* root() { return tree_root; }
  // time complexity - O(logn)
  Key rightest_key();

 private:
  enum class Direction : bool { left, right };

  // time complexity - O(logn)
  TreeNode<std::pair<Key, CustomType>>* find(Key key);
  // time complexity - O(1)
  ParentsType parents_check(TreeNode<std::pair<Key, CustomType>>* x_node);

  // time complexity - O(logn)
  void splay(Key key);

  // time complexity - O(1)
  void zig(TreeNode<std::pair<Key, CustomType>>* x_node, Direction direction);

  // time complexity - O(1)
  void zig_zig(TreeNode<std::pair<Key, CustomType>>* x_node,
               Direction direction);

  // time complexity - O(1)
  void zig_zag(TreeNode<std::pair<Key, CustomType>>* x_node,
               Direction direction);

  TreeNode<std::pair<Key, CustomType>>* tree_root;
};

// time complexity - O(logn)
template <constructable CustomType, comparable Key>
TreeNode<std::pair<Key, CustomType>>* SplayTree<CustomType, Key>::find(
    Key key) {
  if (tree_root == nullptr) return nullptr;

  TreeNode<std::pair<Key, CustomType>>* current_node = tree_root;
  for (;;) {
    if (key == current_node->value.first)
      return current_node;
    else if (key > current_node->value.first) {
      if (current_node->right_child == nullptr) return current_node;

      current_node = current_node->right_child;
    }
    // else if for more explicit code
    else if (key < current_node->value.first) {
      if (current_node->left_child == nullptr) return current_node;

      current_node = current_node->left_child;
    }
  }
}

// time complexity - O(nlogn)
template <constructable CustomType, comparable Key>
SplayTree<CustomType, Key>::SplayTree(
    std::initializer_list<std::pair<Key, CustomType>> init_list) {
  for (const std::pair<Key, CustomType>& pair : init_list)
    add(pair.first, pair.second);
}

// time complexity - O(logn)
template <constructable CustomType, comparable Key>
Key SplayTree<CustomType, Key>::rightest_key() {
  if (tree_root == nullptr) throw std::runtime_error("empty tree\n");
  TreeNode<std::pair<Key, CustomType>>* current_node = tree_root;

  while (current_node->right_child != nullptr)
    current_node = current_node->right_child;

  return current_node->value.first;
}

// time complexity - O(1)
template <constructable CustomType, comparable Key>
void SplayTree<CustomType, Key>::zig(
    TreeNode<std::pair<Key, CustomType>>* x_node, Direction direction) {
  TreeNode<std::pair<Key, CustomType>>* parent_node = x_node->parent;
  TreeNode<std::pair<Key, CustomType>>* parent_of_a_parent =
      parent_node->parent;

  if (direction == Direction::right) {
    TreeNode<std::pair<Key, CustomType>>* x_right_node = x_node->right_child;

    parent_node->left_child = x_right_node;
    if (x_right_node != nullptr) x_right_node->parent = parent_node;
    x_node->right_child = parent_node;
    parent_node->parent = x_node;
  }
  // else if for more explicit code
  else if (direction == Direction::left) {
    TreeNode<std::pair<Key, CustomType>>* x_left_node = x_node->left_child;

    parent_node->right_child = x_left_node;
    if (x_left_node != nullptr) x_left_node->parent = parent_node;
    x_node->left_child = parent_node;
    parent_node->parent = x_node;
  }

  x_node->parent = parent_of_a_parent;
  if (x_node->is_root()) tree_root = x_node;
}

// time complexity - O(1)
template <constructable CustomType, comparable Key>
void SplayTree<CustomType, Key>::zig_zig(
    TreeNode<std::pair<Key, CustomType>>* x_node, Direction direction) {
  if (direction == Direction::right) {
    zig(x_node->parent, Direction::right);
    zig(x_node, Direction::right);
  }
  // else if for more explicit code
  else if (direction == Direction::left) {
    zig(x_node->parent, Direction::left);
    zig(x_node, Direction::left);
  }
  if (x_node->is_root()) tree_root = x_node;
}

// time complexity - O(1)
template <constructable CustomType, comparable Key>
void SplayTree<CustomType, Key>::zig_zag(
    TreeNode<std::pair<Key, CustomType>>* x_node, Direction direction) {
  if (direction == Direction::right) {
    zig(x_node, Direction::right);
    zig(x_node, Direction::left);
  }
  // else if for more explicit code
  else if (direction == Direction::left) {
    zig(x_node, Direction::left);
    zig(x_node, Direction::right);
  }
  if (x_node->is_root()) tree_root = x_node;
}

// time complexity - O(1)
template <constructable CustomType, comparable Key>
ParentsType SplayTree<CustomType, Key>::parents_check(
    TreeNode<std::pair<Key, CustomType>>* x_node) {
  if (x_node == nullptr)
    throw std::runtime_error("x_node is a nullptr\n");
  else if (x_node->parent == nullptr)
    return ParentsType::orphan;
  else if (x_node->parent != nullptr) {
    TreeNode<std::pair<Key, CustomType>>* parent_node = x_node->parent;
    if (parent_node->parent == nullptr) {
      if (parent_node->left_child == parent_node->right_child)
        throw std::runtime_error(
            "left and right children are the same node!?\n");
      else if (parent_node->left_child == x_node)
        return ParentsType::right;
      // else if for more explicit code
      else if (parent_node->right_child == x_node)
        return ParentsType::left;
    } else {
      if (parent_node->parent->left_child == parent_node->parent->right_child)
        throw std::runtime_error(
            "left and right children are the same node!?\n");
      if (parent_node->left_child == x_node) {
        if (parent_node->parent->left_child == parent_node)
          return ParentsType::right_right;
        // else if for more explicit code
        else if (parent_node->parent->right_child == parent_node)
          return ParentsType::right_left;
      }
      // else if for more explicit code
      else if (parent_node->right_child == x_node) {
        if (parent_node->parent->left_child == parent_node)
          return ParentsType::left_right;
        // else if for more explicit code
        else if (parent_node->parent->right_child == parent_node)
          return ParentsType::left_left;
      }
    }
  }
  throw std::runtime_error(
      "got throw all else if blocks but haven't found a match\n");
}

// time complexity - O(logn)
template <constructable CustomType, comparable Key>
void SplayTree<CustomType, Key>::splay(Key key) {
  if (tree_root == nullptr) return;

  TreeNode<std::pair<Key, CustomType>>* x_node = find(key);

  while (!x_node->is_root()) {
    ParentsType parents_type = parents_check(x_node);

    switch (parents_type) {
      case ParentsType::left:
        zig(x_node, Direction::left);
        break;
      case ParentsType::right:
        zig(x_node, Direction::right);
        break;
      case ParentsType::left_left:
        zig_zig(x_node, Direction::left);
        break;
      case ParentsType::right_right:
        zig_zig(x_node, Direction::right);
        break;
      case ParentsType::left_right:
        zig_zag(x_node, Direction::left);
        break;
      case ParentsType::right_left:
        zig_zag(x_node, Direction::right);
        break;
      case ParentsType::orphan:
        break;
    }
  }
}

// time complexity - O(logn)
template <constructable CustomType, comparable Key>
void SplayTree<CustomType, Key>::merge(SplayTree<CustomType, Key>& tree) {
  if (tree_root == nullptr) {
    tree_root = tree.tree_root;
    return;
  } else if (tree.tree_root == nullptr)
    return;
  splay(rightest_key());
  tree_root->right_child = tree.tree_root;
  tree.tree_root->parent = tree_root;
}

// time complexity - O(logn)
template <constructable CustomType, comparable Key>
SplayTree<CustomType, Key> SplayTree<CustomType, Key>::split(Key key) {
  splay(key);
  if (tree_root == nullptr) return SplayTree{nullptr};
  if (find(key) != tree_root)
    throw std::runtime_error("key is not root after splaying");

  if (tree_root->value.first >= key) {
    SplayTree right_tree{tree_root};
    tree_root = tree_root->left_child;

    if (tree_root != nullptr) tree_root->parent = nullptr;
    right_tree.tree_root->left_child = nullptr;
    return right_tree;
  } else {
    SplayTree right_tree{tree_root->right_child};

    tree_root->right_child = nullptr;
    if (right_tree.tree_root != nullptr) right_tree.tree_root->parent = nullptr;
    return right_tree;
  }
}

// time complexity - O(logn)
template <constructable CustomType, comparable Key>
void SplayTree<CustomType, Key>::add(Key key, CustomType value) {
  SplayTree right_tree = split(key);

  TreeNode<std::pair<Key, CustomType>>* new_root =
      new TreeNode<std::pair<Key, CustomType>>{
          tree_root, {key, value}, right_tree.tree_root};

  tree_root = new_root;
}

// time complexity - O(logn)
template <constructable CustomType, comparable Key>
void SplayTree<CustomType, Key>::remove(Key key) {
  TreeNode<std::pair<Key, CustomType>>* x_node = find(key);
  if (x_node->value.first != key)
    throw std::runtime_error("removing a non-existing element\n");

  splay(key);
  x_node = tree_root;
  tree_root = x_node->left_child;
  if (tree_root != nullptr) tree_root->parent = nullptr;

  x_node->left_child = nullptr;
  SplayTree right_tree{x_node->right_child};
  x_node->right_child = nullptr;
  if (right_tree.tree_root != nullptr) right_tree.tree_root->parent = nullptr;

  delete x_node;

  merge(right_tree);
}

// time complexity - O(logn)
template <constructable CustomType, comparable Key>
CustomType& SplayTree<CustomType, Key>::operator[](Key key) {
  TreeNode<std::pair<Key, CustomType>>* x_node = find(key);

  if ((x_node == nullptr) || (x_node->value.first != key))
    add(key, CustomType{});
  TreeNode<std::pair<Key, CustomType>>* value_node = find(key);

  return value_node->value.second;
}

// time complexity - O(n)
template <constructable CustomType, comparable Key>
void in_order_DFS(TreeNode<std::pair<Key, CustomType>>* current_node,
                  std::vector<CustomType>& data_vector) {
  if (current_node == nullptr) return;
  if (current_node->parent == nullptr && !data_vector.empty())
    throw std::runtime_error("data_vector is not empty\n");

  in_order_DFS(current_node->left_child, data_vector);
  data_vector.push_back(current_node->value.second);
  in_order_DFS(current_node->right_child, data_vector);
}