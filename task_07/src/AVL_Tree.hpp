#include <bits/stdc++.h>
#include <cstddef>

using namespace std;

struct Node {
  int key;
  unsigned char height;
  Node *left = nullptr;
  Node *right = nullptr;
  Node(int k) {
    key = k;
    height = 1;
  }
};

class AVL_Tree {
public:
  void Insert(int value);
  void Remove(int value);
  bool Contains(int value);

private:
  Node *root = nullptr;
  bool Contains(Node *node, int value);
  Node *Remove(Node *root, int k);
  Node *Insert(Node *root, int k);
  Node *RotateRight(Node *p);
  Node *Rotateleft(Node *q);
  Node *Balance(Node *p);
  Node *Findmin(Node *right_subtree);
  Node *Removemin(Node *p);
  unsigned char Height(Node *p);
  int DifferenceH(Node *p);
  void Fixheight(Node *p);
};
