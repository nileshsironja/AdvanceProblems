// BitsAanagram.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
using namespace std;

int isset(int no, int move)
{
	if (no &	(1 << move))
		return 1;
	return 0; 
}

int isAnagram(int a)
{
	int l = 0, r = 32;
	int count = 0;
	while ( l < r )
	{
		if (isset(a, l))
			count++;
		l++;
	} 
	return count;
}

int main()
{
	int a = 3, b = 12;

	if (isAnagram(a) == isAnagram(b))
		cout << endl << "Anagram";
	else
		cout << endl << "Not an Anagram";

    return 0;
}

