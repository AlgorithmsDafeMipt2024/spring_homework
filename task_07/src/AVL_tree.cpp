#include "AVL_tree.hpp"

void AVL_tree::push(int value) { root = insert(root, value); }

void AVL_tree::pop(int value) { root = remove(root, value); }

bool AVL_tree::contains(int value) {
  Node* node = find(root, value);
  if (node == nullptr) {
    return false;
  }
  if (node->value == value) {
    return true;
  }
  throw std::logic_error("contains: unreachable error");
}

unsigned int AVL_tree::height(Node* node) {
  if (node == nullptr) {
    return 0;
  }
  return node->height;
}

int AVL_tree::balance_coeff(Node* node) {
  return height(node->right) - height(node->left);
}

void AVL_tree::update_height(Node* node) {
  unsigned int height_l = height(node->left);
  unsigned int height_r = height(node->right);
  node->height = std::max(height_l, height_r) + 1;
}

AVL_tree::Node* AVL_tree::rotate_right(Node* node) {
  Node* l_node = node->left;
  node->left = l_node->right;
  l_node->right = node;
  update_height(node);
  update_height(l_node);
  return l_node;
}

AVL_tree::Node* AVL_tree::rotate_left(Node* node) {
  Node* r_node = node->right;
  node->right = r_node->left;
  r_node->left = node;
  update_height(node);
  update_height(r_node);
  return r_node;
}

AVL_tree::Node* AVL_tree::balance(Node* node) {
  update_height(node);
  if (balance_coeff(node) == 2) {
    if (balance_coeff(node->right) < 0) {
      node->right = rotate_right(node->right);
    }
    return rotate_left(node);
  }
  if (balance_coeff(node) == -2) {
    if (balance_coeff(node->left) > 0) {
      node->left = rotate_left(node->left);
    }
    return rotate_right(node);
  }
  return node;
}

AVL_tree::Node* AVL_tree::insert(Node* node, int val) {
  if (node == nullptr) {
    return new Node(val);
  }
  if (val < node->value) {
    node->left = insert(node->left, val);
  } else {
    node->right = insert(node->right, val);
  }
  return balance(node);
}

AVL_tree::Node* AVL_tree::find_min(Node* node) {
  if (node->left == nullptr) {
    return node;
  }
  return find_min(node->left);
}

AVL_tree::Node* AVL_tree::remove_min(Node* node) {
  if (node->left == nullptr) return node->right;
  node->left = remove_min(node->left);
  return balance(node);
}

AVL_tree::Node* AVL_tree::find(Node* node, int val) {
  if (node == nullptr) {
    return nullptr;
  }
  if (val < node->value) {
    return find(node->left, val);
  }
  if (val > node->value) {
    return find(node->right, val);
  }
  return node;
}

AVL_tree::Node* AVL_tree::remove(Node* node, int val) {
  if (node == nullptr) {
    return 0;
  }
  if (val < node->value) {
    node->left = remove(node->left, val);
    return balance(node);
  } else if (val > node->value) {
    node->right = remove(node->right, val);
    return balance(node);
  } else {
    Node* l_node = node->left;
    Node* r_node = node->right;
    delete node;

    if (r_node == nullptr) {
      return l_node;
    }
    Node* min_node = find_min(r_node);
    min_node->right = remove_min(r_node);
    min_node->left = l_node;
    return balance(min_node);
  }
}