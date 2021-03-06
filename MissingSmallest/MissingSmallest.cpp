// MissingSmallest.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
using namespace std;
#define SIZE 15

int arr[] = {1,2,3,5,6,-5,9,-75,12,76,-96,-4,57,69,52};

int main()
{
	//segregate +ve n -ve numbers
	int i = 0, j = SIZE - 1;

	while (i < j)
	{
		while (i < j && arr[i] > 0)i++;
		while (i < j && arr[j] < 0)j--;
		//swap
		int temp = arr[i];
		arr[i] = arr[j];
		arr[j] = temp;
	}

	int posR = 0;
	for (int i = 0; i < SIZE; i++)
		if (arr[i] < 0) { posR = i; break; }

	for (int i = 0; i < posR; i++)
	{
		if (arr[i] > 0)
		{
			arr[arr[i]] = -arr[arr[i]];
		}
		else
		{
			arr[-arr[i]] = -arr[-arr[i]]; 
		}
	}

	int done = 0;
	for (int i = 1; i < posR; i++)
	{
		if (arr[i] > 0)
		{
			cout << i << " ";
			done = 1;
			break;
		}
	}
	if (!done)
		cout << i << " ";

    return 0;
}

