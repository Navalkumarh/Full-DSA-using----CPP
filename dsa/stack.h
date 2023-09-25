#include <iostream>
using namespace std;
#include <fstream>
const int SIZE = 8;
int stack[8], top = -1;
void push(int value)
{
  if (top == SIZE - 1)
    cout << "\nStack overflow\n\n";
  else
  {
    top++;
    stack[top] = value;
  }
  cout << endl
       << value << " Pushed Successfully..\n\n";
}
void pop()
{
  if (top == -1)
    cout << "\nStack Underflow\n\n";
  else
  {
    cout << endl
         << stack[top] << " Deleted\n\n";
    top--;
  }
}
void display()
{
  if (top == -1)
    cout << "\nStack is Empty\n\n";
  else
  {
    cout << "Stack from bottom to top is:\n";
    for (int i = 0; i <= top; i++)
    {
      cout << stack[i] << "  ";
    }
    cout << "\n\n";
  }
}
class estack
{
  char s[50];
  int top;

public:
  estack()
  {
    top = -1;
  }
  void push(char token)
  {
    if (top == 49)
    {
      cout << "\nStack Overflow\n\n";
      exit(0);
    }
    top++;
    s[top] = token;
  }
  char pop()
  {
    if (top == -1)
    {
      cout << "\nStack Underflow\n\n";
      exit(0);
    }
    return s[top--];
  }
  char peek()
  {
    return (s[top]);
  }
  int isempty()
  {
    if (top == -1)
      return (1);
    else
      return (0);
  }
};
int isoperator(char c)
{
  if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^')
    return (1);
  else
    return (0);
}
int getpriority(char op)
{
  if (op == '^')
    return (3);
  if (op == '*' || op == '/')
    return (2);
  if (op == '+' || op == '-')
    return (1);
  else
  {
    cout << "\nInvalid Operator " << op << "\n\n";
    exit(0);
  }
}
void expevaluation()
{
  estack stk;
  char infix[100], postfix[100];
  int i, p, a, b;
  char c;
  cout << "Infix to Postfix Conversion:\n";
  cout << "-----------------------------\n";
  cout << "Enter Infix Expression: ";
  cin >> infix;
  i = p = 0;
  while (infix[i] != '\0')
  {
    if (infix[i] == '(')
      stk.push(infix[i]);
    else if (isoperator(infix[i]))
    {
      while (1)
      {
        if (isoperator(stk.peek()))
        {
          a = getpriority(stk.peek());
          b = getpriority(infix[i]);
          if (a >= b)
          {
            c = stk.pop();
            postfix[p++] = c;
            continue;
          }
          else
            break;
        }
        else
          break;
      }
      stk.push(infix[i]);
    }
    else if (infix[i] == ')')
    {
      while (stk.peek() != '(')
      {
        c = stk.pop();
        postfix[p++] = c;
      }
      stk.pop();
    }
    else
    {
      postfix[p++] = infix[i];
    }
    i++;
  }
  while (!stk.isempty())
  {
    c = stk.pop();
    postfix[p++] = c;
  }
  postfix[p] = '\0';
  cout << "\nPostfix is: " << postfix << "\n\n";
}
int partition(int *a, int p, int q)
{
  int t;
  while (1)
  {
    while (p < q && a[p] <= a[q])
    {
      q--;
    }
    if (p == q)
      return (p);
    t = a[p];
    a[p] = a[q];
    a[q] = t;
    while (q > p && a[q] >= a[p])
    {
      p++;
    }
    if (p == q)
      return (p);
    t = a[p];
    a[p] = a[q];
    a[q] = t;
  }
}
void quiksort(int *a, int p, int q)
{
  int m;
  m = partition(a, p, q);
  if (m > p + 1)
    quiksort(a, p, m - 1);
  if (m < q - 1)
    quiksort(a, m + 1, q);
}
void quicksort()
{
  int a[15] = {45, 77, 54, 43, 89, 76, 65, 55, 25, 43, 90, 87, 65, 99, 77};
  quiksort(a, 0, 14);
  for (int j = 0; j < 15; j++)
    cout << a[j] << "  ";
}

void linearstack()
{system("cls");
  int ch, value;
  while (1)
  {
    cout << "Data Structure: Stack\n";
    cout << "----------------------\n";
    cout << "1. Push the value\n";
    cout << "2. Pop the value\n";
    cout << "3. Display stack\n";
    cout << "4. Expression evaluation\n";
    cout << "5. Quick sort\n";
    cout << "6. Return to main menu\n";
    cout << "Enter your choice :";
    cin >> ch;

    if (ch == 1)
    {
      cout << "Enter Value to Push: ";
      cin >> value;
      push(value);
    }
    else if (ch == 2)
    {
      pop();
    }
    else if (ch == 3)
    {
      display();
    }
    else if (ch == 4)
    {
      expevaluation();
    }
    else if (ch == 5)
    {
      quicksort();
      cout << endl;
    }
    else if (ch == 6)
      return;
    else
      cout << "Invalid choice\n\n";
  }
}
