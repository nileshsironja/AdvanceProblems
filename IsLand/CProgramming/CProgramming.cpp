// CProgramming.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<stdio.h>


int main()
{

	int a[5] = {10,11,12};
	int *p=a;

	--*p++;
	printf("*p = %d",*p);
	
	printf("\n *p = %d",*--p);

	char *str="hello\0";
	while(str)
	{
	  printf("%m",*str++); 
	  getchar();
	}
	printf("%m");
	  getchar();
	return 0;
}

