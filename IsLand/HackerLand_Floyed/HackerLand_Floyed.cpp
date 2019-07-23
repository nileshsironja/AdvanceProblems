// HackerLand_Floyed.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<math.h>
#include<iostream>
#define Maxs 99999
#define SIZE 401
using namespace std;

int N,M,Q,A,B,W;
int arr[SIZE][SIZE];

void floyed()
{
	for(int k=1;k<=N;k++)
	{
		for(int i=1;i<=N;i++)
		{
			for(int j=1;j<=N;j++)
			{
				if(arr[i][k] != Maxs && arr[k][j] != Maxs && arr[i][j] > (arr[i][k] + arr[k][j]))
				{
					arr[i][j] = (arr[i][k] + arr[k][j]);
				}
			}
		}
	}
}
int main()
{
	cin>>N>>M;

	for(int i=0;i<=N;i++)
	{
		for(int j=0;j<=N;j++)
		{
			arr[i][j] = Maxs;
			arr[j][i] = Maxs;
		}
	}

	for(int i=0;i<M;i++)
	{
		cin>>A>>B>>W;
		//if(arr[A][B] > W)
		{
			arr[A][B] = W;
			//arr[B][A] = W;
		}
	}

	floyed();
	cin>>Q;
	for(int i=0;i<Q;i++)
	{
		cin>>A>>B;
		if(A == B)
			cout<<"0"<<endl;
		else if(arr[A][B] == Maxs)
			cout<<"-1"<<endl;
		else
			cout<<arr[A][B]<<endl;
	}

	return 0;
}

