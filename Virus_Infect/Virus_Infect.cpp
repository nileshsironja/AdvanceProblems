// Virus_Infect.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<stdlib.h>
struct Tree
{
	int id;
	int size;
	int actualsize;
	struct Tree *child;
	struct Tree *parent;
	struct Tree *sibling;
};

typedef struct Tree Tr;
Tr *root = NULL;

Tr* getNode(int pid, int size);
/* INIT ADD MOVE DELETE INFECT RECOVER */

/*************************     INIT API      *******************************/
void init()
{
	root = NULL;
	root = getNode(10000, 0);
}

/*************************     INIT API      *******************************/

/*************************     ADD API      *******************************/

 
Tr *getNode(int id,int size)
{
	Tr *node = (Tr*)malloc(sizeof(Tr));
	node->actualsize = size;
	node->size = size;
	node->id = id;
	node->child = NULL;
	node->sibling = NULL; 
	return node;
}

void add(int pid,int id,int size)
{
	Tr *node = search_id(root,pid);
	if (node->child == NULL)
	{
		node->child = getNode(id, size);
		node->child->parent = node;
	}
	else
	{ 
		node = getNode(id, size); 
		node->sibling = root->child;
		root->child = node;
		node->parent = root; 
	}
}

/*************************     ADD API      *******************************/

/*************************     INFECT API    *******************************/
//total size of file in the system/ number of files

void gettotalsize(Tr *root,int *sum,int *numF)
{ 
	while (root != NULL)
	{
		if(root->child->size == 0)
		gettotalsize(root->child,&(*sum = *sum+root->size),numF);
		else
		gettotalsize(root->child, &(*sum = *sum + root->size), numF + 1);
		root = root->sibling; 
	}

}
Tr* search_id(Tr *root, int id) //search id
{
	if (!root) return NULL;
	if (root->id == id)return root;

	Tr *temp = root->child;
	while (temp)
	{
		Tr *nodeWthID = search_id(root->child, id);
		if(nodeWthID)
		{
			return nodeWthID;
		}
		root = root->sibling;
	}
	return NULL;
}
void increasefilesize(Tr *root, int size)
{ 
	while (root != NULL)
	{ 
		if (root->child->size != NULL)
			root->child->size += size;
		increasefilesize(root->child, size);
		 
		root = root->sibling;
	} 
}
void getInfect(Tr *root, int id)
{
	int totsize = 0;
	int numF = 0;
	gettotalsize(root,&totsize,&numF);
	Tr *nodeWthID = NULL;
	nodeWthID = search_id(root, id);
	increasefilesize(nodeWthID,totsize / numF);
}


/*************************     INFECT API    *******************************/


/*************************     RECOVER API    *******************************/
Tr* search_rec(Tr *root, int id) //search parent
{
	if (!root) return NULL;
	if (root->id == id)return root;

	while (root != NULL)
	{
		Tr *node = NULL;
		if (node = search_rec(root->child, id))
		{
			return node;
		}
		root = root->sibling;
	}
}
void getrecover(Tr *rootNode)
{
	if (rootNode == NULL) return;
	else
	{
		while (rootNode != NULL)
		{
			rootNode->size = rootNode->actualsize;
			getrecover(rootNode->child);
			rootNode = rootNode->sibling; 
		} 
	}
}

void recover(Tr *root, int id)
{
	Tr *rootNode = search_rec(root, id);
	getrecover(rootNode);
}


/*************************     RECOVER API    *******************************/



/*************************     MOVE API    *******************************/
Tr* search(Tr *root, int id) //search parent
{
	if (!root) return NULL;
	if (root->id == id)return root;
	//if (root->child != NULL && root->child->id == id) return root;
	while (root != NULL)
	{
		Tr *parent = root;
		if ((search(root->child, id)) != NULL)
		{
			return parent;
		}
		root = root->sibling; 
	} 
}

bool addSuccessor(Tr *root, Tr *successor, int id)
{
	if (root->id == id)
	{
		if (root->child == NULL)
		{
			root->child = successor; 
		}
		else
		{
			Tr *traverse = root->child;
			while (traverse->sibling != NULL)
			{
				traverse = traverse->sibling;
			}
			traverse->sibling = successor;
		}
		return true;
	}

	while (root != NULL)
	{
		if (addSuccessor(root->child, successor, id))
		{
			return true;
		} 
		root = root->sibling; 
	} 
	return false;
}

void move(Tr *root, int id, int pid)
{
	//find the parent node and get it's successor of given id;
	Tr *successor = NULL;
	Tr *parent = search(root, id);
	if (parent->child->id == id)
	{
		successor = parent->child;
		parent->child = parent->child->sibling;
	}
	else
	{
		Tr *traverse = parent->child;
		while (traverse->sibling->id != id)
		{
			traverse = traverse->sibling;
		}
		successor = traverse->sibling;
		traverse->sibling = traverse->sibling->sibling;
	}

	//now add the successor which is found in step 1;
	addSuccessor(root,successor,id);

}
/*************************     MOVE API    *******************************/




int main()
{
	init();
	add(10000, 10003, 0);
	add(10000, 10005, 150);
	add(10003, 10004, 0);
	add(10003, 10007, 350);
	add(10004, 30008, 50);
	move(root, 30008, 10003);
    return 0;
}

