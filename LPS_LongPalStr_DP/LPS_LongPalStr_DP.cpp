// LPS_LongPalStr_DP.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#define SIZE 13
using namespace std;

char str[] = "geeksforgeeks";

int max(int a, int b)
{
	if (a > b)
		return a;
	return b;
}

//solved through recursion
int lps_rec(int i,int j)
{
	//base case, if only one char
	if (i == j)
		return 1;
	//base case, if only two chars
	if (i + 1 == j && str[i] == str[j])
		return 2;
	//if more than two chars, and index i,j matches
	if (str[i] == str[j])
		return lps_rec(i + 1, j - 1) + 2;
	//there are 2 cases i+1 or j-1

	return max(lps_rec(i + 1, j), lps_rec(i, j - 1));	 
}
//solved through dynamic programming
int lps_dp()
{
	int dp[SIZE][SIZE];

	memset(dp, 0, sizeof(dp));
	for (int i = 0; i < SIZE; i++)
		dp[i][i] = 1;


	for (int c = 2; c <= SIZE; c++)
	{
		for (int i = 0; i < SIZE-c+1; i++)
		{
			int j = i + c - 1;
			//base case, if only two chars
			if (i + 1 == j && str[i] == str[j])
				dp[i][j] = 2;
			//if more than two chars, and index i,j matches
			if (str[i] == str[j])
				dp[i][j] = dp[i + 1][j - 1] + 2;
			else
				dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]); 
		}
	}
	return dp[0][SIZE - 1];
}

int main()
{
	cout<<"Length of lps : "<<lps_rec(0, SIZE-1);

	cout << "Length of lps : " << lps_dp();

    return 0;
}





