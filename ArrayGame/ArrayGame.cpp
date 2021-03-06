// ArrayGame.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
using namespace std;
long int N = 0;

struct dlist
{
	long int num;
	struct dlist *prev, *next;
};

typedef struct dlist list;

list *head = NULL;

struct Player
{
	long int alice;
	long int bob;
};

struct Player calculate()
{
	struct Player Play;
	list *mid = head, *temp = NULL;
	long int i = 0,Alice = 0, Bob = 0;
	while (i++ < N / 2)
	{
		mid = mid->next; //get mid node
	}
 	
	bool flag = true;
	if (N % 2 == 0)
		mid = mid->prev;
	//core logic
	while (mid && N)
	{
		if (N == 2)
		{
			if (mid->prev)
			{
				mid = mid->prev;
			}
		}

		if (N % 2 == 0)
		{
			if (mid && (mid->num <= mid->next->num))
			{
				if(flag)
					Alice += mid->next->num;
				else
					Bob += mid->next->num;

				temp = mid->next;
				mid->next = temp->next;
				if (temp->next)
					temp->next->prev = mid;
				delete temp;
			}
			else if(mid && (mid->num > mid->next->num))
			{
				//mid pos
				if (flag)
					Alice += mid->num;
				else
					Bob += mid->num;

				temp = mid;
				mid = mid->next;
				if(mid)
				mid->prev = temp->prev;
				if (temp->prev)
					temp->prev->next = mid;
				delete temp;
			}
			
			 
		}
		else
		{
			if(flag)
				Alice += mid->num;
			else
				Bob += mid->num;

			temp = mid;
			mid = mid->prev;
			if (mid)
				mid->next = temp->next;
			if (temp->next)
				temp->next->prev = mid;
			delete temp;
		}
		if (flag == true) flag = false;
		else flag = true;
		N = N - 1;
	} 

	Play.alice = Alice;
	Play.bob = Bob;
	return Play;
}
 
//int main()
//{
//	cin >> N;
//
//	long int i = 0,number = 0;
//	list *temp = NULL;
//	while (i++ < N)
//	{
//		cin >> number;
//		list *node = new list;
//		node->num = number;
//		node->prev = node->next = NULL;
//
//		if (!head)
//		{
//			head = node; 
//			temp = head;
//		}
//		else
//		{
//			temp->next = node;
//			node->prev = temp;
//			temp = node;
//		} 
//	}
//
//	struct Player Play = calculate();
//
//	if (Play.alice >= Play.bob)
//	{
//		cout << "Alex " << Play.alice - Play.bob;
//	}
//	else
//	{
//		cout << "Bob " << Play.bob - Play.alice;
//	}
//
//    return 0;
//}

long long int T;
int  x1, y1, x2, y2, x3, y3, x4, y4;
long long m1, m2, m3, m4;
int main()
{
	cin >> T;

	while (T--)
	{
		cin >> x1 >> y1 >> x2 >> y2;
		cin >> x3 >> y3 >> x4 >> y4;

	/*	m1 = (y2 - y1);
		m2 = (x2 - x1);

		m3 = (y4 - y3);
		m4 = (x4 - x3);*/


		if (((x1 == x2) && (y1 == y2)) || ((x3 == x4) && (y3 == y4)))
			cout << "INVALID" << endl;

		else if ((x2 - x1) == 0 || (x4 - x3) == 0)
		{
			cout << "INVALID" << endl;
		}

		else if ((((y2 - y1) / (x2 - x1)) * ((y4 - y3) / (x4 - x3))) == -1)
		{
			cout << "YES" << endl;
		}
		else
		{
			cout << "NO" << endl;
		}

	}
	return 0;
}

