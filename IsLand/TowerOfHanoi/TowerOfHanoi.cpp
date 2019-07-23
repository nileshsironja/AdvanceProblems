// TowerOfHanoi.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <stdio.h>
#include <iostream>
using namespace std;
void towers(int, char, char, char);
 
int main()
{
    int num;
 
    //printf("Enter the number of disks : ");
    //scanf("%d", &num);
	cout<<"Disk :";
	cin>>num;
    printf("The sequence of moves involved in the Tower of Hanoi are :\n");
    towers(num, 'A', 'C', 'B');
	system("pause");
    return 0;
}
void towers(int num, char frompeg, char topeg, char auxpeg)
{
    if (num == 1)
    {
        cout<<"\n Move disk 1 from peg "<<frompeg<<" to "<<topeg;
        return;
    }
    towers(num - 1, frompeg, auxpeg, topeg);
    cout<<"\n Move disk "<<num <<" from peg "<<frompeg<<" to peg "<<topeg;
    towers(num - 1, auxpeg, topeg, frompeg);
}

