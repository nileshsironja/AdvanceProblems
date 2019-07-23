// rearrage_array.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
using namespace std;

int arr[] = {3,2,0,1};


void rearrage()
{
	int index,temp,ele,cnt;

	int size = sizeof(arr)/sizeof(arr[0]);
	int i;
	ele = 0,index = 0,cnt = 0;
	ele = arr[index];
	while(cnt < size)
	{
		for(i=0;i<size;i++)
			if(index == arr[i])
				break;
		index = i; temp = ele;
		ele = arr[index];
		arr[index] = temp;
		cnt++;

	}
	for(i=0;i<size;i++)
		cout<<arr[i]<<" ";

}


int main()
{
	rearrage();
	return 0;
}

