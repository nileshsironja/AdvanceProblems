// TestCpp.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
using namespace std;


class A
{
public:
	int arr[5];
	A()
	{cout<<"hi";
	}
};
class B: public A
{
	char arr[5];
public:
	void show()
	{
		cout<<arr[0];
	}
};
class C: public A
{};

class D:public B, public C
{
};


int _tmain(int argc, _TCHAR* argv[])
{
	A *a = (A*)malloc(sizeof(A));
	A *b;
	system("pause");
	return 0;
}

