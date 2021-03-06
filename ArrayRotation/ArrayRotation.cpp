// ArrayRotation.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>

using namespace std;
#define SIZE 3

int arr[SIZE] = {9,7,8};


int getRotatePos(int l, int r)
{
	if (l == r) // if only one element
	{
		return l;
	}


	int mid = l + (r - l) / 2;

	if (arr[mid] > arr[l] && arr[mid + 1] > arr[mid])
	{
		return getRotatePos(mid, r);
	}
	else if (arr[mid] < arr[l] && arr[mid - 1] < arr[mid])
	{
		return getRotatePos(l, mid);
	}
	else
		return mid;

}

int main()
{
	cout << "Rotation in array :" << getRotatePos(0, SIZE - 1);

    return 0;
}

