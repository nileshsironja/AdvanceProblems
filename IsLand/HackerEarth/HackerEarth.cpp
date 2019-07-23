// HackerEarth.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
using namespace std;
long long int arr[1000001];
int main()
{
	long long int N,Q,M,no,prod = 1;
	cin>>N>>Q>>M;
	for(long long int i=0;i<N;i++)
	{
		cin>>no;
		arr[i] = no;
		prod = (prod * no);
	}
	long long int q;
	for(long long int i = 0;i<Q;i++)
	{
		cin>>q;
		long long int ans = (prod/arr[q-1])%M;
		cout<<ans<<endl;
	}
	//system("pause");
	return 0;
}
/*
5 3 100
1 2 3 4 5
1
2
4



*/


//int main()
//{
//
//
//
//	return 0;
//}



//int main()
//{
//
//
//
//	return 0;
//}
//
