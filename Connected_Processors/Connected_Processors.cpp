// Connected_Processors.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#define SIZE 20
using namespace std;

int matrix[SIZE][SIZE];
int ROW, COL;
int leftline(int i,int j,int flag)
{
	int jp = j;

	//remove line
	if (flag == 0)
	{
		while (j >= 0)
		{
			if (matrix[i][j] == 2)
				matrix[i][j--] = 0;
		}
	}
	else //add line
	{
		while (j >= 0)
		{
			if (matrix[i][j] == 1 || matrix[i][j] == 2)
				return 0;
			j--;
		}
		while (jp >= 0)
		{
			matrix[i][jp--] = 2;
		} 
	}
	return 1;
}
int rightline(int i, int j, int flag)
{
	int jp = j;

	//remove line
	if (flag == 0)
	{
		while (j < COL)
		{
			if (matrix[i][j] == 2)
				matrix[i][j++] = 0;
		}
	}
	else //add line
	{
		while (j < COL)
		{
			if (matrix[i][j] == 1 || matrix[i][j] == 2)
				return 0;
			j++;
		}
		while (jp < COL)
		{
			matrix[i][jp++] = 2;
		}
	}
	return 1;
}

int upline(int i, int j, int flag)
{
	int ip = i;

	//remove line
	if (flag == 0)
	{
		while (i >= 0)
		{
			if (matrix[i][j] == 2)
				matrix[i--][j] = 0;
		}
	}
	else //add line
	{
		while (i >= 0)
		{
			if (matrix[i][j] == 1 || matrix[i][j] == 2)
				return 0;
			i--;
		}
		while (ip >= 0)
		{
			matrix[ip--][j] = 2;
		}
	}
	return 1;
}

int downline(int i, int j, int flag)
{
	int ip = i;

	//remove line
	if (flag == 0)
	{
		while (i >= 0)
		{
			if (matrix[i][j] == 2)
				matrix[i++][j] = 0;
		}
	}
	else //add line
	{
		while (i >= 0)
		{
			if (matrix[i][j] == 1 || matrix[i][j] == 2)
				return 0;
			i++;
		}
		while (ip >= 0)
		{
			matrix[ip++][j] = 2;
		}
	}
	return 1;
}

int cores[7][2] = { 0 };
int N;
int FinalLen = 999999;
int MaxProC = 0;
void recur(int index,int totcore,int len)
{
	if (index == N - 1)
	{
		if (FinalLen > len)
		{
			FinalLen = len;
		}
		if (MaxProC < totcore)
		{
			MaxProC = totcore;
			FinalLen = len; 
		} 
	}

	//dir 1, left line
	if (leftline(cores[index][0], cores[index][1], 1))
	{
		len = len + (cores[index][1] + 1);
		totcore = totcore + 1;
		recur(index + 1, totcore, len);
		leftline(cores[index][0], cores[index][1], 0); //removing line
		len = len - (cores[index][1] + 1);
		totcore = totcore - 1;
 	}
	//dir 2, right line
	if (rightline(cores[index][0], cores[index][1], 1))
	{
		len = len + (COL - cores[index][1] - 1);
		totcore = totcore + 1;
		recur(index + 1, totcore, len);
		rightline(cores[index][0], cores[index][1], 0); //removing line
		len = len - (COL - cores[index][1] - 1);
		totcore = totcore - 1;
	}
	//dir 3, up line
	if (upline(cores[index][0], cores[index][1], 1))
	{
		len = len + (cores[index][0] + 1);
		totcore = totcore + 1;
		recur(index + 1, totcore, len);
		upline(cores[index][0], cores[index][1], 0); //removing line
		len = len - (cores[index][0] + 1);
		totcore = totcore - 1;
	}
	//dir 2, down line
	if (downline(cores[index][0], cores[index][1], 1))
	{
		len = len + (ROW - cores[index][0] - 1);
		totcore = totcore + 1;
		recur(index + 1, totcore, len);
		downline(cores[index][0], cores[index][1], 0); //removing line
		len = len - (ROW - cores[index][0] - 1);
		totcore = totcore - 1;
	}
	recur(index+1, totcore, len);
}



int main()
{
		



    return 0;
}

