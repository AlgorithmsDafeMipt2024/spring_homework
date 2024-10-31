#include "avl_tree.hpp">

#include <algorithm>

AVLTree::~AVLTree() { Clear(root); }

void AVLTree::Clear(TreeNode *node) {
  if (node == nullptr) return;
  Clear(node->left);
  Clear(node->right);
  delete node;
}

int AVLTree::Height(TreeNode *node) const { return node ? node->height : 0; }

int AVLTree::BalanceFactor(TreeNode *node) const {
  return Height(node->left) - Height(node->right);
}

void AVLTree::Update(TreeNode *node) {
  if (node)
    node->height = std::max(Height(node->left), Height(node->right)) + 1;
}

TreeNode *AVLTree::RotateRight(TreeNode *old_node) {
  TreeNode *new_node = old_node->left;
  old_node->left = new_node->right;
  new_node->right = old_node;

  Update(old_node);
  Update(new_node);

  return new_node;
}

TreeNode *AVLTree::RotateLeft(TreeNode *old_node) {
  TreeNode *new_node = old_node->right;
  old_node->right = new_node->left;
  new_node->left = old_node;

  Update(old_node);
  Update(new_node);

  return new_node;
}

TreeNode *AVLTree::ReBalance(TreeNode *node) {
  int balance = BalanceFactor(node);
  if (balance > 1) {
    if (BalanceFactor(node->left) < 0) node->left = RotateLeft(node);
    return RotateRight(node);
  }
  if (balance < -1) {
    if (BalanceFactor(node->right) > 0) node->right = RotateRight(node);
    return RotateLeft(node);
  }
  return node;
}

TreeNode *AVLTree::SearchMin(TreeNode *node) {
  if (!node->left) return node;
  return SearchMin(node->left);
}

TreeNode *AVLTree::Insert(int value, TreeNode *&node) {
  if (!node) return new TreeNode(value);
  if (value < node->value)
    node->left = Insert(value, node->left);
  else if (value > node->value)
    node->right = Insert(value, node->right);
  else
    return node;
  Update(node);
  return ReBalance(node);
}
bool AVLTree::Find(int value, const TreeNode *node) const {
  if (!node) return false;
  if (value < node->value) return Find(value, node->left);
  if (value > node->value) return Find(value, node->right);
  return true;
}

TreeNode *AVLTree::Remove(int value, TreeNode *&node) {
  if (!node) return nullptr;
  if (value < node->value)
    node->left = Remove(value, node->left);
  else if (value > node->value)
    node->right = Remove(value, node->right);
  else {
    if (!node->left) return node->right;
    if (!node->right) return node->left;
    TreeNode *min_node = SearchMin(node->right);
    node->value = min_node->value;
    node->right = Remove(min_node->value, node->right);
  }
  Update(node);
  return ReBalance(node);
}

void AVLTree::Insert(int value) { root = Insert(value, root); }

void AVLTree::Remove(int value) { root = Remove(value, root); }

bool AVLTree::Find(int value) const { return Find(value, root); }
