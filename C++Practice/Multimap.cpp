// C++Practice.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#ifdef ONCE
#include<map>
#include<iostream>
using namespace std;

int main()
{
	multimap<int,int>  mmap;


	mmap.insert(pair<int,int>(5, 5));
	mmap.insert(pair<int, int>(2, 25));
	mmap.insert(pair<int, int>(3, 65));
	mmap.insert(pair<int, int>(6, 56));
	mmap.insert(pair<int, int>(3, 15));

	multimap<int, int> :: iterator it;

	/*for (it = mmap.begin(); it != mmap.end(); it++)
	{
		cout << it->first << " " << it->second << endl;
	}*/

	it = mmap.find(3);
	int count = mmap.count(3);
	cout << count << endl;
	for (int i=0; i<count; i++)
		cout << it->first << " " << it->second << endl;


	return 0;
}
#endif







