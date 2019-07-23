// Linkedlist.c.cpp : main project file.

#include "stdafx.h"
#include<stdio.h>
#include<stdlib.h>
using namespace System;

struct list
{
   struct list *next;
   int data;
};

list * createlist()
{
	list *head,*tail,*tmp;
	int no,n;
	char ch;
	head=tail=NULL;
	printf("Enter no of nodes :");
	scanf("%d",&n);
	while(n--)
	{
	printf("\nEnter no :");
	scanf("%d",&no);

	if(!head)
	{
		head = (struct list*)malloc(sizeof(struct list));
		head->data = no;
		head->next = NULL;
		tail = head;
	}
	else
	{
	    tmp = (struct list*)malloc(sizeof(struct list));
 		tail->next = tmp;
		tail = tail->next;
		tail->data = no;
		tail->next = NULL;
	} 
	 
	 
	} 
	return head;
}

void displaylist(list *head)
{
	while(head)
	  printf("\n %d",head->data),head=head->next;	
}

void show_mem_rep(char *start, int n) 
{
    int i;
    for (i = 0; i < n; i++)
         printf(" %.2x", start[i]);
    printf("\n");
}

list* reverseList(list *head)
{
	if(!head)return head;
	if(!head->next)return head;
	list *temp = head;
	head = head->next;
	temp->next = NULL;
	list *newhead = reverseList(head);
	head->next = temp;
	return newhead; 
}

list* mergelist(list *l1,list *l2)
{
	list *head,*tail,*ptr = l1,*qtr = l2,*rst ;

	if(l1->data < l2->data)head=l1,tail=l1;else head=l2,tail=l2;

	while(ptr && qtr)
	{
		if(ptr->data < qtr->data)
		{
		  rst = ptr;
		  ptr = ptr->next;
		  tail->next = rst;
		}
		else
		{
		  rst = qtr;
		  qtr = qtr->next;
		  tail->next = rst;
		}
		tail = rst;
	}
	if(qtr)tail->next = qtr;
	else tail->next = ptr;
	return head;
}
 
list* rearrange(list *head)
{
	/*
Examples:
Input:  1 -> 2 -> 3 -> 4
Output: 1 -> 4 -> 2 -> 3

Input:  1 -> 2 -> 3 -> 4 -> 5
Output: 1 -> 5 -> 2 -> 4 -> 3 
*/
	if(!head || !head->next)return head;
	list *slow = head,*fast = head;
	while(1) {slow=slow->next,fast=fast->next;if(fast->next)fast=fast->next;else break;}

	slow->next = reverseList(slow->next);
//	displaylist(head);

	fast = slow->next;
	slow->next = NULL;
	slow = head;
	
	while(fast)
	{
		list *ptr = slow->next;
		slow->next = fast;
		fast = fast->next;
		slow->next->next = ptr; 
		slow = ptr;
	}
	return head;
}

list* set_link(list *head,int k1,int k2)
{
/*	Input:  10->15->12->13->20->14,  x = 12, y = 20
	Output: 10->15->20->13->12->14

	Input:  10->15->12->13->20->14,  x = 10, y = 20
	Output: 20->15->12->13->10->14

	Input:  10->15->12->13->20->14,  x = 12, y = 13
	Output: 10->15->13->12->20->14*/
	if(!head && !head->next)return NULL;

	list *f1,*f2,*s1,*s2,*ptr=head,*str;
	//if nodes are in between the list and not consecutive
	while(ptr)
	{
		if(ptr->next->data == k1)
		{
		  f1 = ptr,f2 = ptr->next; 
		}
		if(ptr->next->data == k2)
		{
		  s1 = ptr,s2 = ptr->next; 
		  break;
		} 
		ptr = ptr->next;
	}

	
	//if k1,k2 are adjecent

	if(f2 == s1)
	{
		//str = s1;
		f1->next = s2;
		s1->next = s2->next;
		s2->next = s1;
	} 
	else
	{
		f1->next = s2;
		str = s2->next;
		s2->next = f2->next;
		s1->next = f2;
		f2->next = str;
	}
	displaylist(head);
}

int main()
{
	list *l1,*l2,*l3;

	/* merge two list into a final one
	l1 = createlist();
	l2 = createlist();
	l3 = mergelist(l1,l2);
	displaylist(l3);*/

	/* reverse a given list
	l1 = createlist();
	l1 = reverseList(l1);
	displaylist(l1);*/

	/* rearrange a given list
	l1 = createlist();
 	l1 = rearrange(l1);
	displaylist(l1);*/

	l1 = createlist();
	set_link(l1,12,13);

	system("pause");
}


