// 1_1_to_N_N_path.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
/*
0 0 0
0 0 0
0 0 0

*/

#include <iostream>
using namespace std;
int counts[5][5];
// Returns count of possible paths to reach cell at row number m and column
// number n from the topmost leftmost cell (cell at 1, 1)
int  numberOfPaths(int m, int n)
{
	// If either given row number is first or given column number is first
	if (m == 1 || n == 1)
		return 1;
	if (counts[m][n])return (counts[m][n]);
	// If diagonal movements are allowed then the last addition
	// is required.
	return (counts[m][n] = numberOfPaths(m - 1, n) + numberOfPaths(m, n - 1));
	// + numberOfPaths(m-1,n-1);
}
// Returns count of possible paths to reach cell at row number m and column
// number n from the topmost leftmost cell (cell at 1, 1)
int  numberOfPaths______(int m, int n)
{
	// If either given row number is first or given column number is first
	if (m == 1 || n == 1)
		return 1;

	// If diagonal movements are allowed then the last addition
	// is required.
	return  numberOfPaths(m - 1, n) + numberOfPaths(m, n - 1);
	// + numberOfPaths(m-1,n-1);
}
int main()
{
	cout << numberOfPaths(3, 3);
	return 0;
}