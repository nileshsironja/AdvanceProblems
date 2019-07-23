// C++Practice.cpp : Defines the entry point for the console application.
//


#include "stdafx.h"
#include<iostream>
using namespace std; 
#ifdef ONCE

template<class X>void swaps(X &a, X &b)
{
	X temp;
	temp = a;
	a = b;
	b = temp; 
}

int main()
{
	int a = 10, b = 20;
	char aa = 'a', ba = 'b';

	swaps(a, b);
	cout << a << b << endl;
	swaps(aa, ba);
	cout << aa << ba << endl;

    return 0;
}

#endif