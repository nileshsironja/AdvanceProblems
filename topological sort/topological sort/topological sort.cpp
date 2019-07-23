// topological sort.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<list>
#include<stdlib.h>
#include<string.h>
#define size 15
using namespace std;

int stack[size];
int top = 0;
struct Graph
{
   list<int> *adj;
   int V;
   int E;
};
struct Graph G;
int visited[size] = {0};
void dotopo(int v)
{
	//int i;

	list<int>::iterator it;
	 
	for(it = G.adj[v].begin(); it != G.adj[v].end();it++)
	{
	   if(!visited[*it])
		   dotopo(*it); 
	}

	visited[v] = 1;
	stack[top++] = v;
}

void topo()
{
	
	int i;
	 
	for(i=0;i<G.V;i++)
	{
		if(!visited[i])
		dotopo(i);	 
		//visited[i] = 1;
	}


	for(i=top-1;i>=0;i--)
		cout<<endl<<stack[i];

}


int main()
{
	cout<<"Enter no of Vertices :";
	cin>>G.V;
	cout<<endl<<"Enter no of edges :";
	cin>>G.E;
	G.adj = new list<int>[G.V];
	int i,a,b;
	for(i=0;i<G.E;i++)
	{
		cin>>a>>b;
		G.adj[a].push_back(b); 
	}

	topo();

	return 0;
}

