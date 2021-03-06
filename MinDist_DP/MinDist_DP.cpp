// MinDist_DP.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#define N 4
#define INF 9999
#include<iostream>
#include<time.h>
using namespace std;
int cost[N][N] = { 
	{ 0, 15, 80, 90 },
	{ INF, 0, 40, 50 },
	{ INF, INF, 0, 70 },
	{ INF, INF, INF, 0 }
};

int recDP[N] = { 0 };
int dp[N] = { 0 };
int min(int a, int b)
{
	if (a < b)
		return a;
	return b;
}
int minCost(int s)
{
	if (s == N - 1)
	{
		return cost[s][N - 1];
	}

	int minC = cost[s][N-1];
	for (int i = s + 1; i < N; i++)
	{
		int minCst = min(cost[s][N-1], cost[s][i] + minCost(i));

		if (minC > minCst)
			minC = minCst;
	}
	return minC;
}

int minCost_RecDP(int s)
{
	if (s == N - 1)
	{
		return cost[s][N - 1];
	}
	if (recDP[s] != INF)
		return recDP[s];

	int minC = cost[s][N - 1];
	for (int i = s + 1; i < N; i++)
	{
		int minCst = min(cost[s][N - 1], cost[s][i] + minCost_RecDP(i));

		if (minC > minCst)
			minC = minCst;
	}
	return (recDP[s] = minC);
}


int main()
{
	for (int i = 0; i < N; i++)
	{
		recDP[i] = INF;
		dp[i] = INF;
	}

	clock_t time;
	double total;
	time = clock();

	cout << "The Minimum cost to reach station "
		<< N << " is " << minCost(0);

	total = (double)(time - time_t()) / CLOCKS_PER_SEC;
	cout << endl <<"Time :"<<  total<< endl;

	time = clock();

	cout <<endl<< "The Minimum cost to reach station "
		<< N << " is " << minCost_RecDP(0);


	total = (double)(time - time_t()) / CLOCKS_PER_SEC;
	cout << endl << "Time :" << total  << endl;

	return 0;
}

