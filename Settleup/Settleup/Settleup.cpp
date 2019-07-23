// Settleup.cpp : main project file.

#include "stdafx.h"
#include<iostream> 
#define N 3
using namespace System;


int main()
{

	int graph[N][N] = { {0, 1000, 2000},
                        {0, 0, 5000},
                        {0, 0, 0},};
 
	int i,j;
	for(i=0;i<N;i++) //row
	{
		for(j=0; graph[i][j] && j<N ;j++) //col
		{		

		  
		}
	}


    // Print the solution
    //minCashFlow(graph);
}