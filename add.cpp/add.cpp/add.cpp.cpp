// add.cpp.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<limits>
using namespace std;

void findsteps(long int x,long int y,long int L,long int *cnt_min,int cnt)
{

	if(x > L || y > L)
		return;
	if(x == L || y == L)
		if(*cnt_min > cnt)
		*cnt_min = cnt;

	findsteps(x+y,y,L,cnt_min,cnt+1);
	findsteps(x,y+x,L,cnt_min,cnt+1);

}
/*
int main()
{
	long int T,L;
	cin>>T;
	while(T--)
	{
	  cin>>L; 
	  long int cnt = INT_MAX;
	  findsteps(1,1,L,&cnt,0);
	  cout<<cnt<<endl;
 	}
	return 0;
}

*/