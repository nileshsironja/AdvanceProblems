// Array_Median.cpp : main project file.

#include "stdafx.h"
#include<iostream>

using namespace System;

int median(int arr[],int n)
{
	if(n%2 == 0)
		return (arr[n/2] + arr[n/2-1])/2;
	else
		return arr[n/2];

}

int getMedian(int arr[],int prr[],int n)
{
	if(n<=0)return -1;
	if(n == 1) return (arr[0]+prr[0])/2;
	if(n == 2) return ((arr[0]>prr[0]?arr[0]:prr[0])+(arr[1]<prr[1]?arr[1]:prr[1]))/2;

	int m1= median(arr,n);
	int m2= median(prr,n);

	if(m1 == m2)
		return m1;

	if(m1 < m2)
	{
		if(n%2 == 0)
		return getMedian(arr+n/2-1,prr,n/2);
		else
		return getMedian(arr+n/2,prr,n/2);
	}
	else
	{
		if(n%2 == 0)
		return getMedian(prr+n/2-1,arr,n/2);
		else
		return getMedian(prr+n/2,arr,n/2);
	} 
}

//1 2 12 13 15 17 26 30 38 45

int main()
{
	int ar1[] = {1, 12, 15, 26, 38};
    int ar2[] = {2, 13, 17, 30, 45};
 
    int n1 = sizeof(ar1)/sizeof(ar1[0]);
    int n2 = sizeof(ar2)/sizeof(ar2[0]);
    if (n1 == n2)
        printf("Median is %d", getMedian(ar1, ar2, n1));
    else
        printf("Doesn't work for arrays of unequal size");
    getchar();
    return 0;

}