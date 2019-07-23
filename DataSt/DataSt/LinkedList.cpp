// DataSt.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
using namespace std;

struct LinkedList
{
	struct LinkedList *next;
	int data;
};

typedef struct LinkedList list;
list *head = NULL;

list* insert(list *head)
{
	int data; 
	list *temp = NULL;
	cout<<"Enter data (-1 for exit):";
	cin>>data;
	if(-1 == data)return head;
	if(head == NULL)
	{
		head = (list*)malloc(sizeof(list));
		head->next = NULL;
		head->data = data;
	}
	else
	{
		temp = head;
		while(temp->next != NULL)
			temp = temp->next;
		temp->next = (list *)malloc(sizeof(list));
		temp->next->data = data;
		temp->next->next = NULL;
	}
	insert(head);
}
void deletelistnode(list *head)
{


}
void display(list *head)
{
	list *temp = head;
	cout<<endl;
	while(temp)
	{
		cout<<temp->data<<" ";
		temp = temp->next;
	}
	cout<<endl;
	return;
}
 
void Reverse(list **head)
{
	list *first = NULL, *rest = NULL;
	if(*head == NULL || (*head)->next == NULL)
		return; 
	first = *head;
	rest = (*head)->next;
	Reverse(&rest);
	first->next->next = first;
	first->next = NULL;
	*head = rest; 
}
int main()
{
	int choice = 1;
	cout<<"---Linked List---";
	while(choice)
	{
		cout<<"\n1.Insert";
		cout<<"\n2.Delete";
		cout<<"\n3.Display";
		cout<<"\n4.Reverse";
		cout<<"\nEnter your choice :";
		cin>>choice;
		 
		switch(choice)
		{
			case 1:
			head = insert(head);
			break;
			case 2:
			deletelistnode(head);
			break;
			case 3:
			display(head);
			break;
			case 4:
			Reverse(&head);
			break;
		}
	}


	return 0;
}

