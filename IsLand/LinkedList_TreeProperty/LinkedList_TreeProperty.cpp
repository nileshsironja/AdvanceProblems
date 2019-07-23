// Linkedlist.c.cpp : main project file.

#include "stdafx.h"
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;

struct list
{
   struct list *next;
   struct list *child;
   int data;
};

list *head,*temp;
 

list * createlist()
{

	list *n1,*n2,*n3,*n4,*n5,*n6,*n7,*n8,*n9,*n10;

	n1 = (struct list*)malloc(sizeof(struct list));
	n1->data = 10;

	head = n1;

	n2 = (struct list*)malloc(sizeof(struct list));
	n2->data = 2;

	n3 = (struct list*)malloc(sizeof(struct list));
	n3->data = 3;

	n4 = (struct list*)malloc(sizeof(struct list));
	n4->data = 4;

	n5 = (struct list*)malloc(sizeof(struct list));
	n5->data = 11;

	n6 = (struct list*)malloc(sizeof(struct list));
	n6->data = 9;

	n7 = (struct list*)malloc(sizeof(struct list));
	n7->data = 5;

	n8 = (struct list*)malloc(sizeof(struct list));
	n8->data = 13;

	n9 = (struct list*)malloc(sizeof(struct list));
	n9->data = 7;

	n10 = (struct list*)malloc(sizeof(struct list));
	n10->data = 6;


	n1->next = n7;
	n1->child = n2;

	n2->next = NULL;
	n2->child = n3;

	n3->next = n5;
	n3->child = n4;

	n4->next = NULL;
	n4->child = NULL;

	n5->next = NULL;
	n5->child = n6;

	n6->next = NULL;
	n6->child = NULL;

	n7->next = n9;
	n7->child = n8;

	n8->next = NULL;
	n8->child = NULL;

	n9->next = n10;
	n9->child = NULL;

	n10->next = NULL;
	n10->child = NULL;


	return head;
 }

list *res_list=NULL;

void singlylist(list *head)
{
  if (!head)
	  return;
   
     list *temp = (struct list*)malloc(sizeof(struct list));
	 temp->data = head->data;
	 temp->next = NULL;
	 temp->child = NULL;
	 if(!res_list)
		 res_list = temp;
	 else
	 {
		 list *temp2 = res_list;
		 while(temp2->next !=NULL)
			 temp2 = temp2->next;
		 temp2->next = temp;
	 } 
   singlylist(head->child);
   singlylist(head->next);


}
 
list *singly_lst(list *head)
{
	if(!head)return NULL;

	list *temp = head;
	list *ptr1 = singly_lst(head->child);
	list *ptr2 = singly_lst(head->next);
	//temp->child = NULL;
	if(ptr1)
	{temp->next = ptr1;
	if(ptr2)
	{
	  while(ptr1->next)ptr1=ptr1->next;
	  ptr1->next = ptr2;
	}
	temp->child= NULL;}
	return temp;
}
/*	list *lst = head;
	list *add = singly_lst(head->child);
	lst->child = NULL;
	//if(lst->next)
	if(head->next && add)
	add->next = head->next;
	lst->next = add;

	//if(head->next)
	//	add->next = head->next;
	if(add && add->next)
	{
		singly_lst(add->next);   
	}
	cout<<"\n lst :"<<lst->data;
	return lst;*/

void displaylist(list *head)
{
	while(head)
	  printf("\n %d",head->data),head=head->next;	
}
 
int main()
{
	list *l1;
	 
	l1 = createlist();
	
    //singlylist(l1);

	list *l2  = singly_lst(l1);
	displaylist(l2);
	system("pause");
}


