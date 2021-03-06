// CoinChangeDP.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#define SIZE 3
using namespace std;

int coins[SIZE] = { 2,3,1 };

int coinChange(int N,int K)
{
	if (N < 0)return 0;
	if (N == 0)return 1;
	if (K < 0 && N >= 1)return 0;
	  
	return coinChange(N, K - 1) + coinChange(N - coins[K], K);
}

int main()
{

	cout<<"Num ways :"<<coinChange(4,SIZE-1);
    return 0;
}

