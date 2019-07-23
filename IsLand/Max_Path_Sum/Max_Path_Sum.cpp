// Max_Path_Sum.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
using namespace std;

int ar1[] = {2,3,7,10,12,15,30,34};
int ar2[] = {1,5,7,8,10,15,16,19};

int S1 = 8, S2 = 8;
//array are sorted
int calculate()
{
	int max =0, maxsum = 0;
	int i,j;
	int arr1 = 0, arr2 = 0;
	for(i=0,j=0; i < S1 && j < S2 ; )
	{
		if(ar1[i] < ar2[j])
		  arr1 += ar1[i++];
		else if(ar2[j] < ar1[i])
		  arr2 += ar2[j++];

		if(ar1[i] == ar2[j])
		{
		  maxsum += arr1 > arr2 ? arr1 : arr2;
		  maxsum += ar1[i];
		  arr1 = 0; i++;
		  arr2 = 0; j++;
		} 
	}
	while(i < S1)
		maxsum += ar1[i++];
	while(i < S2)
		maxsum +=ar2[i++];

	return maxsum;
}

int main()
{
	 
	cout<<"max path sum is : "<<calculate();
	system("pause");
	return 0;
}

