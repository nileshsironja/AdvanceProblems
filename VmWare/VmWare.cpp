// VmWare.cpp : Defines the entry point for the console application.
//

//Read a file and count the number of kind of characters in that


#include "stdafx.h"
#include<iostream>
#include<fstream>
#include<string>
#define RANGE 127
using namespace std;
int charHash[256];
int main()
{
	string inputfile;
	
	cout << "Enter file path:";
	cin >> inputfile;
	
	ifstream infile(inputfile);
	int i = 0;
	while (getline(infile,inputfile))
	{
		i = 0;
		while (inputfile[i])
		{
			if (inputfile[i] < 0)
			{
				charHash[RANGE - inputfile[i]]++;
			}
			else
			{
				charHash[inputfile[i]]++;
			} 
			i++;
		} 
	}
	
	for (int i = 0; i < RANGE * 2 + 1; i++)
	{
		cout << "char :" << (char)i << " count :" << charHash[i]<<endl;
	}

    return 0;
}



