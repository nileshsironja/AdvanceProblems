// subArray_Sum.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#define S 2
using namespace std;

int arr[S] = {1,4};

int j = 0, i = 0;

int cal_sum = 0, sum = 0;

void get_subarray()
{
	for(i=0;i<S;i++)
	{
		cal_sum += arr[i];
		if(cal_sum == sum)
		{
			cout<<endl<<"Sum is given bw index "<<j<<" and "<<i;
			break;
		}

		while(cal_sum > sum && j < i)
			cal_sum -= arr[j++];

		if(cal_sum == sum)
		{
			cout<<endl<<"Sum is given bw index "<<j<<" and "<<i;
			break;
		} 
	}
	if(cal_sum != sum)
		cout<<endl<<"no subarray found";
}


int main()
{ 
	get_subarray();

	system("pause");

	return 0;
}

