// LIS.cpp : main project file.

#include "stdafx.h"
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;

/*
Building bridges
Maximum sum increasing subsequence
longest chain 
*/


int lis(int arr[],int n)
{
	int *ls = (int*)malloc(sizeof(int)*n);

	int i,j;

	memset(ls,0,sizeof(int)*n);
	for(i=0;i<n;i++)
	{
		ls[i] = 1;
		for(j=i-1;j>=0;j--)
		{
			if((arr[i] > arr[j]) &&(ls[j]+1 > ls[i]))
				ls[i] = ls[j] + 1;
		}
		cout<<endl<<ls[i];
	}
	j = 0; //utilize as max
	for(i=0;i<n;i++)
	{
		if(j < ls[i])
			j = ls[i];
	}
	return j; 
}

/* Driver program to test above function */
int main()
{
	int arr[] = { 10, 22, 9, 33, 21, 50, 41, 60, 80 };
    int n = sizeof(arr)/sizeof(arr[0]);
    printf("Length of LIS is %d\n",  lis( arr, n ));
	system("pause");
    return 0;
}