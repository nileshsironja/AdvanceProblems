// MinReach.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
using namespace std;
#define SIZE 11

int arr[SIZE] = { 1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9 };

int gsteps = 99;

int getMin(int s,int h)
{
	if (s == h)
		return 0;

	int min = 99;
	for (int i = s+1; i <= s+arr[s] && i<SIZE; i++)
	{
		int get = getMin(i, h);
		if (get + 1 < min)
		{
			min = get + 1;
		}
		
	}
	return min;
}


int main()
{

	cout << getMin(0,SIZE-1);

    return 0;
}

