// ServerOperation.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#define SIZE 11
#define TTSIZE 50001

int mystrcmp(char a[], char b[]);

void init();
void logout(char idx[]);
void addaccount(char idx[], char password[], int df);
void connect(char idx[]);
void tick();

int tickcnt=0;
struct account
{
	char id[SIZE];
	char pass[SIZE];
	int defaulttime;
	int remain;
	struct account *next;
};

typedef struct account act;

act *head = NULL;

void connect()
{


}

void addaccount(char idx[], char password[], int df)
{
	act *node = new act;

	node->defaulttime = df;
	node->remain = df;
	mystrcpy(node->id, idx);
	mystrcpy(node->pass, password);
	node->next = NULL;

	if (head)
	{
		head = node;
		return;
	}
	else
	{
		//make the tickcnt = 0
		act *prev = NULL,*temp = head;
		bool once = false;
		while (temp)
		{
			temp->remain -= tickcnt;

			//place the node
			if ((false == once) && (temp->remain > node->remain))
			{
				once = true;
				if (prev)
				{
					prev->next = node;
					node->next = temp; 
				}
				else
				{
					node->next = temp;
				}
			}

			temp = temp->next; 
		}

		tickcnt = 0;

	} 
}

void tick()
{
	act *prev = NULL,*temp = head;
	

	if ((temp->remain - tickcnt) > 0)
	{
		tickcnt++;
		return;
	}


	while (temp && ((temp->remain - tickcnt) == 0))
	{
		prev = temp;
		temp = temp->next;
		delete prev; 
	}
	//set head
	head = temp;
	tickcnt = 0;
	 
}

void init()
{
	act *prev = NULL,*temp = head;
	while(temp)
	{
		prev = temp;
		temp = temp->next;
		delete prev; 
	}
	head = NULL; 
	tickcnt = 0;
}

void logout(char idx[])
{
	act *temp = head;
	act *prev = NULL;
	while (temp)
	{
		if (!mystrcmp(temp->id, idx))
		{
			prev->next = temp->next;
			delete temp; 
			return;
		}
		prev = temp;
		temp = temp->next;
	} 
}

void connect()
{

}


int main()
{
    return 0;
}

int mystrcmp(char a[], char b[])
{
	int i = 0;
	while (i< SIZE && a[i] && b[i] && a[i] != b[i])i++;
	return a[i] - b[i];
}
void mystrcpy(char a[], char b[])
{
	int i = 0;
	while (i < SIZE && b[i])
	{
		a[i] = b[i];
		i++;
	}
	a[i] = '\0';
}
