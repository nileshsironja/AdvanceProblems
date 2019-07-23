// N_Queens.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#define S 8
using namespace std;

int queens[S][S];
 
int check_place(int row,int col)
{
	int j,k;
	//check in a col;
	for(j=row; j >=0; j--)
		if(queens[j][col])
			return 0;
	//check in a row;
	for(j=col; j >=0; j--)
		if(queens[row][j])
			return 0;
	//check in a left diagonal;
	for(j=row,k=col; j>=0 && k>=0; j--,k--)
		if(queens[j][k])
			return 0;
	//check in a right diagonal;
	for(j=row,k=col; j>=0 && k<S; j--,k++)
		if(queens[j][k])
			return 0; 
	return 1;
}
int counts=0;
int place_queen(int row)
{
	if(row >= S)
		return 1;
	for(int j=0;j<S;j++)
	{
		if(check_place(row,j))
		{
			queens[row][j] = 1;
			//cout<<endl<<"Row :"<<row<<" Col :"<<j;
			if(place_queen(row+1))
			{
				counts++;
				cout<<endl<<counts;
				cout<<endl;
				for(int i=0;i<S;i++)
				{
					for(int k=0;k<S;k++)
						cout<<" "<<queens[i][k];
					cout<<endl;
				}
				//return 1;
			}	
			queens[row][j] = 0;
		}
 	}         	 
	return 0;
}

int main()
{

	if(place_queen(0))
	{
		cout<<endl<<"Placed Queen";
	}
	else
	{
		cout<<endl<<"Queen cannot be placed";
	}

	cout<<endl<<endl;
	for(int i=0;i<S;i++)
	{
		for(int j=0;j<S;j++)
		{
			cout<<queens[i][j]<<" ";
		}
		cout<<endl;
	}

	system("pause");

	return 0;
}

