// GameSVCoffice.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#define HIGH 999999
using namespace std;

int a=9,b=3,c=1;

int globalCNT = HIGH;
int arr[] = {HIGH,HIGH,HIGH,HIGH,HIGH,HIGH};
int mins()
{
	int temp = HIGH;
	for(int i=0;i<6;i++)
	{
		if(arr[i] < temp)
			temp = arr[i];
	}
	return temp; 
}
int playGame(int A,int B,int C,int cnt)
{
	if(A < 0 && B < 0 && C < 0)  // base condition
	{
		if(globalCNT > cnt)
			globalCNT = cnt;
		
		return globalCNT;
	}
	//optimized condition
	if(globalCNT < cnt)
		return globalCNT;

	arr[0] = playGame(A-a, B-b, C-c, cnt+1);
	arr[1] = playGame(A-a, B-c, C-b, cnt+1);
	arr[2] = playGame(A-b, B-a, C-c, cnt+1);
	arr[3] = playGame(A-b, B-c, C-a, cnt+1);
	arr[4] = playGame(A-c, B-a, C-b, cnt+1);
	arr[5] = playGame(A-c, B-b, C-a, cnt+1);

	return mins();
}


int main()
{
	int A,B,C;
	cin>>A>>B>>C;

	globalCNT = HIGH;
	playGame(A,B,C,0);
	
	cout<<globalCNT<<endl;
	system("pause");
	return 0;
}

