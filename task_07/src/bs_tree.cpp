#include "bs_tree.hpp"

template <typename T>
void BSTree<T>::Insert(T value) {
  Insert(value, root);
}

template <typename T>
void BSTree<T>::Insert(T value, std::unique_ptr<BSTNode> &node) {
  if (!node) {
    node = std::make_unique<BSTNode>(value);
    return;
  }
  if (value <= node->value) Insert(value, node->left);
  if (value > node->value) Insert(value, node->right);
}

template <typename T>
bool BSTree<T>::Contains(T value, const std::unique_ptr<BSTNode> &node) const {
  if (!node) return false;
  if (value < node->value) return Contains(value, node->left);
  if (value > node->value) return Contains(value, node->right);
  return true;
}

template <typename T>
bool BSTree<T>::Contains(T value) const {
  return Contains(value, root);
}

template <typename T>
void BSTree<T>::Remove(T value) {
  Remove(value, root);
}

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
  if (value < node->value) {
    Remove(value, node->right);
    return;
  }
}

template <typename T>
std::unique_ptr<typename BSTree<T>::BSTNode> &BSTree<T>::SearchMin(
    std::unique_ptr<BSTNode> &node) {
  if (node->left == nullptr) return node;
  return SearchMin(node->left);
}
