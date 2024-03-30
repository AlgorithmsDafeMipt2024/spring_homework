#include <algorithm>
#include <deque>
#include <iostream>
using std::endl, std::cout;

#include "stack.hpp"

int main() {
  auto stack = Stack<int>();

  Stack<int> stack_1;
  std::stack<int> stack_2;

  // pushing elements into first stack
  stack_1.Push(1);
  stack_1.Push(2);
  stack_1.Push(3);
  stack_1.Push(4);

  // pushing elements into 2nd stack
  stack_2.push(3);
  stack_2.push(5);
  stack_2.push(7);
  stack_2.push(9);

  cout << "stack_1 = ";
  while (!stack_1.Empty()) {
    cout << stack_1.Top() << " ";
    stack_1.Pop();
  }

  // printing the second stack
  cout << endl << "stack_2 = ";
  while (!stack_2.empty()) {
    cout << stack_2.top() << " ";
    stack_2.pop();
  }

  cout << endl;
  cout << endl;

  // pushing elements into first stack
  stack_1.Push(1);
  stack_1.Push(2);
  stack_1.Push(3);
  stack_1.Push(4);

  // pushing elements into 2nd stack
  stack_2.push(3);
  stack_2.push(5);
  stack_2.push(7);
  stack_2.push(9);

  // using swap() function to swap elements of stacks
  stack_1.Swap(stack_2);

  // printing the first stack
  cout << "stack_1 = ";
  while (!stack_1.Empty()) {
    cout << stack_1.Top() << " ";
    stack_1.Pop();
  }

  // printing the second stack
  cout << endl << "stack_2 = ";
  while (!stack_2.empty()) {
    cout << stack_2.top() << " ";
    stack_2.pop();
  }

  cout << endl;
  cout << endl;

  Stack<int> stack_1_2;
  Stack<int> stack_2_2;

  // pushing elements into first stack
  stack_1_2.Push(1);
  stack_1_2.Push(2);
  stack_1_2.Push(3);
  stack_1_2.Push(4);

  // pushing elements into 2nd stack
  stack_2_2.Push(3);
  stack_2_2.Push(5);
  stack_2_2.Push(7);
  stack_2_2.Push(9);

  cout << "stack_1_2 = ";
  while (!stack_1_2.Empty()) {
    cout << stack_1_2.Top() << " ";
    stack_1_2.Pop();
  }

  // printing the second stack
  cout << endl << "stack_2_2 = ";
  while (!stack_2_2.Empty()) {
    cout << stack_2_2.Top() << " ";
    stack_2_2.Pop();
  }

  cout << endl;
  cout << endl;

  // pushing elements into first stack
  stack_1_2.Push(1);
  stack_1_2.Push(2);
  stack_1_2.Push(3);
  stack_1_2.Push(4);

  // pushing elements into 2nd stack
  stack_2_2.Push(3);
  stack_2_2.Push(5);
  stack_2_2.Push(7);
  stack_2_2.Push(9);

  // using swap() function to swap elements of stacks
  stack_1_2.Swap(stack_2_2);

  // printing the first stack
  cout << "stack_1_2 = ";
  while (!stack_1_2.Empty()) {
    cout << stack_1_2.Top() << " ";
    stack_1_2.Pop();
  }

  // printing the second stack
  cout << endl << "stack_2_2 = ";
  while (!stack_2_2.Empty()) {
    cout << stack_2_2.Top() << " ";
    stack_2_2.Pop();
  }

  cout << endl;

  return 0;
}
