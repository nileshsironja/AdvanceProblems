// Templates.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
using namespace std;

template<typename T>
 
T getmax(T a,T b)
{
	return a>b?a:b;
}

int _tmain(int argc, _TCHAR* argv[])
{
	template<int> getmax(5,6);
	return 0;
}

