// Permutation.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
using namespace std;

char str[] = "abcd";

void sortdstringati(int ii)
{
	for(int i=ii; str[i]; i++)
	{
		for(int j=i+1; str[j]; j++)
		{
			if(str[i] > str[j])
			{
				char ch = str[i];
				str[i] = str[j];
				str[j] = ch;
			}
		}
	}
}

int strlength = strlen(str);

int findceil(int ii)
{
	int ceilindex = 0;
	for(int i=ii+1;i<strlength;i++)
	{
		if(str[ii] < str[i])
		{
			if(ceilindex == 0)
				ceilindex = i;
			else
			{
				if(str[ceilindex] > str[i])
					ceilindex = i;
			}

			//ceilindex = i;
		}
	}
	return ceilindex;
}
void swap(int i,int j)
{
	char ch = str[i];
	str[i] = str[j];
	str[j] = ch;
}
void permute()
{
	if(str == '\0')return;

	bool done = false;

	sortdstringati(0);
	
	while(true != done)
	{
		cout<<str<<endl;
		int i;
		//find the first character
		for(i = strlength - 2; i >=0; i--)
			if(str[i] < str[i+1])
				break;

		//base condition
		if(i == -1)break;

		int index = findceil(i);
		
		swap(i,index);

		sortdstringati(i+1);
	
	}

}

int main()
{
	permute(); 
	system("pause");
	return 0;
}

