// DirectoryStruct26May.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<malloc.h>
#define LEN 11
using namespace std;

struct Tree
{
	char str[LEN];
	struct Tree *child;
	struct Tree *sibling;
	struct Tree *parent;
};
typedef struct Tree tree;
tree *curdir = NULL, *root = NULL;

void init();
void searchdir();
void deletedir(char key[]);
void movedir();
void mkdir(char key[]);



void deleteall(tree *root)
{
	if (!root)return;
	
	tree *chd = root->child;
	while (chd)
	{
		tree *sib = root->sibling;
		deleteall(sib);
		chd = sib;
	}
	delete root;
}

// if it is /t find in the child, if any node matches
// if string+'*' then delete the dir which is having key prefix of string
// if '*' delete all the dir and sub-dir under the current dir

void deletedir(char key[])
{
	if (key[0] == '//')
	{
		//check current dir child which is 

	}
	else if (key[0] == '*')
	{


	}
	else
	{


	}

}
void mystrcpy(char a[],const char b[])
{
	int i = 0;
	while (b[i] && i < LEN)
	{
		a[i] = b[i]; i++;
	}
	a[i] = '\0';
}

tree* getnode(const char key[])
{
	tree *node = new tree;
	node->child = NULL;
	node->parent = curdir;
	node->sibling = NULL;
	mystrcpy(node->str, key);

}

void mkdir(char key[])
{
	tree *node = getnode(key);


}

void init()
{

	deleteall(root);

	root = getnode("//");
	curdir = root;
}


int main()
{
    return 0;
}

