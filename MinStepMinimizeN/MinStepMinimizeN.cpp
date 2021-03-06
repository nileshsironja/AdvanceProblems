// MinStepMinimizeN.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#define N 20
using namespace std;

int memo[N] = { 0 };

int min(int a, int b)
{
	if (a < b)
		return a;
	return b;
}

int MinStepMinimizeN(int n)
{
	if (n == 0)
		return 0;

	if (memo[n] != 0)
		return 1;

	int res = 0;
	
	res = MinStepMinimizeN(n - 1);

	if (n % 2 == 0)
		res = min(res, MinStepMinimizeN(n / 2));

	if (n % 3 == 0)
		res = min(res, MinStepMinimizeN(n / 3));

	memo[n] = 1 + res;

	return memo[n];


}

int main()
{
	cout<<" "<<MinStepMinimizeN(10); 
	return 0;
}

