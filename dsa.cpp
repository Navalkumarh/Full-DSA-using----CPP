/* 
Project: DSA using C++
Description: Whole DSA covered in single program using C++ language
Date: 15/09/2023
Author: Naval Kumar
*/



#include <iostream>
#include <fstream>
#include "array.h"
#include "linkedlist.h"
#include "stack.h"
#include "lqueue.h"
#include "bst.h" 
#include "graph.h"
//#include "shortpath.h"

using namespace std;
void hashing();
main()
{
  int ch;
  string c;
  while (1)
  {
    system("cls");
    cout << "Data Structure and Algorithm\n";
    cout << "-----------------------------\n";
    cout << "1. Array\n";
    cout << "2. Linked List\n";
    cout << "3. Stack\n";
    cout << "4. Queue\n";
    cout << "5. Binary Tree\n";
    cout << "6. Graph\n";
    cout << "7. Exit\n";
    cout << "Enter Your Choice: ";
    cin>>ch;
    if (ch == 1)
      array();
    else if (ch == 2)
      linkedlist();
    else if (ch == 3)
      linearstack();
    else if (ch == 4)
      lqueue();
    else if (ch == 5)
      bst();
    else if (ch == 6)
      graphMenu();
    else if (ch == 7)
      break;
    cout << "Invalid Choice\n";
  }
}


