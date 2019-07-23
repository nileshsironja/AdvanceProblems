// Swiggy.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<vector>
using namespace std;


int gcd(int a, int b)
{
	// Everything divides 0  
	if (a == 0 || b == 0)
		return 0;

	// base case 
	if (a == b)
		return a;

	// a is greater 
	if (a > b)
		return gcd(a - b, b);
	return gcd(a, b - a);
}

//int main()
//{
//	cout << gcd(5, 7);
//
//	return 0;
//}

int dodfs(bool matrix[50][50], int i, int no, int n, int ch)
{
	if (i > n)
		return 0;
	if (ch == no)
		return 1;

	for (int j = i + 1; j < n; j++)
	{
		if (matrix[i][j] && dodfs(matrix,i, no, n, j) == 1)
		{
			return 1;
		}
	}
	return 0;


}


vector<int> connectedCities(int n, int g, vector<int> originCities, vector<int> destinationCities) {

	bool matrix[50][50] = { 0,0 };
	memset(matrix, 0, sizeof(matrix));
	vector<int> result;



	vector<int>::iterator itO = originCities.begin();
	vector<int>::iterator itD = destinationCities.begin();
	int gcdN = 0;

	for (int i=1;i<n;i++) 
	{
		vector<int>::iterator itD = destinationCities.begin();
		for (int j=i+1;j<n;j++)
		{
			gcdN = gcd(i, j);
			if (gcdN > g)
				matrix[i][j] = true;
			else
				matrix[i][j] = false;
		}

	}
	itO = originCities.begin();
	itD = destinationCities.begin();

	for (; itO != originCities.end(); itO++, itD++)
	{

		if(dodfs(matrix,*itO,*itD,n,0))
			result.push_back(1);
		else
			result.push_back(0);
	}

	return result;
}
