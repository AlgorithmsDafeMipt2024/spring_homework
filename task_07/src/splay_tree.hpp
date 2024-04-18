#pragma once
#include <cstddef>
#include <iostream>
#include <stdexcept>

#include "tree_node.hpp"

enum class ParentsType : char {
  no_parents,
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

  CustomType& operator[](Key key);
  void merge(SplayTree& tree);
  SplayTree split(Key key);
  void add(Key key, CustomType value);
  void remove(Key key);

  friend void in_order_depth_first_search(SplayTree<CustomType>& splaytree);

  Key rightest_key();

 private:
  enum class Direction : bool { left, right };

  TreeNode<std::pair<Key, CustomType>>* find(Key key);
  ParentsType parents_check(TreeNode<std::pair<Key, CustomType>>* x_node);

  void splay(Key key);

  void zig(TreeNode<std::pair<Key, CustomType>>* x_node, Direction direction);
  void zig_zig(TreeNode<std::pair<Key, CustomType>>* x_node,
               Direction direction);
  void zig_zag(TreeNode<std::pair<Key, CustomType>>* x_node,
               Direction direction);

  TreeNode<std::pair<Key, CustomType>>* tree_root;
};

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

template <constructable CustomType, comparable Key>
Key SplayTree<CustomType, Key>::rightest_key() {
  if (tree_root == nullptr) throw std::runtime_error("empty tree\n");
  TreeNode<std::pair<Key, CustomType>>* current_node = tree_root;
  while (current_node->right_child != nullptr)
    current_node = current_node->right_child;
  return current_node->value.first;
}

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

template <constructable CustomType, comparable Key>
void SplayTree<CustomType, Key>::zig_zag(
    TreeNode<std::pair<Key, CustomType>>* x_node, Direction direction) {
  if (direction == Direction::right) {
    zig(x_node, Direction::left);
    zig(x_node, Direction::right);
  }
  // else if for more explicit code
  else if (direction == Direction::left) {
    zig(x_node, Direction::right);
    zig(x_node, Direction::left);
  }
  if (x_node->is_root()) tree_root = x_node;
}

template <constructable CustomType, comparable Key>
ParentsType SplayTree<CustomType, Key>::parents_check(
    TreeNode<std::pair<Key, CustomType>>* x_node) {
  if (x_node == nullptr)
    throw std::runtime_error("x_node is a nullptr\n");
  else if (x_node->parent == nullptr)
    return ParentsType::no_parents;
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
      TreeNode<std::pair<Key, CustomType>>* parent_parent_node =
          parent_node->parent;
      if (parent_parent_node->left_child == parent_parent_node->right_child)
        throw std::runtime_error(
            "left and right children are the same node!?\n");
      if (parent_node->left_child == x_node) {
        if (parent_parent_node->left_child == parent_node)
          return ParentsType::right_right;
        // else if for more explicit code
        else if (parent_parent_node->right_child == parent_node)
          return ParentsType::right_left;
      }
      // else if for more explicit code
      else if (parent_node->right_child == x_node) {
        if (parent_parent_node->left_child == parent_node)
          return ParentsType::left_right;
        // else if for more explicit code
        else if (parent_parent_node->right_child == parent_node)
          return ParentsType::left_left;
      }
    }
  }
}

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
      default:
        break;
    }
  }
}

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

template <constructable CustomType, comparable Key>
SplayTree<CustomType, Key> SplayTree<CustomType, Key>::split(Key key) {
  splay(key);
  if (tree_root == nullptr) return SplayTree{nullptr};
  SplayTree right_tree;
  if (tree_root->value.first >= key) {
    SplayTree right_tree{tree_root};
    tree_root = tree_root->left_child;
    if (tree_root != nullptr) tree_root->parent = nullptr;
    right_tree.tree_root->left_child = nullptr;
  } else {
    SplayTree right_tree{tree_root->right_child};
    tree_root->right_child = nullptr;
    if (right_tree.tree_root != nullptr) right_tree.tree_root->parent = nullptr;
  }
  return right_tree;
}

template <constructable CustomType, comparable Key>
void SplayTree<CustomType, Key>::add(Key key, CustomType value) {
  if (tree_root == nullptr) {
    tree_root = new TreeNode<std::pair<Key, CustomType>>{{key, value}};
    return;
  }
  SplayTree right_tree = split(key);
  std::pair<Key, CustomType> init_value = {key, value};
  TreeNode<std::pair<Key, CustomType>>* new_root =
      new TreeNode<std::pair<Key, CustomType>>{tree_root, init_value,
                                               right_tree.tree_root};
  tree_root = new_root;
}

template <constructable CustomType, comparable Key>
void SplayTree<CustomType, Key>::remove(Key key) {
  TreeNode<std::pair<Key, CustomType>>* x_node = find(key);
  if (x_node->value.first != key)
    throw std::runtime_error("removing a non-existing element\n");
  splay(key);
  tree_root = x_node->left;
  tree_root->parent = nullptr;
  x_node->left = nullptr;
  SplayTree right_tree{x_node->right};
  x_node->right = nullptr;
  right_tree.tree_root->parent = nullptr;
  delete x_node;

  merge(right_tree);
}

template <constructable CustomType, comparable Key>
CustomType& SplayTree<CustomType, Key>::operator[](Key key) {
  TreeNode<std::pair<Key, CustomType>>* x_node = find(key);

  if ((x_node == nullptr) || (x_node->value.first != key))
    add(key, CustomType{});
  TreeNode<std::pair<Key, CustomType>>* value_node = find(key);

  return value_node->value.second;
}

template <printable CustomType, comparable Key>
void in_order_depth_first_search(
    SplayTree<CustomType, Key>& splaytree,
    TreeNode<std::pair<Key, CustomType>>* current_node) {
  if (current_node == nullptr) return;
  in_order_depth_first_search(splaytree, current_node->left_child);
  std::cout << current_node->value.second << ' ';
  in_order_depth_first_search(splaytree, current_node->right_child);
}