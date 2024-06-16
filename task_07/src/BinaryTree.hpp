#include <iostream>
#include <vector>

template <class T>
struct Node {
  Node(T value) : data(value), left_ptr(nullptr), right_ptr(nullptr) {}
  T data;
  Node* left_ptr;
  Node* right_ptr;
  int height;
};

template <class T>
class BinaryTree {
 public:
  BinaryTree() : root_(nullptr) {}
  ~BinaryTree() { DestroyTree(root_); }

  void insert(int value) { root_ = InsertRecursive(root_, value); }

  bool search(int value) { return SearchRecursive(root_, value); }

  std::vector<T> InorderTraversal();
  std::vector<T> PreorderTraversal();
  std::vector<T> PostorderTraversal();

 private:
  Node<T>* root_;
  Node<T>* InsertRecursive(Node<T>* node, int value);
  bool SearchRecursive(Node<T>* node, int value);
  void InorderTraversalRecursive(Node<T>* node, std::vector<T>& ans);
  void PreorderTraversalRecursive(Node<T>* node, std::vector<T>& ans);
  void PostorderTraversalRecursive(Node<T>* node, std::vector<T>& ans);
  void DestroyTree(Node<T>* node);
  int GetHeight(Node<T>* node);
  int GetBalance(Node<T>* node);
  void UpdateHeight(Node<T>* node);
  Node<T>* RotateRight(Node<T>* node);
  Node<T>* RotateLeft(Node<T>* node);
  Node<T>* Balance(Node<T>* node);
};

template <class T>
std::vector<T> BinaryTree<T>::InorderTraversal() {
  std::vector<T> ans;
  InorderTraversalRecursive(root_, ans);
  return ans;
}

template <class T>
std::vector<T> BinaryTree<T>::PreorderTraversal() {
  std::vector<T> ans;
  PreorderTraversalRecursive(root_, ans);
  return ans;
}

template <class T>
std::vector<T> BinaryTree<T>::PostorderTraversal() {
  std::vector<T> ans;
  PostorderTraversalRecursive(root_, ans);
  return ans;
}

template <class T>
void BinaryTree<T>::InorderTraversalRecursive(Node<T>* node,
                                              std::vector<T>& ans) {
  if (node == nullptr) {
    return;
  }
  InorderTraversalRecursive(node->left_ptr, ans);
  ans.push_back(node->data);
  InorderTraversalRecursive(node->right_ptr, ans);
}

template <class T>
void BinaryTree<T>::PreorderTraversalRecursive(Node<T>* node,
                                               std::vector<T>& ans) {
  if (node == nullptr) {
    return;
  }
  ans.push_back(node->data);
  PreorderTraversalRecursive(node->left_ptr, ans);
  PreorderTraversalRecursive(node->right_ptr, ans);
}

template <class T>
void BinaryTree<T>::PostorderTraversalRecursive(Node<T>* node,
                                                std::vector<T>& ans) {
  if (node == nullptr) {
    return;
  }
  PostorderTraversalRecursive(node->left_ptr, ans);
  PostorderTraversalRecursive(node->right_ptr, ans);
  ans.push_back(node->data);
}

template <class T>
bool BinaryTree<T>::SearchRecursive(Node<T>* node, int value) {
  if (node == nullptr) {
    return false;
  }

  if (value == node->data) {
    return true;
  }

  if (value < node->data) {
    return SearchRecursive(node->left_ptr, value);
  } else {
    return SearchRecursive(node->right_ptr, value);
  }
}

template <class T>
Node<T>* BinaryTree<T>::InsertRecursive(Node<T>* node, int value) {
  if (node == nullptr) {
    return new Node(value);
  }

  if (value < node->data) {
    node->left_ptr = InsertRecursive(node->left_ptr, value);
  } else if (value > node->data) {
    node->right_ptr = InsertRecursive(node->right_ptr, value);
  }
  return Balance(node);
}

template <class T>
void BinaryTree<T>::DestroyTree(Node<T>* node) {
  if (node == nullptr) {
    return;
  }

  DestroyTree(node->left_ptr);
  DestroyTree(node->right_ptr);
  delete node;
}

template <class T>
int BinaryTree<T>::GetHeight(Node<T>* node) {
  if (node == nullptr) return 0;
  return node->height;
}

template <class T>
int BinaryTree<T>::GetBalance(Node<T>* node) {
  if (node == nullptr) return 0;
  return GetHeight(node->left_ptr) - GetHeight(node->right_ptr);
}

template <class T>
void BinaryTree<T>::UpdateHeight(Node<T>* node) {
  node->height =
      std::max(GetHeight(node->left_ptr), GetHeight(node->right_ptr)) + 1;
}

template <class T>
Node<T>* BinaryTree<T>::RotateRight(Node<T>* node) {
  Node<T>* l_child = node->left_ptr;
  Node<T>* lr_child = l_child->right_ptr;

  l_child->right_ptr = node;
  node->left_ptr = lr_child;

  UpdateHeight(node);
  UpdateHeight(l_child);

  return l_child;
}

template <class T>
Node<T>* BinaryTree<T>::RotateLeft(Node<T>* node) {
  Node<T>* r_child = node->right_ptr;
  Node<T>* rl_child = r_child->left_ptr;

  r_child->left_ptr = node;
  node->right_ptr = rl_child;

  UpdateHeight(node);
  UpdateHeight(r_child);

  return r_child;
}

template <class T>
Node<T>* BinaryTree<T>::Balance(Node<T>* node) {
  UpdateHeight(node);

  int balance = GetBalance(node);

  if (balance > 1) {
    if (GetBalance(node->left_ptr) < 0) {
      node->left_ptr = RotateLeft(node->left_ptr);
    }
    return RotateRight(node);
  }
  if (balance < -1) {
    if (GetBalance(node->right_ptr) > 0) {
      node->right_ptr = RotateRight(node->right_ptr);
    }
    return RotateLeft(node);
  }

  return node;
}
