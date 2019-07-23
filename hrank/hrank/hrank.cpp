// hrank.cpp : main project file.

#include "stdafx.h"
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <list>
using namespace std;


int main() {
   
	int n,k;
	list<int> lst;
	cin>>n;
	while(n--)
	{
	  cin>>k;
	  int no;
	  while(k--)
	  {
	    cin>>no;
		lst.push_back(no);
	  }
	}
	lst.sort();
	lst.unique();
	list<int>::iterator it = lst.begin();
	while(it!=lst.end())
	{
	  cout<<*it++<<" ";
	}

    return 0;
}
