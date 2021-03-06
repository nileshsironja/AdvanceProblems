// DBMS.cpp : Defines the entry point for the console application.
//

#include "stdafx.h" 
#define SIZE 5
#define TRECORD 5001
#define STRSIZE 19
#define PRIME 5381
enum field
{
	NAME = 0,
	NUMBER = 1,
	BDAY = 2,
	EMAIL = 3,
	MEMO = 4
};
  
char db[TRECORD][SIZE][STRSIZE];
struct hashing
{
	int id;
	struct hashing *next;
}*hash[5][SIZE];

typedef struct hashing chain;
int id = 0;

void init()
{
	for (int i = 0; i < 5; i++)
	{
		chain *prev, *temp;
		for (int j = 0; j < SIZE; j++)
		{
			temp = hash[i][j];
			while (temp)
			{
				prev = temp;
				temp = temp->next;
				delete prev; 
			}
			hash[i][j] = NULL;
		} 
	}

	id = 0;
}

void storehash(char record[][STRSIZE])
{
	for (int i = 0; i < SIZE; i++)
	{
		int hashval = gethash(record[i]);

		chain *node = new chain;

		node->id = id;
		node->next = NULL;
		if (hash[i][hashval] == NULL)
			hash[i][hashval] = node;
		else
		{
			node->next = hash[i][hashval];
			hash[i][hashval] = node;
		} 
	} 
}
void store(char record[][STRSIZE])
{
	for (int i = 0; i < SIZE; i++)
	{
		mystrcpy(db[id][i], record[i]);
	}
	storehash(record);
	id++;
}

void mystrcpy(char dest[], char src[])
{
	int i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}

int mystrcmp(char str[], char strex[])
{
	int i = 0;
	while (i < STRSIZE && str[i] && strex[i] && str[i] == strex[i])i++;

	return str[i] - strex[i];
}

int gethash(char str[])
{
	int sum = 0;
	for (int i = 0; i < STRSIZE && str[i]; i++)
	{
		int sum = (sum * PRIME + str[i]) % SIZE;
		 
	}
	return sum % SIZE;
}
