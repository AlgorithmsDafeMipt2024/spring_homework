// std libs
#include <iostream>

// my libs
#include "bst.hpp"

// std usings:
using std::cout, std::cin, std::endl;
using std::string, std::optional;

// MEANS: перегрузка, которая выводит optional в поток
// ARGS: [ostream&]: ссылка на поток, в который надо вывести (мод.)
// ARGS: [const vector<Type>&]: вектор элементов произвольного типа
// RETURNS: [ostream&]: ссылка на поток, в который вывели
// template <typename Type>
// inline std::ostream& operator<<(std::ostream& os,
//                                 const std::optional<Type>& opt) {
//   os << opt.value();
// }

int main() {
  // самое глупое создание бинарного дерева
  auto par_1 = new Node(8);

  par_1->left_child = new Node(3);
  {
    par_1->left_child->left_child = new Node(1);
    par_1->left_child->right_child = new Node(6);
    {
      par_1->left_child->right_child->left_child = new Node(4);
      par_1->left_child->right_child->right_child = new Node(7);
    }
  }
  par_1->right_child = new Node(10);
  {
    par_1->right_child->right_child = new Node(14);
    { par_1->right_child->right_child->left_child = new Node(13); }
  }

  auto bst_1 = BinarySearchTree(par_1);

  // чуть более умное создание бинарного дерева
  auto bst_2 = BinarySearchTree(new Node(8));
  bst_2.Add(3, "3");
  bst_2.Add(1, "1");
  bst_2.Add(6, "6");
  bst_2.Add(4, "4");
  bst_2.Add(7, "7");
  bst_2.Add(10, "10");
  bst_2.Add(14, "14");
  bst_2.Add(13, "13");

  cout << bst_1.Find(8).value() << endl;
  cout << bst_2.Find(8).value() << endl;
  return 0;
}
