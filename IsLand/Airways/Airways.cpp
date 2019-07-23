// Airways.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<limits.h>
#define S 11
using namespace std;
int N;
int arr[S][S];
int visited[S];
int fare = 0;
int fare_s = 0;
 
/*
5
4
0 5 4 9
1 0 3 2
7 2 0 1
9 2 5 0
*/
int ptr=0;
int store[S] = {0};
void dodfs(int v,int cnt)
{
	visited[v] = 1;
	if(cnt == N-1)
	{
		fare += arr[v][0];
		store[ptr++] = fare;
		fare -= arr[v][0];
		//return fare;
	}
	 
	for(int i=0;i<N;i++)
	{
		if(!visited[i] && arr[v][i])
		{ 
			fare += arr[v][i];
 			dodfs(i,cnt+1);
			fare -= arr[v][i];
 		} 
	} 
	visited[v] = 0;
}

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		cin>>N;
		memset(visited,0,sizeof(visited));
		memset(arr,0,sizeof(arr));
		for(int i = 0 ; i<N;i++)
		{
			for(int j = 0 ; j<N;j++)
			{
				cin>>arr[i][j];
			}
		}

		dodfs(0,0);

		for(int i=0;i<ptr;i++)
			cout<<store[i]<<" ";
		//cout<<fare;
	}
 
	system("pause");
	return 0;
}

