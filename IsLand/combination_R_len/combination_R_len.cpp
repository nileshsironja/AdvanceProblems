// combination_R_len.cpp : Defines the entry point for the console application.
//

//http://www.geeksforgeeks.org/combinations-with-repetitions/

#include "stdafx.h"
#include<iostream>
#define SIZE 10
using namespace std;

int N;
int R;
int number[SIZE];
int comb[SIZE];

void print()
{
	for(int i=0;i<R;i++)
		cout<<comb[i];
}
//http://www.geeksforgeeks.org/combinations-with-repetitions/
void printComb(int start,int end,int index)
{
	if(index == R)
	{
		print();
		cout<<endl;
		return;
	}

	for(int i=start; i<end; i++)
	{
		comb[index] = number[i];
		printComb(i+1,end,index+1); 
	} 
}

//http://www.geeksforgeeks.org/combinations-with-repetitions/

int main()
{
	cin>>N;
	for(int i=0;i<N;i++)
		cin>>number[i];

	cin>>R;

	printComb(0,N,0);

	system("pause");

	return 0;
}

