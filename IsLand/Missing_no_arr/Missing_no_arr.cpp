// Missing_no_arr.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#define S 4
using namespace std;

int arr[S] = {4,5,10,11};

int find(int l,int h)
{
	if(l > h)
		return -1;
	else
	{
	   int mid = l + (h-l)/2;
	   if(mid > 0 && mid < S-1 && arr[mid-1] + 1 == arr[mid] && arr[mid+1] -1 == arr[mid])
	   {
			int val = find(l,mid-1);
			if(val == -1)
			return find(mid+1,h);
			else return val;
	   }
	   else if(mid == 0 && arr[mid+1] -1 == arr[mid])
	   {
			int val = find(l,mid-1);
			if(val == -1)
			return find(mid+1,h);
			else return val;
	   }
	   else if(mid == S-1 && arr[mid-1] + 1 == arr[mid])
	   {
			int val = find(l,mid-1);
			if(val == -1)
			return find(mid+1,h);
			else return val;
	   }
	   else
	   {
			if(arr[mid-1] != arr[mid] + 1)
				return mid;
			else if(arr[mid] != arr[mid+1] - 1)
				return mid+1;
			//else
				//return mid+1;
	   }
	
	}

}

int main()
{
	

	cout<<"Missing no is : "<<find(0,S)+1<<endl;

	system("pause");
	return 0;
}

