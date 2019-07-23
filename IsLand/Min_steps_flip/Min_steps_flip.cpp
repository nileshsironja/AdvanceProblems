// Min_steps_flip.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
using namespace std;
int steps = 0;

/*

Find the most optimal way to reach a given number x, if we can indeed reach it. 
For example, 3 can be reached om 2 steps, (0, 1) (1, 3) and 4 can be reached in 3 steps (0, -1), (-1, 1) (1, 4).

*/
int min(int a,int b)
{
   return a>b?b:a;
}
int minstep(int n, int i, int step)
{

	if(abs(i) > n)
	 return INT_MAX;

	if(i == n)
	 return step;

	/*if(minstep(n,steps-1) && minstep(n,steps+1))
	{
		steps++;
		return steps;
	}*/

	int pos = minstep(n, i+step+1, step+1);
	int neg = minstep(n, i-step-1, step+1);

	return min(pos,neg);

}



int main()
{
	cout<<"Enter N";
	int n;
	cin>>n;
	cout<<minstep(n,0,0);

	system("pause");

	return 0;
}

