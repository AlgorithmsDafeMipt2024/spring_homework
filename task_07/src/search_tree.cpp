#include "search_tree.hpp"

std::shared_ptr<Node> BinarySearchTree::Find(int value) const {
  std::shared_ptr<Node> node = root;

  while (node) {
    if (value == node->value) return node;
    if (value < node->value) node = node->left;
    if (value > node->value) node = node->right;
  }
  return nullptr;
}

void BinarySearchTree::Insert(int value) {
  std::shared_ptr<Node> parent = root;

  while (parent) {
    if (value <= parent->value) {
      if (!parent->left) {
        parent->left = std::make_shared<Node>(value, nullptr, nullptr, parent);
        break;
      } else
        parent = parent->left;
    } else {
      if (!parent->right) {
        parent->right = std::make_shared<Node>(value, nullptr, nullptr, parent);
        break;
      } else
        parent = parent->right;
    }
  }
}

void BinarySearchTree::Remove(int value) {
  std::shared_ptr<Node> deleted_node = Find(value);
  if (!deleted_node) return;

  std::shared_ptr<Node> max_left_node = deleted_node->left;
  while (max_left_node->right) max_left_node = max_left_node->right;

  max_left_node->left = deleted_node->left;
  max_left_node->right = deleted_node->right;
  max_left_node->parent->right = nullptr;

  std::shared_ptr<Node> parent_of_deleted = deleted_node->parent;
  max_left_node->parent = parent_of_deleted;

  if (parent_of_deleted->left == deleted_node)
    parent_of_deleted->left = max_left_node;
  else
    parent_of_deleted->right = max_left_node;
}