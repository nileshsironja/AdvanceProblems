// SyncShopping.cpp : Defines the entry point for the console application.
//

// BFS_hack.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#define SIZE 2001
#define Maxs 999999
using namespace std;

 
struct Q
{
	int ver;
	int time;
};
struct Q q[SIZE];

int matrix[SIZE][SIZE];
int N,M,K,T;
int visit[SIZE];
int timever[SIZE];
int min1=Maxs,min2=Maxs;
int store[SIZE];
int k =0;
void dobfs()
{
	 
	int f=-1,r=-1;
	k=0;
	q[++r].ver = 1;
	q[r].time = 0;

	while(f < r)
	{
		int u = q[++f].ver;
		visit[u] = 1;
		for(int i = 1; i <= N ; i++)
		{
			if(i!=u && !visit[i] && matrix[u][i])
			{
				if(timever[i] < q[f].time + matrix[u][i])
				{
				    
					timever[i] = q[f].time + matrix[u][i];
					if(i == N)
					store[k++] = timever[i];   		
				}
				q[++r].time = q[f].time + matrix[u][i];
				q[r].ver = i; 
			}
		} 
	}
	//store[j++] = timever[i];   		
	//return q[r].time;
}

void empty()
{
	for(int i=1;i<=N;i++)
	{
		for(int j=1;j<=N;j++)
			matrix[i][j] = 0; 
		visit[i] = 0;
		timever[i] = 0;
	}
}


int main()
{
	
	 
	//cin>>T;
	int u,v,t,K;
	//while(T--)
	{
		cin>>t>>M>>K;
		empty();
		//dist[M] = Maxs;
		N= t;
		while(t--)
		{
			cin>>u;
			while(u--)
			{
				cin>>v;
			}
		}

		while(M--)
		{
			cin>>u>>v>>t;
			matrix[u][v] = t; 

		}

		dobfs();

		int min1 = Maxs, min2 = Maxs;

		for(int i=0;i<k;i++)
		{
			if(min1 > store[i])
			{
				min2 = min1;
				min1 = store[i];
			}
			else if(min2 > store[i])
				min2 = store[i];
		}

		if(min2 == Maxs)
			cout<<min1<<endl;
		else
			cout<<min2<<endl;
	}

	return 0;
}

