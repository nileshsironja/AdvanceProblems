// StackRev_ProfP.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
using namespace std;
#define SIZE 10
int stack[SIZE] = { 10,5,6,7,-9,41,25,63,74,7};
int top = SIZE;

void sort(int top,int num)
{
	if (top < 0)
	{ 
		stack[top + 1] = num;
		return;
	}

	if (num < stack[top])
	{
		int temp = stack[top];
		sort(top - 1, num);
		stack[top+1] = temp;
	}
	else
	stack[top+1] = num;

}

void stackRev(int top)
{
	if (top < 0)return;

	int temp = stack[top];

	stackRev(top - 1);

	sort(top-1, temp); 

}

int main()
{
	cout << "Sorted elements :";
	stackRev(SIZE-1);
	for (int i = 0; i < SIZE; i++)
		cout << stack[i] << " " << endl;
    return 0;
}

