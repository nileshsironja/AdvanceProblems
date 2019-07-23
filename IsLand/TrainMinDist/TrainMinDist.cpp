// TrainMinDist.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#define N 4
#define MAX 99999
using namespace std;

int matrix[N][N] = { 
					{0,15,80,90},
				    {MAX,0,40,50},
				    {MAX,MAX,0,70},
				    {MAX,MAX,MAX,0},
				   };

int visited[N][N] = {
					 {0,0,0,0},
					 {0,0,0,0},
					 {0,0,0,0},
					 {0,0,0,0},
				    };

int Gcost = 999999;
int getcost(int u,int cost)
{
	if(u == N-1)
	{
		if(Gcost > cost)
		{
			cout<<cost<<endl;
			Gcost = cost;
		}
		return cost; 
	}

	int localcost = 0;
	
	for(int i=u+1;i<N;i++)
	{ 
		if(!visited[u][i])
		{
			visited[u][i] = 1;
			localcost = getcost(i,cost+matrix[u][i]);
			visited[u][i] = 0;
		} 
	} 
	
	return localcost;
}


int main()
{

	cout<<getcost(0,0);
	cout<<endl<<"ans :"<<Gcost;
	getchar();
	return 0;
}

