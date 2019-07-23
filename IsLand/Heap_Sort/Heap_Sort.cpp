// Heap_Sort.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#define SIZE 10
using namespace std;
//consider a complete binary tree
int arr[] = {8,74,58,24,63,12,45,41,65,14};


void heapify(int i,int sizes)
{
	int left = i*2+1, right = i*2+2;

	if(left >= sizes  && right >= sizes)
		return;

	int maxindex; 

	if(arr[right] > arr[left] && left < sizes &&  right < sizes)
		maxindex = right;
	else
		maxindex = left;

	if(arr[i] > arr[maxindex])
		maxindex = i;
	else
	{
		int temp = arr[i];
		arr[i] = arr[maxindex];
		arr[maxindex] = temp;
		heapify(maxindex,sizes);
	}
}


void heapsort()
{
	for(int i = (SIZE-1)/2; i >= 0 ; i--)
	{
		heapify(i,SIZE);
	} 

	//print max-heap array
	int sizes = SIZE - 1;
	for(int i=0;i<(SIZE-1/2);i++)
	{ 
		int temp = arr[0];
		arr[0] = arr[sizes - i];
		arr[sizes - i] = temp; 
		heapify(0,sizes - i);
	}
	for(int i=0 ; i<SIZE; i++)
		cout<<arr[i]<<"  ";
}


int main()
{
	heapsort();
	system("pause");
	return 0;
}

