// BFS_hack.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#define SIZE 1001
#define Maxs 999999
using namespace std;

int T,M,N;
int matrix[SIZE][SIZE];
//int visited[SIZE][SIZE];

int dist[SIZE];
int S;
int visit[SIZE];
int set[SIZE*SIZE][2];
int cnt = 0;

int getver()
{
	int maxdist = Maxs;
	int ver = 0;
	int index = 0;
	for(int i=0;i<=N;i++)
	{
		if(set[i][0] != -1 && maxdist > set[i][1])
		{
		  maxdist = set[i][1];
		  ver = set[i][0];
		  index = i;
		}
	}
	set[index][0] = -1;
	return ver;
}

void dobfs()
{
	cnt = 1;
	set[0][0] = S;
	set[0][1] = 0;
	dist[S] = 0;
	for(int j=1;j<=N;j++)
	{

		int u = getver(); 
		visit[u] = 1;
		
		for(int i=1;i<=N;i++)
		{
			if(u != i && matrix[u][i] && dist[i] > matrix[u][i]+dist[u])
			{
				dist[i] = matrix[u][i]+dist[u]; 
				set[cnt][0] = i;
				set[cnt++][1] = dist[i];
			}
		} 
	}
}

void empty()
{
	for(int i=1;i<=N;i++)
	{
		for(int j=1;j<=N;j++)
		{
			matrix[i][j] = 0;
			//visited[i][j] = 0;
		}
		dist[i] = Maxs;
		set[i][0] = -1;
		set[i][1] = Maxs;
	}
}

int main()
{
	
	cin>>T;
	int u,v;
	while(T--)
	{
		cin>>N>>M;
		empty();
		//dist[M] = Maxs;
		while(M--)
		{
			cin>>u>>v;
			matrix[u][v] = 6;
			matrix[v][u] = 6;
			//dist[M] = Maxs;
		}
		cin>>S;
		dobfs();

		for(int i=1;i<=N;i++)
		{
			if(i == S)
				continue;
			if(dist[i] == Maxs)
				cout<<"-1 ";
			else
				cout<<dist[i]<<" "; 
		}
		cout<<endl;
	
	}

	return 0;
}

