#include<iostream>
using namespace std;
struct tnode
{
  tnode *left;
  int info;
  tnode *right;
}*root=NULL;
void insertBST(int value)
{
  tnode *n,*p,*par;
  char side;
  n=new tnode;
  n->info=value;
  n->left=n->right=NULL;
  if(root==NULL)
  {
    root=n;
    return;
  }
  p=root;
  par=NULL;
  side=' ';
  while(p!=NULL)
  {
    par=p;
    if(value<p->info)
    {
      p=p->left;
      side='L';
    }
    else
    {
      p=p->right;
      side='R';
    }
  }
  if(side=='L')
  par->left=n;
  else
  par->right=n;
}
void searchBST(int value)
{
  tnode *p;
  p=root;
  while(p!=NULL)
  {
    if(value==p->info)
    break;
    else
    if(value>p->info)
    p=p->right;
    else
    p=p->left;
  }
  if(p==NULL)
  cout<<"value not present\n";
  else
  cout<<"value is present at "<<p<<endl;
}
void preorder(tnode *root)
{
  if(root==NULL)
  return;
  cout<<root->info<<"  ";
  preorder(root->left);
  preorder(root->right);
}
void inorder(tnode *root)
{
  if(root==NULL)
  return;
  inorder(root->left);
  cout<<root->info<<"  ";
  inorder(root->right);
}
void postorder(tnode *root)
{
  if(root==NULL)
  return;
  postorder(root->left);
  postorder(root->right);
  cout<<root->info<<" ";
}

void del0or1childnode(tnode *p,tnode *par)
{
  tnode *next;
  if(p->left!=NULL)
  next=p->left;
  else
  next=p->right;
  if(par==NULL)
  root=next;
  else
  if(par->left==p)
  par->left=next;
  else
  par->right=next;
}
void del2childnode(tnode *p,tnode *par)
{
  tnode *next,*nextpar;
  next=p->right;
  nextpar=p;
  while(next->left!=NULL)
  {
    nextpar=next;
    next=next->left;
  }
  del0or1childnode(next,nextpar);

  next->left=p->left;
  next->right=p->right;
  if(par==NULL)
  root=next;
  else
  if(par->left==p)
  par->left=next;
  else
  par->right=next;
}

void delBST(int value)
{
  tnode *p,*par;
  p=root;
  par=NULL;
  while(p!=NULL)
  {
    if(value==p->info)
    break;
    par=p;
    if(value<p->info)
    p=p->left;
    else
    p=p->right;
  }
  if(p==NULL)
  {
    cout<<"value not present\n";
    return;
  }
  if(p->left!=NULL && p->right!=NULL)
  del2childnode(p,par);
  else
  del0or1childnode(p,par);
  cout<<value<<" Deleted \n";
  delete p;
}
void bst()
{system("cls");
  int ch,value;
  insertBST(30);
  insertBST(50);
  insertBST(20);
  insertBST(60);
  insertBST(46);
  insertBST(32);
  insertBST(75);
  insertBST(28);
  insertBST(38);
  insertBST(45);
  
  while(1)
  { cout<<"Data Structure: Binary Search Tree\n";
    cout<<"----------------------------------\n";
    cout<<"1. Insert BST\n";
    cout<<"2. Search BST\n";
    
    cout<<"3. Preorder\n";
    cout<<"4. Inoder\n";
    cout<<"5. Postorder\n";
    cout<<"6. Delete BST\n";
    cout<<"7. Exit\n";
    cout<<"Enter your choice ";
    cin>>ch;
    if(ch==1)
    {
      cout<<"Enter value ";
      cin>>value;
      insertBST(value);
    }
    else
    if(ch==2)
    {
       cout<<"Enter value ";
      cin>>value;
      searchBST(value);
    }
    else
    if(ch==3){
    preorder(root);
    cout<<endl;
    }
    else
    if(ch==4)
    {
    inorder(root);
    cout<<endl;
    }
    else
    if(ch==5)
    {
    postorder(root);
    cout<<endl;
    }
    else
    if(ch==6)
    {
      cout<<"Enter value ";
      cin>>value;
      delBST(value);
    }
    else
    if(ch==7)
    exit(0);
    else
    cout<<"invalid choice\n";

  }
}