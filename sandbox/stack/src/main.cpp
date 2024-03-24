#include <algorithm>
#include <deque>
#include <iostream>
using std::endl, std::cout;

#include "stack.hpp"

int main() {
  auto stack = Stack<int>();
  stack.Push(6);
  cout << stack.Top() << endl;
  cout << "size:" << stack.Size() << endl;
  stack.Pop();
  cout << "size:" << stack.Size() << endl;
  cout << endl;

  cout << endl;
  stack.PushRange({4, 3, 2, 1});
  cout << stack.Top() << endl;
  cout << "size:" << stack.Size() << endl;
  stack.Pop();
  cout << stack.Top() << endl;
  cout << "size:" << stack.Size() << endl;
  stack.Pop();
  cout << stack.Top() << endl;
  cout << "size:" << stack.Size() << endl;
  stack.Pop();
  cout << stack.Top() << endl;
  cout << "size:" << stack.Size() << endl;
  stack.Pop();
  cout << "size:" << stack.Size() << endl;
  cout << endl;

  stack.PushRange(std::vector(4, 0));
  cout << stack.Top() << endl;
  cout << "size:" << stack.Size() << endl;
  stack.Pop();
  cout << stack.Top() << endl;
  cout << "size:" << stack.Size() << endl;
  stack.Pop();
  cout << stack.Top() << endl;
  cout << "size:" << stack.Size() << endl;
  stack.Pop();
  cout << stack.Top() << endl;
  cout << "size:" << stack.Size() << endl;
  stack.Pop();
  cout << "size:" << stack.Size() << endl;
  cout << endl;

  stack.PushRange(std::vector({4, 3, 2, 1}));
  cout << stack.Top() << endl;
  cout << "size:" << stack.Size() << endl;
  stack.Pop();
  cout << stack.Top() << endl;
  cout << "size:" << stack.Size() << endl;
  stack.Pop();
  cout << stack.Top() << endl;
  cout << "size:" << stack.Size() << endl;
  stack.Pop();
  cout << stack.Top() << endl;
  cout << "size:" << stack.Size() << endl;
  stack.Pop();
  cout << "size:" << stack.Size() << endl;
  cout << endl;

  std::stack<int> std_stack;
  std_stack.push(4);
  std_stack.push(3);
  std_stack.push(2);
  std_stack.push(1);
  stack.PushRange(std_stack);
  cout << stack.Top() << endl;
  cout << "size:" << stack.Size() << endl;
  stack.Pop();
  cout << stack.Top() << endl;
  cout << "size:" << stack.Size() << endl;
  stack.Pop();
  cout << stack.Top() << endl;
  cout << "size:" << stack.Size() << endl;
  stack.Pop();
  cout << stack.Top() << endl;
  cout << "size:" << stack.Size() << endl;
  stack.Pop();
  cout << "size:" << stack.Size() << endl;
  cout << endl;

  Stack<int> my_stack;
  my_stack.Push(4);
  my_stack.Push(3);
  my_stack.Push(2);
  my_stack.Push(1);
  cout << my_stack.Top() << endl;
  stack.PushRange(my_stack);
  cout << stack.Top() << endl;
  cout << "size:" << stack.Size() << endl;
  stack.Pop();
  cout << stack.Top() << endl;
  cout << "size:" << stack.Size() << endl;
  stack.Pop();
  cout << stack.Top() << endl;
  cout << "size:" << stack.Size() << endl;
  stack.Pop();
  cout << stack.Top() << endl;
  cout << "size:" << stack.Size() << endl;
  stack.Pop();
  cout << "size:" << stack.Size() << endl;
  cout << endl;

  cout << my_stack.Top() << endl;
  stack = my_stack;
  cout << stack.Top() << endl;
  cout << "size:" << stack.Size() << endl;
  stack.Pop();
  cout << stack.Top() << endl;
  cout << "size:" << stack.Size() << endl;
  stack.Pop();
  cout << stack.Top() << endl;
  cout << "size:" << stack.Size() << endl;
  stack.Pop();
  cout << stack.Top() << endl;
  cout << "size:" << stack.Size() << endl;
  stack.Pop();
  cout << "size:" << stack.Size() << endl;
  cout << endl;
  return 0;
}
