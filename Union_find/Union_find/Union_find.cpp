// Union_find.cpp : main project file.

#include "stdafx.h"
#include<iostream>
using namespace std;
 
struct edge
{
	int u,v;
};
struct graph
{
	int E,V;
	struct edge *e;
};

struct graph* create_graph(struct graph *G)
{
    G = (struct graph*)malloc(sizeof(graph));
	
	cout<<"Enter no of Edges :";
	cin>>G->E;
	cout<<"Enter no of Vertices :";
	cin>>G->V;

	int i;
//	for(i=0;i<G->V;i++)
//		cout<<" "<<parent[i];
	cout<<"Enter edges :";
	G->e = (struct edge*)malloc(sizeof(edge)*G->E);
	for(i=0;i<G->E;i++)
	{
		cin>>G->e[i].u>>G->e[i].v; 
//		parent[G->e[i].u] = G->e[i].v;
	}
	return G;
}
int find(int parent[],int u)
{
	if(parent[u] == -1)return u;
	else return find(parent,parent[u]);
}
void Union(int parent[],int a,int b)
{
	//int x = find(parent,a);
	//int y = find(parent,b);
	parent[a] = b;
}
int is_cycle(struct graph *G)
{
	int i;
	int *parent = (int *)malloc(sizeof(int) * (G->V)); 
	memset(parent,-1,sizeof(int) * (G->V));
	for(i=0;i<G->E;i++)
	cout<<parent[i]<<" ";
	for(i=0;i<G->E;i++)
	{
		int a,b;
		a = find(parent,G->e[i].u); 
		b = find(parent,G->e[i].v);
		if(a == b)
		{
			return 1;
		} 
		Union(parent,a,b);
	}
	return 0;
}

int main()
{
	 graph *G = NULL;
     G = create_graph(G);
	 if(is_cycle(G))cout<<"cycle";else cout<<"no cycle";
     
	 system("pause");
	 return 0;
}
