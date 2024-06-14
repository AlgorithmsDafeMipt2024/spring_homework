#include "AVL_Tree.hpp"

unsigned char AVL_Tree::Height(Node *p) { return p ? p->height : 0; }

int AVL_Tree::DifferenceH(Node *p) {
  return Height(p->right) - Height(p->left);
}

void AVL_Tree::Fixheight(Node *p) {
  unsigned char height_l = Height(p->left);
  unsigned char height_r = Height(p->right);
  p->height = (height_l > height_r ? height_l : height_r) + 1;
}

Node *AVL_Tree::Insert(Node *root, int k) {
  if (root == nullptr) {
    return new Node(k);
  } else if (root->key < k) {
    root->right = Insert(root->right, k);
  } else {
    root->left = Insert(root->left, k);
  }
  return Balance(root);
}

Node *AVL_Tree::RotateRight(Node *p) {
  Node *q = p->left;
  p->left = q->right;
  q->right = p;
  Fixheight(p);
  Fixheight(q);
  return q;
}

Node *AVL_Tree::Rotateleft(Node *q) {
  Node *p = q->right;
  q->right = p->left;
  p->left = q;
  Fixheight(q);
  Fixheight(p);
  return p;
}
Node *AVL_Tree::Balance(Node *p) {
  Fixheight(p);
  if (DifferenceH(p) == 2) {
    if (DifferenceH(p->right) < 0) {
      p->right = RotateRight(p->right);
    }
    return Rotateleft(p);
  }

  if (DifferenceH(p) == -2) {
    if (DifferenceH(p->left) > 0) {
      p->left = Rotateleft(p->left);
    }
    return RotateRight(p);
  }
  return p;
}

Node *AVL_Tree::Findmin(Node *right_subtree) {
  return right_subtree->left ? Findmin(right_subtree->left) : right_subtree;
}

Node *AVL_Tree::Removemin(Node *p) {
  if (p->left == nullptr) return p->right;
  p->left = Removemin(p->left);
  return p;
}

Node *AVL_Tree::Remove(Node *p, int k) {
  if (!p) return nullptr;
  if (k < p->key) {
    p->left = Remove(p->left, k);
  } else if (k > p->key) {
    p->right = Remove(p->right, k);
  } else {
    Node *p_left = p->left;
    Node *p_right = p->right;
    delete p;
    if (!p_right) return p_left;
    Node *min = Findmin(p_right);
    min->right = Removemin(p_right);
    min->left = p_left;
    return Balance(min);
  }
  return Balance(p);
}

bool AVL_Tree::Contains(Node *node, int value) {
  if (!node) return false;
  if (value < node->key) {
    return Contains(node->left, value);
  }
  if (value > node->key) {
    return Contains(node->right, value);
  }
  return true;
}

void AVL_Tree::Insert(int value) { root = Insert(root, value); }

void AVL_Tree::Remove(int value) { root = Remove(root, value); }

bool AVL_Tree::Contains(int value) { return Contains(root, value); }