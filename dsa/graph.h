#include<iostream>
#include "shortpath.h"
using namespace std;
struct edge;

struct vertex
{
	char info;
	int status;
	vertex *vlink;
	edge *elink;
	vertex()
	{
		info=' ';
		status=0;
		vlink=NULL;
		elink=NULL;
	}
};
struct edge
{
	vertex *vlink;
	edge *elink;
	edge()
	{
		vlink=NULL;
		elink=NULL;
	}
};
class gstack
{
	vertex *data[20];
	int top;
	public:
	gstack()
	{
		top=-1;
	}
	void push(vertex *v)
	{
		top++;
		data[top]=v;
	}
	vertex* pop()
	{
		return(data[top--]);
	}
	int isempty()
	{
		return(top==-1);
	}
};

class gqueue
{
	vertex *data[20];
	int front,rear;
	public:
	gqueue()
	{
		front=rear=-1;
	}
	void insert(vertex *v)
	{
		rear++;
		if(front==-1)
			front=0;
		data[rear]=v;
	}
	vertex* remove()
	{
		vertex *p;
		p=data[front];
		if(front==rear)
			front=rear=-1;
		else
			front++;
		return(p);
	}
	int isempty()
	{
		return(front==-1);
	}
};



class graph
{
	vertex *start;
	public:
	graph()
	{
		start=NULL;
	}
	void addVertex(char value)
	{
		vertex *n;
		n=new vertex;
		n->info=value;
		n->vlink=start;
		n->elink=NULL;
		start=n;
	}
	vertex * getVertex(char value)
	{
		vertex *p=start;
		while(p!=NULL)
		{
			if(value==p->info)
				return(p);
			p=p->vlink;
		}
		return(NULL);

	}
	void addEdge(char p,char q)
	{
		vertex *x,*y;
		edge *n;
		x=getVertex(p);
		y=getVertex(q);
		if(x==NULL)
		{
			cout<<"Source Vertex Not Found \n";
			return;
		}
		if(y==NULL)
		{
			cout<<"Destin Vertex Not Found\n";
			return;
		}
		n=new edge;
		n->vlink=y;
		n->elink=x->elink;
		x->elink=n;
	}
	void setReadyState()
	{
		vertex *p;
		p=start;
		while(p!=NULL)
		{
			p->status=0;
			p=p->vlink;
		}
	}

	void dfs()
	{
		gstack stk;
		vertex *p;
		edge *e;
		cout<<"Traversal: Depth First Searh Traversal is \n";
		if(start==NULL)
		{
			cout<<"Graph is Empty\n";
			return;
		}
		setReadyState();
		stk.push(start);
		start->status=1;
		while(!stk.isempty())
		{
			p=stk.pop();
			cout<<p->info;
			p->status=2;
			e=p->elink;
			while(e!=NULL)
			{
				if(e->vlink->status==0)
				{
					stk.push(e->vlink);
					e->vlink->status=1;
				}
				e=e->elink;
			}
		}
		cout<<endl;
	}
	void bfs()
	{
		gqueue que;
		vertex *p;
		edge *e;
		cout<<"Traversal: Breadth First Search is\n";
		if(start==NULL)
		{
			cout<<"Graph is Empty\n";
			return;
		}
		setReadyState();
		que.insert(start);
		start->status=1;
		while(!que.isempty())
		{
			p=que.remove();
			cout<<p->info;
			p->status=2;
			e=p->elink;
			while(e!=NULL)
			{
				if(e->vlink->status==0)
				{
					que.insert(e->vlink);
					e->vlink->status=2;
				}
				e=e->elink;
			}
		}
		cout<<endl;
	}
	~graph()
	{
		vertex *v,*v2;
		edge *e,*e2;
		v=start;
		while(v!=NULL)
		{
			e=v->elink;
			while(e!=NULL)
			{
				e2=e->elink;
				delete e;
				e=e2;
			}
			v2=v->vlink;
			delete v;
			v=v2;
		}
	}
};


void graphTraversal()
{
	graph g ;
	g.addVertex('H');
	g.addVertex('G');
	g.addVertex('F');
	g.addVertex('E');
	g.addVertex('C');
	g.addVertex('B');
	g.addVertex('A');
	g.addEdge('A','C');
	g.addEdge('A','B');
	
	g.addEdge('B','F');
	g.addEdge('B','E');
	g.addEdge('C','H');
	g.addEdge('C','G');
	system("cls");
	
	cout<<"Default Vertex List is: H G F E C B A\n\n";
	cout<<"Default Edge List is\n";
	cout<<"1. A C\n";
	cout<<"2. A B\n";
	cout<<"3. B F\n";
	cout<<"4. B E\n";
	cout<<"5. C H\n";
	cout<<"6. C G\n";
	cout<<"Traversal Result is:\n";
	cout<<"--------------------\n";

	g.dfs();
	g.bfs();
	char c;
	cout<<"\n\nPress Any Alphabet to return to main menu...";
	cin>>c;
	return;
}
void graphMenu()
{system("cls");
int cho;
cout<<"Data Structure: Graph \n";
	cout<<"----------------------\n";

cout<<"1.Traversal in Graph\n";
cout<<"2.Shortest path in Graph\n";
cout<<"Enter your Choice : ";
cin>>cho;
if(cho==1)
{
	graphTraversal();

}
else
if(cho==2)
{
	shortestPath();
}
else
cout<<"Invalid Choice\n";
}

