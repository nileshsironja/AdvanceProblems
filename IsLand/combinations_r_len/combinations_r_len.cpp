// combinations_r_len.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#define S 5
using namespace std;

int arr[S] = {1,2,3,4,5};;
int r;
int comb[S];
void find_r_len_comb(int n)
{
	if(n == r)
	{
		for(int i = 0; i < r; i++)
			cout<<comb[i]<<" ";
		cout<<endl;
		return;
	}
	
	for(int i = 0 ;i < S; i++)
	{
		comb[n] = arr[i];
		find_r_len_comb(n+1); 
		 
	}
}

int main()
{
	
	cout<<"enter r :";
	cin>>r;

	find_r_len_comb(0);

	system("pause");
	return 0;
}

