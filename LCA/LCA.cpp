// LCA.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

// Sample code to perform I/O:

#include <iostream>

using namespace std;

int arr[43];
int m;

int sum = 0;
void rec(int p)
{

	for (int i = p; i <= m; i++)
	{
		sum += arr[i];
		rec(p + 1);
	}

}

int main() {
	int num;
	cin >> num;										// Reading input from STDIN

	for (int i = 1; i <= 42; i++)
		arr[i] = i;

	while (num--)
	{
		cin >> m;
		rec(1);
		cout << sum << endl;



	}

}

// Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail


// Write your code here
