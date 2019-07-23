// C++Practice.cpp : Defines the entry point for the console application.
//


#include "stdafx.h"
#ifdef ONCE
#include<iostream>
using namespace std;

void fun(double d)
{
	cout << d;

}
void fun(int d)
{
	cout << d;
}


int main()
{
	fun('c');
	
	
	return 0;
}

#endif