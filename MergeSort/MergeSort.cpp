// MergeSort.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
using namespace std;

#define size 10

int arr[] = { 363,6785,252,634,767,7644,563,656,4733,4345 };
int b[size];
void merge(int L, int mid, int R)
{

	int i = L;
	int j = mid + 1;
	int k = 0;
	while (i <= mid && j <= R)
	{
		if (arr[i] < arr[j])b[k++] = arr[i++];
		else if (arr[i] >= arr[j])b[k++] = arr[j++];
	}

	while (i <= mid)b[k++] = arr[i++];
	while (j <= R)b[k++] = arr[j++];

	i = L;
	for (int ptr = 0; ptr < k; ptr++)
		arr[i++] = b[ptr];


}
void sort(int L, int R)
{

	if (L < R)
	{
		int mid = L + (R-L) / 2;
		sort(L, mid);
		sort(mid + 1, R);
		merge(L, mid, R);
	}
}

int main()
{
	sort(0,size-1);
	for (int i = 0; i < size; i++)
		cout << arr[i] << " ";
    return 0;
}

