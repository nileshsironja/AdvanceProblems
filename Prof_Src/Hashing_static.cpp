// Prof_Src.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
using namespace std;

struct HashTable
{
	char name[8]; 
}hashtable[1024][50] = {'\0'};



void search_(const char name[])
{
	int ascii = 0;
	//cal ascii value
	for (int i = 0; name[i]; i++)
		ascii = ascii + name[i];

	int itr = 0;
	while ((itr < 50) && !strcmp(hashtable[ascii][itr].name,name));

	if (itr < 50) cout << "found";
	else cout << "not found";
	 
}


void insert_(const char name[])
{
	int ascii = 0;
	//cal ascii value
	for (int i = 0; name[i]; i++)
		ascii = ascii + name[i];

	int itr = 0;
	 
	while ((itr < 50) && hashtable[ascii][itr].name[0] != '\0' ) itr++;

	strcpy_s(hashtable[ascii][itr].name, name);

}

int main()
{
	for (int i = 0; i < 1024; i++)
		for (int j = 0; j < 50; j++)
			for(int k=0;k<8;k++)
				hashtable[i][j].name[k] = '\0';
	insert_("ABC");
	insert_("BCA");
	insert_("CBA");
	insert_("ABC");
	search_("BCA");
	return 0;
}

