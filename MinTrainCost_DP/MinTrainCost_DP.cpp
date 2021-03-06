// MinTrainCost_DP.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#define SIZE 4
#define MAXCOST 9999
#define INF 9999
using namespace std;

int cost[SIZE][SIZE] = {
	{ 0, 15, 80, 90 },
{ INF, 0, 40, 50 },
{ INF, INF, 0, 70 },
{ INF, INF, INF, 0 }

};

int price[SIZE] = { 0 }; 
int getMinCost(int n)
{ 
	for (int i = 0; i < SIZE; i++)
		price[i] = INF;

	price[0] = 0;
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = i+1; j < SIZE; j++)
		{
			if (  price[j] > (price[i] + cost[i][j]))
			{
				price[j] = price[i] + cost[i][j];
			} 
		}
	}
	return price[n-1]; 
}


int main()
{
	
	int a, b, c;

	a = 1000000000;
	b = 1000000000;
	c = 3;
	c = (a%c * b%c) % c;

	cout << c;
	cout << "Min Price :" << getMinCost(3);
	return 0;
}





