#include<iostream>
using namespace std;
const int qsize=10;
int queue[qsize],front=-1,rear=-1;
void insertq(int value)
{
  if((front==0 && rear==qsize-1)|| (rear==front-1))
  cout<<"queue overflow\n";
  else
  {
    rear++;
    if(front==-1)
    front=0;
    if(rear==qsize)
    rear=0;
    queue[rear]=value;
  }
}
void removeq()
{
  if(front==-1)
  cout<<"queue underflow\n";
  else
  {
    cout<<queue[front]<<"deleted\n";
    if(front==rear)
    front=rear=-1;
    else
    {front++;
    if(front==qsize)
    front=0;
    }
  }
}
void displayq()
{
  int i;
  if(front==-1)
  cout<<"queue underflow";
  else
  {cout<<"values in queue are:\n";
    i=front;
    while(i!=rear)
    {
      cout<<queue[i]<<"  ";
      i++;
      if(i==qsize)
      i=0;
    }cout<<queue[i]<<endl;
  }
}
void lqueue()
{
  int ch,value;
  while(1)
  { cout<<"Data Structure: Queue\n";
    cout<<"---------------------\n";
    cout<<"1. Insert the value\n";
    cout<<"2. Remove the value\n";
    cout<<"3. Display\n";
    cout<<"4. Exit\n";
    cout<<"Enter your choice: ";
    cin>>ch;
    if(ch==1)
    {
      cout<<"Enter value: ";
      cin>>value;
      insertq(value);
    }
    else
    if(ch==2)
    {
      removeq();
    }
    else
    if(ch==3)
    displayq();
    else
    if(ch==4)
    break;
    else
    cout<<"invalid choice\n";
  }
  }