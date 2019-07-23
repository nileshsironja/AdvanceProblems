// TopOfHead.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
using namespace std;

long long int arr[80001];
long long int stack[80001][2];

//10 ans 19
//9 8 5 4 7 2 6 8 3 4
//0 1 2 3 4 5 6 7 8 9
 
// 4 - 3 - 1 = 0 
// 4 - 2 - 1 = 1
// 6 - 5 - 1 = 0
// 7 - 6 - 1 = 0
// 7 - 4 - 1 = 2
// 7 - 1 - 1 = 5
// 9 - 8 - 1 = 0
// 9 - 7 - 1 = 1
// 9 - 0 - 1 = 8

int main()
{
	int N;
	cin>>N;
	int i;
	for(i=0;i<N;i++)
		cin>>arr[i];

	int top = 0;
	stack[top][0] = arr[0];
	stack[top][1] = 0;
	long long int counts = 0;
	for(i=1;i<N;i++)
	{
		if(top>=0 && arr[i] >= stack[top][0])
		{
			while(top>=0 && arr[i] >= stack[top][0])
			{
				counts += i - stack[top][1] - 1;
				cout<<endl<<" i-stack[top][1] "<<i<<" - "<<stack[top][1]<<" -1 ";
				top--;
			}
			if(top < 0) 
				top = 0;  
			else
				top = top + 1;
		}
		else
		   top = top + 1;
	    
		stack[top][0] = arr[i];
		stack[top][1] = i;
		 
	}
	//empty the stack
	while(top >= 0)
	{
		counts += N - 1 - stack[top][1];
		cout<<endl<<" i-stack[top][1] "<<i<<" - "<<stack[top][1];
		top--;
	}
	cout<<" "<<counts;
	system("pause");
	return 0;
}

