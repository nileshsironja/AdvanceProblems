// ListMergeSort.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<malloc.h>
using namespace std;

struct List
{
	int val;
	struct List *next; 
};

struct List *a = NULL;
typedef struct List lst;

lst* formlist(int i,lst *head)
{
	lst *node = new lst;
	node->val = i;
	node->next = NULL;

	if (!head)head = node;
	else
	{
		node->next = head;
		head = node;
	}
	return head;
}

lst *split(lst *head)
{
	if (!head || !head->next)return head;
	
	lst *slow = head, *fast = head->next->next;

	while (fast && fast->next)
	{
		slow = slow->next;
		fast = fast->next->next; 
	}

	lst *res = slow->next;
	slow->next = NULL;
	return res; 
}
lst * merge(lst *a, lst *b)
{
	if (!a)return b;
	if (!b)return a;

	lst *result = NULL;

	if (a->val < b->val)
	{
		result = a;
		result->next = merge(a->next, b);
	}
	else
	{
		result = b;
		result->next = merge(a, b->next);
	}
	return result;
}
void sort(lst **a)
{
	if (!*a|| !(*a)->next)return;

	lst *b = split(*a);
	sort(a);
	sort(&b);
	*a = merge(*a,b); 
}


int main()
{ 
	for (int i = 0; i < 10; i++)
	{
		a = formlist(i*rand() % 50, a);
	}
	lst *aa = a;
	while (aa)
	{
		cout << aa->val << " ";
		aa = aa->next;
	}
	
	sort(&a);
	cout << endl << endl;
	while (a)
	{
		cout << a->val << " ";
		a = a->next;
	}
	return 0;
}

