// Pattern_rec.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
using namespace std;

void pattern(int N,int K)
{ 
	if( K < 0 || K > N)
	{
		cout<<K<<" ";
		return;
	}
	cout<<K<<" ";
	pattern(N,K-5);
	cout<<K<<" ";
	//pattern(N,K+5); 

}


int main()
{
	int N,K;
	cin>>N;
	K = N;
	pattern(N,K);
	system("pause");
	return 0;
}

