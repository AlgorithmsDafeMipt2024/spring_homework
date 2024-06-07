#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

struct Node {
  int value;
  Node* left;
  Node* right;

  Node(int val) : value(val), left(nullptr), right(nullptr) {}
};

void insert(Node*& root, int value) {
  Node* newNode = new Node(value);
  if (root == nullptr) {
    root = newNode;
    return;
  }
  Node* current = root;
  while (true) {
    if (value <= current->value) {
      if (current->left == nullptr) {
        current->left = newNode;
        break;
      }
      current = current->left;
    } else {
      if (current->right == nullptr) {
        current->right = newNode;
        break;
      }
      current = current->right;
    }
  }
}

void build_binary_search_tree(vector<int>& arr, Node*& root) {
  for (int i = 0; i < arr.size(); ++i) {
    insert(root, arr[i]);
  }
}

string find(Node* current, int value) {
  while (true) {
    if (value == current->value) {
      return "Есть";
    }

    if (value < current->value) {
      if (current->left == nullptr) break;
      current = current->left;
    }

    if (value > current->value) {
      if (current->right == nullptr) break;
      current = current->right;
    }
  }
  return "Нет";
}

Node* findMin(Node* node) {
  while (node->left != nullptr) {
    node = node->left;
  }
  return node;
}

void remove(Node* current, int value) {
  while (true) {
    Node* next = nullptr;

    if (value < current->value) {
      next = current->left;
      if (next == nullptr) {
        cout << "Такого элемента нет\n";
      }

      if (value == next->value) {
        if (next->left == nullptr && next->right == nullptr) {
          current->left = nullptr;
          delete next;
          return;
        }
        if (next->left != nullptr && next->right == nullptr) {
          current->left = next->left;
          delete next;
          return;
        }
        if (next->left == nullptr && next->right != nullptr) {
          current->left = next->right;
          delete next;
          return;
        }
        if (next->left != nullptr && next->right != nullptr) {
          Node* min_right = findMin(next->right);
          next->value = min_right->value;
          value = min_right->value;
        }
      }
      current = next;
    }

    if (value > current->value) {
      next = current->right;
      if (current->right == nullptr) {
        cout << "Такого элемента нет\n";
      }
      if (value == next->value) {
        if (next->left == nullptr && next->right == nullptr) {
          current->right = nullptr;
          delete next;
        }
        if (next->left != nullptr && next->right == nullptr) {
          current->right = next->left;
          delete next;
        }
        if (next->left == nullptr && next->right != nullptr) {
          current->right = next->right;
          delete next;
        }
        if (next->left != nullptr && next->right != nullptr) {
          Node* min_right = findMin(next->right);
          next->value = min_right->value;
          value = min_right->value;
        }
        return;
      }
      current = next;
    }
  }
}