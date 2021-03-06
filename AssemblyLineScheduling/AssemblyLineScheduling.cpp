// AssemblyLineScheduling.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#define NUM_STATION 4
using namespace std;


int carAssembly(int a[][NUM_STATION], int time[][NUM_STATION], int entry[], int exit[],int line, int i)
{
	if (i >= NUM_STATION)
	{
		return exit[line];
	}

	int sum = 0, sumE=0;
	sum = a[line][i] + carAssembly(a, time, entry, exit, line, i + 1);
	//switch line
	if (line == 0)
	{
		sumE = a[line][i] + time[line][i-1] + carAssembly(a, time, entry,  exit, 1, i + 1);
	}
	else if (line == 1)
	{
		sumE = a[line][i] + time[line][i-1] + carAssembly(a, time, entry, exit, 0, i + 1);
	}

	return sum < sumE ? sum : sumE; 
}

int main()
{
	int a[][NUM_STATION] = { { 4, 5, 3, 2 },
	{ 2, 10, 1, 4 } };
	int t[][NUM_STATION] = { { 0, 7, 4, 5 },
	{ 0, 9, 2, 8 } };
	int e[] = { 10, 12 }, x[] = { 18, 7 };

	int firstLineEntry = e[0] + carAssembly(a, t, e, x,0,1);
	int secondLineEntry = e[1] + carAssembly(a, t, e, x,1,1);
	if (firstLineEntry > secondLineEntry)
		cout << firstLineEntry;
	else
		cout << secondLineEntry;
 
	return 0;
}

// Ans : 35







