#include <iostream>
using namespace std;
const int F=1000;
void shortestPath()
{
	int w[6][6]={{0,5,10,25,F,F},
			{F,0,F,F,20,F},
			{F,F,0,8,F,18},
			{F,F,F,0,F,12},
			{F,F,15,F,0,F},
			{F,F,F,F,4,0}};
	int i,j,k;
	
	for(k=0;k<=5;k++)
	{
		for(i=0;i<=5;i++)
		{
			for(j=0;j<=5;j++)
			{
				if(w[i][j]>w[i][k]+w[k][j])
					w[i][j]=w[i][k]+w[k][j];
			}
		}
		cout<<"After Iteration "<<k<<endl;
		for(i=0;i<=5;i++)
		{
			for(j=0;j<=5;j++)
			{
				cout<<w[i][j];
			}
			cout<<endl;
		}
	}
	char o;
	cout<<"\n\nPress Any Alphabet to return to main menu...";
	cin>>o;
	return;
}
