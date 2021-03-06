// Prof_Src.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
using namespace std;
 
struct HashTable
{
	char name[8]; 
	struct HashTable *next; 
}*hashtable[1024];



void search(const char name[])
{
	int ascii = 0;
	//cal ascii value
	for (int i = 0; name[i]; i++)
		ascii = ascii + name[i];

	struct HashTable *root = hashtable[ascii];

	while (root)
	{
		if (!strcmp(root->name, name))
		{
			cout << "found"; break;
		}
		root = root->next;
	}

}


void insert(const char name[])
{  
	int ascii = 0;
	//cal ascii value
	for (int i = 0; name[i]; i++)
		ascii = ascii + name[i];

	if (hashtable[ascii] == NULL)
	{
		hashtable[ascii] = (struct HashTable*) malloc(sizeof(HashTable));
		memcpy(hashtable[ascii]->name, name, sizeof(name));
		hashtable[ascii]->next = NULL;
	}
	else
	{
		bool isInsert = false;
		struct HashTable *hashtableroot = hashtable[ascii];
		while (strcmp(hashtableroot->name,name) && hashtableroot->next != NULL)
		{ 
			hashtableroot = hashtableroot->next;
		}
		if (hashtableroot->next == NULL)
		{
			struct HashTable *newNode = (struct HashTable*) malloc(sizeof(HashTable));
			memcpy(newNode->name, name, sizeof(name));
			newNode->next = NULL;
			hashtableroot->next = newNode;
		}
	} 
}
//
//int main()
//{
//	insert("ABC");
//	insert("BCA");
//	insert("CBA");
//	insert("ABC");
//	search("BCA");
//    return 0;
//}
//
