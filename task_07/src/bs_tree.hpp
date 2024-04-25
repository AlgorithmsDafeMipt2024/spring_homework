#pragma once
#include <memory>

template <typename T>
class BSTree {
 public:
  // Constructor to initialize the tree with a nullptr root
  BSTree() : root(nullptr) {}

  // Public methods for insertion, checking containment, and removal
  void Insert(T value);
  bool Contains(T value) const;
  void Remove(T value);

 private:
  // Node structure for the binary search tree
  struct BSTNode {
    T value;
    std::unique_ptr<BSTNode> left;
    std::unique_ptr<BSTNode> right;

    // Node constructor to set the value, left, and right pointers to nullptr
    explicit BSTNode(T value) : value(value), left(nullptr), right(nullptr) {}
  };

  std::unique_ptr<BSTNode> root;  // Root of the binary search tree

  // Private method to find the minimum node in a subtree starting from the
  // given node
  std::unique_ptr<BSTNode> &SearchMin(std::unique_ptr<BSTNode> &node) const;

  // Private method to check containment recursively in a subtree starting from
  // the given node
  bool Contains(T value, const std::unique_ptr<BSTNode> &node) const;

  // Private method to insert a value recursively in the binary search tree
  // starting from the given node
  void Insert(T value, std::unique_ptr<BSTNode> &node);

  // Private method to remove a value recursively from the binary search tree
  // starting from the given node
  void Remove(T value, std::unique_ptr<BSTNode> &node);
};

// Public method to insert a value into the binary search tree
template <typename T>
void BSTree<T>::Insert(T value) {
  Insert(value, root);
}

// Private method to insert a value recursively into the binary search tree
template <typename T>
void BSTree<T>::Insert(T value, std::unique_ptr<BSTNode> &node) {
  if (!node) {
    node = std::make_unique<BSTNode>(value);
    return;
  }
  if (value <= node->value) Insert(value, node->left);
  if (value > node->value) Insert(value, node->right);
}

// Public method to check if a value is contained in the binary search tree
template <typename T>
bool BSTree<T>::Contains(T value) const {
  return Contains(value, root);
}

// Private method to check if a value is contained in a subtree starting from
// the given node
template <typename T>
bool BSTree<T>::Contains(T value, const std::unique_ptr<BSTNode> &node) const {
  if (!node) return false;
  if (value < node->value) return Contains(value, node->left);
  if (value > node->value) return Contains(value, node->right);
  return true;
}

// Public method to remove a value from the binary search tree
template <typename T>
void BSTree<T>::Remove(T value) {
  Remove(value, root);
}

// Private method to remove a value recursively from the binary search tree
// starting from the given node
template <typename T>
void BSTree<T>::Remove(T value, std::unique_ptr<BSTNode> &node) {
  if (!node) return;
  if (value == node->value) {
    if (!node->left && !node->right) {
      node = nullptr;
      return;
    }
    if (node->left && !node->right) {
      node = std::move(node->left);
      return;
    }
    if (!node->left && node->right) {
      node = std::move(node->right);
      return;
    }
    std::unique_ptr<BSTNode> &minNode = SearchMin(node->right);
    node->value = minNode->value;
    Remove(minNode->value, minNode);
    return;
  }
  if (value < node->value) {
    Remove(value, node->left);
    return;
  }
  if (value > node->value) {
    Remove(value, node->right);
    return;
  }
}

// Private method to find the minimum node in a subtree starting from the given
// node
template <typename T>
std::unique_ptr<typename BSTree<T>::BSTNode> &BSTree<T>::SearchMin(
    std::unique_ptr<BSTNode> &node) const {
  if (!node->left) return node;
  return SearchMin(node->left);
}