#include <iostream>
#include <fstream>
using namespace std;
void printArray(int *arr, int n)
{
  int i;
  for (i = 0; i < n; i++)
    cout << arr[i] << "  ";
  cout << endl;
}

void linearsearch(int *a, int value, int n)
{
  int i;
  for (i = 0; i < n; i++)
  {
    if (value == a[i])
      break;
  }
  if (i == n + 1)
    cout << "Value not present\n";
  else
    cout << "Value is present at " << i << " th position\n";
}
void binarysearch(int *a, int value, int n)
{
  int beg, mid, end;

  beg = 0;
  end = n - 1;
  while (beg <= end)
  {
    mid = (beg + end) / 2;
    if (a[mid] == value)
      break;
    else if (a[mid] > value)
      end = mid - 1;
    else
      beg = mid + 1;
  }
  if (beg > end)
    cout << "Value not present\n";
  else
    cout << "Value is present at" << mid << "th position\n";
}
void arrayCopy(int *tar, int *src, int size)
{
  int i;
  for (i = 0; i < size; i++)
  {
    tar[i] = src[i];
  }
}

void bubblesort(int *a, int n)
{
  int i, j, t;
  int temp[100];
  arrayCopy(temp, a, n);

  for (i = 0; i < n - 1; i++)
  {
    for (j = 0; j < n - 1 - i; j++)
    {
      if (temp[j] > temp[j + 1])
      {
        t = temp[j];
        temp[j] = temp[j + 1];
        temp[j + 1] = t;
      }
    }
  }
  cout << "BubbleSorted array is :\n";
  printArray(temp, n);
}
void insertionsort(int *a, int n)
{
  int i, j, p;
  int temp[100];
  arrayCopy(temp, a, n);
  for (i = 1; i < n; i++)
  {
    p = temp[i];
    for (j = i - 1; j >= 0; j--)
    {
      if (p > temp[j])
        break;
      else
        temp[j + 1] = temp[j];
    }
    temp[j + 1] = p;
  }
  cout << "InsertSorted array is :\n";
  printArray(temp, n);
}
void mergesort()
{
  cout << "merge sort\n";
}
void selectionsort(int *arr, int n, int inplace = 0, int display = 1)
{
  int i, j, t, p, *a;
  int temp[100];
  if (inplace == 0)
  {
    arrayCopy(temp, arr, n);
    a = temp;
  }
  else
    a = arr;

  for (i = 0; i < n - 1; i++)
  {
    p = i;
    for (j = i + 1; j < n; j++)
    {
      if (a[p] > a[j])
        p = j;
    }
    if (p != i)
    {
      t = a[i];
      a[i] = a[p];
      a[p] = t;
    }
  }
  if (display == 1)
  {
    cout << "SelectionSorted array is:\n";
    printArray(a, n);
  }
}
void merge(int *a, int b1, int e1, int b2, int e2)
{
  int i, j, k, *temp, as;
  as = (e2 - b1 + 1);
  temp = new int[as];
  i = b1;
  j = b2;
  k = 0;
  while (i <= e1 && j <= e2)
  {
    if (a[i] < a[j])
    {
      temp[k] = a[i];
      i++;
    }
    else
    {
      temp[k] = a[j];
      j++;
    }
    k++;
  }
  if (i <= e1)
  {
    while (i <= e1)
    {
      temp[k] = a[i];
      i++;
      k++;
    }
  }
  else
  {
    while (j <= e2)
    {
      temp[k] = a[j];
      j++;
      k++;
    }
  }
    for (i = 0; i < as; i++)
    {
      a[b1 + i] = temp[i];
    }
    delete[] temp;
  
}
void mergesort(int *a, int arrsize, int grpsize)
{
  //cout<<grpsize<<endl;
  if (arrsize <= grpsize)
    return;
  int ngs, tg, rem, i, b1, e1, b2, e2;
  ngs = grpsize * 2;
  tg = arrsize / ngs;
  rem = arrsize % ngs;
  for (i = 0; i < tg; i++)
  {
    b1 = i * ngs;
    e1 = b1 + grpsize - 1;
    b2 = e1 + 1;
    e2 = b2 + grpsize - 1;
    merge(a, b1, e1, b2, e2);
  }
  if (rem > grpsize)
  {
    b1 = tg * ngs;
    e1 = b1 + grpsize - 1;
    b2 = e1 + 1;
    e2 = b2 + (rem - grpsize) - 1;
    merge(a, b1, e1, b2, e2);
  }
  mergesort(a, arrsize, ngs);
}

void array()
{
  int ch;
  int arr[100];
  ifstream ifs("data.txt");
  int n, i, value, arr_size;
 char c;
  system("cls");
  if(!ifs.is_open())
  {
    cout<<"Default Dataset File Not Present\n";
    cout<<"Press any Alphabet and ENTER to return\n";
    cin>>c;
    return;
  }
  i = 0;
  cout<<"Default Data Items For Array is: ";
  //cout<<"--------------------------------\n";
  while (!ifs.eof())
  {
    ifs >> n;
    arr[i] = n;
    i++;
    cout << n << " ";
  }
  cout<<"\n\n\n";
  arr_size = i;
  cout << endl;

  while (1)
  {
    cout << "Data Structure: Array\n";
    cout << "----------------------\n";
    cout << "1. Linear Search\n";
    cout << "2. Binary Search\n";
    cout << "3. Selection Sort\n";
    cout << "4. Bubble Sort\n";
    cout << "5. Insertion Sort\n";
    cout << "6. Merge Sort\n";
    cout << "7. Return to main menu\n";
    cout << "Enter your choice: ";
    cin >> ch;
    if (ch == 1)
    {
      cout << "Enter Value to Search ";
      cin >> value;
      linearsearch(arr, value, arr_size);
    }
    else if (ch == 2)
    {
      int temp[100];
      arrayCopy(temp, arr, arr_size);
      selectionsort(temp, arr_size, 1, 0);

      cout << "Enter Value to Search ";
      cin >> value;
      binarysearch(temp, value, arr_size);
    }
    else if (ch == 3)
      selectionsort(arr, arr_size);
    else if (ch == 4)
      bubblesort(arr, arr_size);
    else if (ch == 5)
      insertionsort(arr, arr_size);
    else if (ch == 6)
    {
      mergesort(arr, arr_size, 1);
      printArray(arr, arr_size);
    }
    else if (ch == 7)
      return;
    else
      cout << "Invalid Choice\n";

  }
}
