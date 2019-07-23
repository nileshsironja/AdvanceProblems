// Max_Prod_arr.cpp : main project file.

#include "stdafx.h"
#include<iostream>

using namespace std;


int findmaxarr(int arr[],int n)
{
  int i,maxsum=1,sum=1;

  for(i=0;i<n;i++)
  {
    sum = sum * arr[i];
	if(sum == 0)
	    sum = 1;
	if(maxsum < sum)
		maxsum = sum; 
  }
  return maxsum;

}

//kadane's algorithm
int main()
{
	int arr[] = {-1, -3, -10, 0, 60};
	int n = sizeof(arr)/sizeof(arr[0]);
	//cout<<n;
	cout<<"\nmax prod subarray :"<<findmaxarr(arr,n);

	system("pause");
	return 0;
}