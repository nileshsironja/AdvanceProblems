// Coin_change.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<limits.h>
#define Size 100
using namespace std;

int table[Size];

int min_coin(int coin[],int V, int m)
{
	int i,j;
	int res = INT_MAX;
    table[0] = 0;

	for(i=1;i<=V;i++)
		table[i] = INT_MAX;

	for(i=1;i<=V;i++)
	{
		int res_diff = INT_MAX;
		for(j=0;j<m;j++)
		{
			if(i >= coin[j])
			{
				res_diff = table[i-coin[j]];
				if(res_diff != INT_MAX && table[i] >= res_diff + 1)
					table[i] = res_diff + 1;
			}
		}
	} 
	return table[V];
}


int main()
{

	int coin[] = {9,5,6,1};
	int V = 11;
	int m = sizeof(coin)/sizeof(coin[0]);
	cout<<"min coin required :"<<min_coin(coin,V,m);
	system("pause");
	return 0;
}

