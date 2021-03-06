// MaxSquare_ProfP.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
using namespace std;

#define SIZE 4
int matrix[SIZE][SIZE] = {

	 {1,0,1,1},
	 {1,1,1,0},
	 {1,1,1,0},
	 {1,0,0,0},

};

int retMin(int a, int b)
{
	if (a < b)return a;
	return b;
}

int main()
{
	int max = 0;
	for (int i = 1; i < SIZE; i++)
	{
		for (int j = 1; j < SIZE; j++)
		{
			if(matrix[i][j])
			matrix[i][j] = retMin(matrix[i][j - 1], retMin(matrix[i - 1][j - 1], matrix[i - 1][j])) + 1; 
			if (max < matrix[i][j])max = matrix[i][j];
		}
	}
	cout << max;

    return 0;
}

