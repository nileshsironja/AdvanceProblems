// Array_2nQue.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
using namespace std;

#define MAX 20

int arr[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
 
void display()
{
	for(int i=0;i<MAX;i++)
		cout<<arr[i]<<" ";
}

void swap(int a, int b)
{
	int temp = arr[a];
	arr[a] = arr[b];
	arr[b] = temp;
}

void sufflearray(int f,int l)
{
	if(l-f <= 1)return;
	if(f < 0 || l >= MAX) return;

	int mid = (f + l)/2 ;

	int temp = mid + 1;

	int mmid = (mid + f)/2;

	for(int i = mmid+1; i <= mid ; i++,temp++)
	{
		swap(i,temp);
	}

	sufflearray(f,mid);
	sufflearray(mid+1,l); 
}

int main(int argc, _TCHAR* argv[])
{

	display();
	sufflearray(0,MAX-1);
	cout<<"Result Array :\n";
	display();
	system("pause");
	return 0;
}

