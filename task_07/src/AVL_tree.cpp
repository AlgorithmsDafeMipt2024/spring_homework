#include "AVL_tree.hpp"

#include <algorithm>
#include <stdexcept>

void AVL_Tree::Insert(int value) { root_ = Insert(root_, value); }
void AVL_Tree::Remove(int value) { root_ = Remove(root_, value); }
bool AVL_Tree::Contains(int value) const { return Contains(root_, value); }

Node* AVL_Tree::Insert(Node* root, int value) {
  if (!root) return new Node(value);
  if (value < root->key)
    root->left = Insert(root->left, value);
  else
    root->right = Insert(root->right, value);
  return Balance(root);
}

Node* AVL_Tree::Remove(Node* root, int value) {
  if (!root) return 0;
  if (value < root->key)
    root->left = Remove(root->left, value);
  else if (value > root->key)
    root->right = Remove(root->right, value);
  else if (value == root->key) {
    Node* new_node_1 = root->left;
    Node* new_node_2 = root->right;
    delete root;
    if (!new_node_2) return new_node_1;
    Node* min = FindMin(new_node_2);
    min->right = RemoveMin(new_node_2);
    min->left = new_node_1;
    return Balance(min);
  } else {
    throw std::runtime_error("AVL_Tree does not contain this element");
  }
  return Balance(root);
}

bool AVL_Tree::Contains(Node* node, int value) const {
  if (!node) return false;
  if (value < node->key) return Contains(node->left, value);
  if (value > node->key) return Contains(node->right, value);
  return true;
}

Node* AVL_Tree::FindMin(Node* root) const {
  return root->left ? FindMin(root->left) : root;
}

Node* AVL_Tree::RemoveMin(Node* root) {
  if (!root->left) return root->right;
  root->left = RemoveMin(root->left);
  return Balance(root);
}

Node* AVL_Tree::Balance(Node* node) {
  FixHeight(node);
  if (Difference(node) == 2) {
    if (Difference(node->right) < 0) node->right = RightRotate(node->right);
    return LeftRotate(node);
  }
  if (Difference(node) == -2) {
    if (Difference(node->left) > 0) node->left = LeftRotate(node->left);
    return RightRotate(node);
  }
  return node;
}

Node* AVL_Tree::RightRotate(Node* node) {
  Node* new_node = node->left;
  node->left = new_node->right;
  new_node->right = node;
  FixHeight(node);
  FixHeight(new_node);
  return new_node;
}

Node* AVL_Tree::LeftRotate(Node* node) {
  Node* new_node = node->right;
  node->right = new_node->left;
  new_node->left = node;
  FixHeight(node);
  FixHeight(new_node);
  return new_node;
}

unsigned AVL_Tree::Height(Node* node) const { return node ? node->height : 0; }

int AVL_Tree::Difference(Node* node) const {
  return Height(node->right) - Height(node->left);
}

void AVL_Tree::FixHeight(Node* node) {
  unsigned left_height = Height(node->left);
  unsigned right_height = Height(node->right);
  node->height = std::max(left_height, right_height) + 1;
}