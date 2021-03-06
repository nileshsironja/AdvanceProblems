// CuttingRod_DP.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<ctime>
#define SIZE 8
using namespace std;


int price[SIZE] = { 1, 5, 8, 9, 10, 17, 17, 20 };
int dp[SIZE];

int max(int a, int b)
{
	if (a > b)
		return a;
	return b;
}
 
int getMaxPrice_(int n)
{
	if (n <= 0)
		return 0;
	int maxP = 0;

	for (int i = 0; i < n; i++)
	{
		maxP = max(maxP, price[i] + getMaxPrice_(n-i-1));
	}
	return maxP;
}
 
//DP 
int getMaxPrice(int n)
{
	if (n <= 0)
		return 0;
	if (dp[n])return dp[n];

	int maxP = 0;

	for (int i = 0; i < n; i++)
	{
		maxP = max(maxP, price[i] + getMaxPrice(n - i - 1));
	}
	dp[n] = maxP;
	return dp[n];
}

int main()
{
	const clock_t begin_time = clock();
	// do something
	
	cout << endl << "Max price :" << getMaxPrice_(SIZE);

	std::cout << float(clock() - begin_time) / CLOCKS_PER_SEC;

    return 0;
}
