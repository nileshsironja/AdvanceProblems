// C++Practice.cpp : Defines the entry point for the console application.
//


#include "stdafx.h"
#include<iostream>
using namespace std;
#ifdef ONCE

int main()
{
	int a = 5;
	cout << sizeof(a++);

    return 0;
}

#endif