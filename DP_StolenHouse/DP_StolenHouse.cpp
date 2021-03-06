// DP_StolenHouse.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
/*
maximum stolen money from the houses, money cann't be stolen from adjacent houses
*/

#define SIZE 5

int arr[SIZE] = { 5, 3, 4, 11, 2 };
int dp[SIZE] = { 0 };

int maxV(int a, int b,int c)
{
	
	int d = a > b ? a : b;

	int r = d > c ? d : c;

	return r;

}
int getMaxStolen(int l, int e)
{
	if (l >= e)return 0;	// Base condition
	
	if (dp[l])return dp[l];

	int sum = 0;

	return dp[l] = maxV(dp[l],arr[l] + getMaxStolen(l + 2, e), getMaxStolen(l + 1, e));

}

int main()
{
	int ans = getMaxStolen(0,SIZE);
    return 0;
}

