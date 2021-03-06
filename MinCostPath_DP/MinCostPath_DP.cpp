// MinCostPath_DP.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#define R 3
#define C 3
using namespace std;

int min(int a, int b, int c)
{
	if (a > b)
	{
		if (a > c)
			return a;
		else
			return c;
	}
	else
	{
		if (b > c)
			return b;
		else
			return c;
	}

}
int minCost(int cost[R][C], int r, int c)
{
	int dp[R][C];
	memset(dp, 0, sizeof(dp));

	dp[0][0] = cost[0][0];
	for (int i = 1; i < C; i++) //col
		dp[0][i] = dp[0][i-1] + cost[0][i];

	for (int j = 1; j < R; j++) //row
		dp[j][0] = dp[j - 1][0] + cost[j][0];

	for (int i = 1; i < R; i++)
	{
		for (int j = 1; j < C; j++)
		{
			dp[i][j] = min(cost[i-1][j-1], cost[i-1][j], cost[i][j-1]);
		}
	}

	return dp[r][c];
}

/* Driver program to test above functions */
int main()
{
	int cost[R][C] = { { 1, 2, 3 },
	{ 4, 8, 2 },
	{ 1, 5, 3 } };
	cout<<minCost(cost, 2, 2);
	return 0;
}

