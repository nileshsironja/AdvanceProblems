// LongestPrefix.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
using namespace std;
#define SIZE 100
#define NUM 3

char str[][SIZE] = { "apple", "ape", "april" };

int checkifmatches(char str[], char  input[], int low, int limit)
{
	int i = low;
	while (i < limit)
	{
		if (str[i] != input[i])
			return 0;
		i++;
	}
	return 1;
}

char input[SIZE + 1];

int findprefix(/*char str[][SIZE]*/)
{
	int minlen = SIZE+5, index = 0;
	for (int i = 0; i < NUM; i++)
	{
		int j = 0,len=0;
		while (str[i][j])
		{
			len++;  j++;
		}
		if (len < minlen) {
			index = i; minlen = len;
		}

	}

	int j = 0;
	while (str[index][j]) input[j] = str[index][j++];

	//binary search
	int L = 0, H = minlen,mid = 0;
	for (int i = 0; i < NUM; i++)
	{
		L = 0, H = minlen, mid = 0;
		while (L < H)
		{
			mid = L + ((H - L) / 2);

			if (checkifmatches(str[i], input, L,mid) == false)
			{
				int k = 0;
				while (L < mid)
				{
					if (input[L] == str[i][L])L++;
				}
				break;
			}
			else
			{
				L = mid + 1;
			}
		}
		if ((L == H) && (input[L] != str[i][H]))L--;

		minlen = L;
	} 
	return minlen;

}

class IndiaBix
{
	int x, y;
public:
	IndiaBix(int xx = 0, int yy = 0)
	{
		x = xx;
		y = yy;
	}
	void Display()
	{
		cout << x << " " << y;
	}
	IndiaBix operator +(IndiaBix z)
	{
		IndiaBix objTemp;
		objTemp.x = x + z.x;
		objTemp.y = y + z.y;
		return objTemp;
	}
};
  int x;
  int CPCTest(int x, int y)
  {
	  return x * y;
  }
  int CPCTest(int x, int y, int z = 5)
  {
	  return x * y * z;
  }
int main()
{
	int a = 5;
	x = ~a + a & a + a << a;
	//int a = 32;
	//printf("%x", ~a);
	IndiaBix objBix1(90, 80);
	IndiaBix objBix2(10, 20);
	IndiaBix objSum;
	IndiaBix &objRef = objSum;
	objRef = objBix1 + objBix2;
	objRef.Display();
	int x = 0;
	int &y = x; y = 5;
	while (x <= 5)
	{
		cout << y++ << " ";
		x++;
	}
	cout << x;
	int minlen = findprefix();
	for (int i = 0; i <= minlen; i++)
		cout << input[i];
	
	return 0;
}

