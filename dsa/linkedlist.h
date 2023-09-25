#include<iostream>
#include<fstream>
using namespace std;
struct node
{
  int info;
  node *link;
}*start=NULL;
void insertbegin(int value)
{
  node *n;
  n=new node;
  n->info=value;
  n->link=start;
  start=n;
}
void insertend(int value)
{
  node *n,*p;
  n=new node;
  n->info=value;
  n->link=NULL;
  if(start==NULL)
  {
    start=n;
    return;
  }
  p=start;
  while(p->link!=NULL)
  {p=p->link;}
  p->link=n;
}
void insertafter(int value,int after)
{
  node *n,*p;
  n=new node;
  n->info=value;
  if(start==NULL)
  {
    n->link=NULL;
    start=n;
    return;
  }
    p=start;
    while(p->link!=NULL)
    { if(p->info==after)
      break;
      p=p->link;
    }
    n->link=p->link;
    p->link=n;
}
void showlist()
{
  node *p;
  if(start==NULL)
  cout<<"List is empty\n";
  else
  {p=start;
  while(p!=NULL)
  {
    cout<<p->info<<"  ";
    p=p->link;
  }
  cout<<endl;
}}
void delnode(int value)
{
  node *p,*prev;
  p=start;prev=NULL;
  while(p!=NULL)
  {
    if(value==p->info)
    break;
    prev=p;
    p=p->link;
  }
  if(p==NULL)
  {cout<<"value not present\n";
  return;}
  cout<<p->info<<" deleted\n";
  if(p==start)
   start=p->link;
   else
   prev->link=p->link;
   delete p;
}
void reverse()
{
  node *cur,*prev,*next;
  cur=start;prev=NULL;
  while(cur!=NULL)
  {
    next=cur->link;
    cur->link=prev;
    prev=cur;
    cur=next;
  }
  start=prev;
}
void count()
{
  int c=0;
  node *p;
  p=start;
  while(p!=NULL)
  {
    c++;
    p=p->link;
  }
  cout<<"No. of nodes is "<<c<<"\n";
}

void linkedlist()
{ system("cls");
  int ch,value,after;
  ifstream ifs;
  int n, i;
  ifs.open("data.txt");
  i = 0;
  while (!ifs.eof())
  {
    ifs >> n;
    insertend(n);
    cout << n << " ";
  }
  cout << endl;

  while(1)
  { cout << "Data Structure: Linked List\n";
    cout << "----------------------------\n";
    cout<<"1. Insert at beginning\n";
    cout<<"2. Insert at end\n";
    cout<<"3. Insert after\n";
    cout<<"4. Showlist\n";
    cout<<"5. Delete node\n";
    cout<<"6. Reverse of list\n";
    cout<<"7. Count no. of nodes\n";
    cout<<"8. Return to main menu\n";
    cout<<"Enter your choice :";
    cin>>ch;
    if(ch==1)
    {
      cout<<"Enter value ";
      cin>>value;
      insertbegin(value);
    }
    else
    if(ch==2)
    {
      cout<<"Enter value ";
      cin>>value;
      insertend(value);
    }
    else
    if(ch==3)
    {
      cout<<"Enter value to be inserted ";
      cin>>value;
      cout<<"Enter value of after ";
      cin>>after;
      insertafter(value,after);
    }
    else
    if(ch==4)
    {
      showlist();
    }
    else
    if(ch==5)
    {
      cout<<"enter value to be deleted: ";
      cin>>value;
      delnode(value);
    }
    else
    if(ch==6)
    {
      reverse();
    }
    else
    if(ch==7)
    {
      count();
    }
    else
    if(ch==8)
    {
      return;
    }
  }
}