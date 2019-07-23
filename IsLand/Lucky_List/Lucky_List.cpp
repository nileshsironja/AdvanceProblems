// Lucky_List.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<math.h>
#include<string.h>
#define S 11
using namespace std;

int counts = 0;
int arr[S];
int N,M;	

void luckylist(int n,int pos)
{
	if(n <= M && pos < N-1)
	{
		arr[pos] = n;
		luckylist(n*2,pos+1);
		for(int j = n*2 + 1 ; j <= M ; j++)
		{
			luckylist(j,pos+1);
		}
	}
	else
	{
		if(pos == N-1 && n <= M)
		{
			arr[pos] = n;
			for(int j = 0 ; j <= pos ; j++)
			{
				cout<<" "<<arr[j];
			}
			cout<<endl;
			counts++;
		} 
	}

}


int main()
{

	cin>>N>>M;

	memset(arr,0,sizeof(arr));

	for(int j = 1; j <= M/pow(2,(double)N-1) ; j++)
	{
		luckylist(j,0);
	}
	cout<<endl<<"count is :"<<counts;
	system("pause");
	
	return 0;
}

