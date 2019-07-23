// Graph.cpp.cpp : main project file.

#include "stdafx.h"
#include<iostream>
#define size 4
using namespace std;
int stack[size],top = -1;

void printpath(int stack[],int top)
{
	int i;
	for(i=0;i<=top;i++)
	{
		cout<<" "<<stack[i];
	} 
	cout<<endl;
	return;
}

void dodfs(int matrix[][size],int visited[],int src,int dst,int stack[],int top)
{
	int i;
	if(src == dst)
	{
	  printpath(stack,top);
	  return;
	} 
	visited[src] = 1;
	for(i=0;i<size;i++)
	{
	  if(matrix[src][i] && !visited[i])
	  {
		 stack[top+1] = i;
		 dodfs(matrix,visited,i,dst,stack,top+1);
		 
	  }
	} 	 
	//top--;
	visited[src] = 0;
}

void prntall_path(int matrix[][size],int visited[],int src, int dst)
{
	int i;
	stack[++top] = src;
	dodfs(matrix,visited,src,dst,stack,top);
	 
}
 
//print all path from source to destination
int main()
{
	int matrix[size][size] = {
							{0,1,1,1},
							{0,0,0,1},
							{1,1,0,0},
							{0,0,0,0},
						};
	int visited[size],s,d;
	memset(visited,0,sizeof(visited));
	cout<<"Enter source :";
	cin>>s;
	cout<<"Enter Dest :";
	cin>>d;
	prntall_path(matrix,visited,s,d);
	system("pause");

}