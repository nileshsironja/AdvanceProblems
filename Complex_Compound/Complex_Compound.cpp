// Complex_Compound.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<malloc.h>
using namespace std;
#define SIZE 5001
#define STRLEN 12
#define PRIME 5381

char db[SIZE][5][STRLEN];

struct Hash
{
	char comp[5][STRLEN];
	struct Hash *next;
}*hashs[SIZE];

int idx = 0;
void init()
{
	for (int i = 0; i < SIZE; i++)
	{
		struct Hash *nextnode = hashs[i];

		while (nextnode)
		{
			struct Hash *temp = nextnode;
			nextnode = nextnode->next;
			delete nextnode;
		}
		hashs[i] = NULL;
	} 

	idx = 0;

}

int gethash(char str[])
{
	int sum = 0,i=0;
	while (str[i])
	{
		sum = PRIME * str[i] + str[i];
	}
	return sum;
}

void mystrcpy(char dest[], char src[])
{
	while (*src)
	{
		*dest = *src;
		dest++, src++;
	} 
	*dest = 0; 
}
void insertHash(char str[5][STRLEN])
{
	for (int i = 0; i < 5; i++)
	{
		int hashval = gethash(str[i]);
		

		struct Hash *node = new Hash;
		node->next = NULL;
		for(int j =0;j<5;j++)
		mystrcpy(node->comp[j], str[j]);


		if (hashs[hashval] == NULL)
		{
			hashs[hashval] = node; 
		}
		else
		{
			node->next = hashs[hashval];
			hashs[hashval] = node;
		} 
	} 
}

void storeDB()
{
	for (int i = 0; i < 5; i++)
	{
		//store the strings
		//db[idx][i]

	}

	//insert into map
	insertHash(db[idx]);
}

void searchCompund(char search[5][STRLEN])
{



}

int main()
{


    return 0;
}

