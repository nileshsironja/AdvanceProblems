// NimGame.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#define SIZE 101
using namespace std;

long long int g,n,s;


int main()
{
	long long int ans = 0;

	cin>>g;
	while(g--)
	{
		cin>>n;
		ans = 0;
		while(n--)
		{
			cin>>s;
			ans = ans ^ s;
		}
		if(ans)cout<<"First"<<endl;
		else cout<<"Second"<<endl;
	}
	  
	return 0;
}

