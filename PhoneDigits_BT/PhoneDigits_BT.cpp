// PhoneDigits_BT.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#define SIZE 10
using namespace std;

char phone[SIZE][5] = {
	{""},
	{""},
	{"ABC"},
	{"DEF"},
	{"GHI"},
	{"JKL"},
	{"MNO"},
	{"PQRS"},
	{"TUV"},
	{"WXYZ"},		
};
char output[4];
void PossibleWords(const char num[],int len)
{
	if (len > strlen(num)) return;
	if (len == strlen(num))
	{
		cout << endl << output; 
	} 

	for (int i = 0; i < strlen(phone[num[len] - 48]); i++)
	{
		if (phone[num[len] - 48][i] != '\0')
			output[len] = phone[num[len] - 48][i];
				
		PossibleWords(num, len + 1);
	}

}

int main()
{
	PossibleWords("239",0);

    return 0;
}

