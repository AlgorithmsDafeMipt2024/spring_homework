#pragma once
#include <algorithm>
#include <memory>

template <typename T>
class AVLTree {
 public:
  AVLTree() : root(nullptr) {}

  void Insert(T value);

  bool Contains(T value) const;

  void Remove(T value);

 private:
  struct AVLNode {
    T value;
    size_t height;
    std::unique_ptr<AVLNode> left;
    std::unique_ptr<AVLNode> right;

    explicit AVLNode(T value)
        : value(value), left(nullptr), right(nullptr), height(1) {}
  };

  std::unique_ptr<AVLNode> root;

  size_t Height(const std::unique_ptr<AVLNode> &node) const;

  int BalanceFactor(const std::unique_ptr<AVLNode> &node) const;

  void UpdateHeight(std::unique_ptr<AVLNode> &node);

  std::unique_ptr<AVLNode> RotateRight(std::unique_ptr<AVLNode> &original_node);

  std::unique_ptr<AVLNode> RotateLeft(std::unique_ptr<AVLNode> &original_node);

  std::unique_ptr<AVLNode> ReBalance(std::unique_ptr<AVLNode> &node);

  std::unique_ptr<AVLNode> SearchMin(std::unique_ptr<AVLNode> &node);

  std::unique_ptr<AVLNode> Insert(T value, std::unique_ptr<AVLNode> &node);

  std::unique_ptr<AVLNode> Remove(T value, std::unique_ptr<AVLNode> &node);

  bool Contains(T value, const std::unique_ptr<AVLNode> &node) const;
};

template <typename T>
size_t AVLTree<T>::Height(const std::unique_ptr<AVLNode> &node) const {
  return node ? node->height : 0;
}

template <typename T>
int AVLTree<T>::BalanceFactor(const std::unique_ptr<AVLNode> &node) const {
  return Height(node->left) - Height(node->right);
}

template <typename T>
void AVLTree<T>::UpdateHeight(std::unique_ptr<AVLNode> &node) {
  if (node)
    node->height = std::max(Height(node->left), Height(node->right)) + 1;
}

template <typename T>
std::unique_ptr<struct AVLTree<T>::AVLNode> AVLTree<T>::RotateRight(
    std::unique_ptr<AVLNode> &original_node) {
  std::unique_ptr<AVLNode> new_node = std::move(original_node->left);
  original_node->left = std::move(new_node->right);
  new_node->right = std::move(original_node);

  UpdateHeight(original_node);
  UpdateHeight(new_node);

  return new_node;

}

template <typename T>
std::unique_ptr<struct AVLTree<T>::AVLNode> AVLTree<T>::RotateLeft(
    std::unique_ptr<AVLNode> &original_node) {
  std::unique_ptr<AVLNode> new_node = std::move(original_node->right);
  original_node->right = std::move(new_node->left);
  new_node->left = std::move(original_node);

  UpdateHeight(original_node);
  UpdateHeight(new_node);

  return new_node;
}

template <typename T>
std::unique_ptr<struct AVLTree<T>::AVLNode> AVLTree<T>::ReBalance(
    std::unique_ptr<AVLNode> &node) {
  int balance = BalanceFactor(node);
  if (balance > 1) {
    if (BalanceFactor(node->left) < 0) node->left = RotateLeft(node);
    return RotateRight(node);
  }
  if (balance < -1) {
    if (BalanceFactor(node->right) > 0) node->right = RotateRight(node);
    return RotateLeft(node);
  }
  return std::move(node);
}

template <typename T>
std::unique_ptr<struct AVLTree<T>::AVLNode> AVLTree<T>::SearchMin(
    std::unique_ptr<AVLNode> &node) {
  if (!node->left) return std::move(node);
  return SearchMin(node->left);
}

template <typename T>
std::unique_ptr<struct AVLTree<T>::AVLNode> AVLTree<T>::Insert(
    T value, std::unique_ptr<AVLNode> &node) {
  if (!node) return std::make_unique<AVLNode>(value);
  if (value < node->value)
    node->left = Insert(value, node->left);
  else if (value > node->value)
    node->right = Insert(value, node->right);
  else
    return std::move(node);
  UpdateHeight(node);
  return ReBalance(node);
}

template <typename T>
bool AVLTree<T>::Contains(T value, const std::unique_ptr<AVLNode> &node) const {
  if (!node) return false;
  if (value < node->value) return Contains(value, node->left);
  if (value > node->value) return Contains(value, node->right);
  return true;
}

template <typename T>
std::unique_ptr<struct AVLTree<T>::AVLNode> AVLTree<T>::Remove(
    T value, std::unique_ptr<AVLNode> &node) {
  if (!node) return nullptr;
  if (value < node->value)
    node->left = Remove(value, node->left);
  else if (value > node->value)
    node->right = Remove(value, node->right);
  else {
    if (!node->left) return std::move(node->right);
    if (!node->right) return std::move(node->left);
    std::unique_ptr<AVLNode> min_node = SearchMin(node->right);
    node->value = min_node->value;
    node->right = Remove(min_node->value, node->right);
  }
  UpdateHeight(node);
  return ReBalance(node);

}

template <typename T>
void AVLTree<T>::Insert(T value) {
  root = Insert(value, root);
}

template <typename T>
void AVLTree<T>::Remove(T value) {
  root = Remove(value, root);
}

template <typename T>
bool AVLTree<T>::Contains(const T value) const {
  return Contains(value, root);
}