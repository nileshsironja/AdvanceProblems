#include<stdio.h>

int main()
{
	int a=5,b=3;
	const int* p = &a;
	*p = 9;
	p = &b;

	printf("%d", *p);

	return 0;
}

