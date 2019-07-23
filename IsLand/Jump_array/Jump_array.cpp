// Jump_array.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
using namespace std;


//Input: arr[] = {1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9}
//Output: 3 (1-> 3 -> 8 ->9)

int minjump(int arr[],int n,int min,int index)
{
	if(n <= 0)
		return INT_MAX;
	if(index >= n)
		return 0;

	int minjumps = INT_MAX;
	for(int i=index+1; i < n && i < index + arr[index]; i++)
	{
		int res = minjump(arr,n,minjumps,i);

		if(res != INT_MAX && res + 1 < minjumps)
			minjumps = res + 1;
	
	}

	return minjumps;

}

int main()
{ 
	int arr[] = {1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9};
	int sizes = sizeof(arr);
	cout<<sizes;
	cout<<minjump(arr,sizeof(arr)/sizeof(arr[0]),INT_MAX,0);

	system("pause");
	return 0;
}

