// DistanceBTWno.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>

using namespace std;
#define SIZE 10
#define MAX 99999
int arr[SIZE] = {8,9,6,5,1,4,3,2,1,9};

int main()
{
	int x = 9, y = 1, dist = MAX;
	int index1= MAX, index2 = MAX;
	for (int i = 0; i < SIZE; i++)
	{
		if (arr[i] == x)
		{
			index1 = i;
		}
		if (arr[i] == y)
		{
			index2 = i;
		}
		if (index1 != MAX && index2 != MAX)
		{
		
			int d = index1 < index2 ? index2 - index1 : index1 - index2;
			if (d < dist)
			{
				dist = d;
			}
		}
	}
	cout << dist;
    return 0;
}

