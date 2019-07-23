// superDigit.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
using namespace std;

int n,p;

int getsum(int n)
{
	if(n/10 == 0)
	  return n;
	
	return n%10 + getsum(n/10);
}

int main()
{
	
	cin>>n>>p;
	
	long long sum = n;
	while(sum/10)
	{
		sum = getsum(sum); 
	}

	sum = p*sum;
	
	while(sum/10)
	{
		sum = getsum(sum); 
	}

	cout<<sum<<endl;

	//system("pause");
	return 0;
}

