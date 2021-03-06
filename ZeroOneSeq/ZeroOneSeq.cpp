// ZeroOneSeq.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
using namespace std;
#define SIZE 15

int arr[SIZE] = { 1,1,1,1,1,1,1,1,1,1,1,0,0,0,0};

int main()
{

	int left = 0, right = SIZE - 1;
	int mid;

	while (left < right)
	{
		mid = left + (right - left) / 2;

		if ((arr[mid] == 0 && arr[mid - 1] == 1) || (arr[mid] == 1 && arr[mid + 1] == 0))
		{
			break;
		}
		else if (arr[mid] == 1 && arr[mid + 1] == 1)
			left = mid;
		else if (arr[mid] == 0 && arr[mid - 1] == 0)
			right = mid;
	}
	cout << mid;
	
	return 0;
}

