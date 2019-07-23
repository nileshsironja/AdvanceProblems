// connected_areas.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#define SIZE 5
#include<iostream>
using namespace std;
/*
1 0 1 0 1
1 1 0 0 0
0 0 0 0 1
0 1 0 0 0
1 1 1 1 1

5 connected areas

*/
int maxpoint = 0;
int check(int matrix[][SIZE],int i,int j,int count)
{
	if(i>=0 && i<SIZE  && j>=0 && j<SIZE && matrix[i][j] == -1)
	{
		matrix[i][j] = count;
		maxpoint++;
		return 1;
	}
	return 0; 
}


void dodfs(int matrix[][SIZE],int i,int j,int count)
{
	//check up
	if(check(matrix,i-1,j,count))
		dodfs(matrix,i-1,j,count);
	//check down
	if(check(matrix,i+1,j,count)) 
		dodfs(matrix,i+1,j,count); 
	//check right
	if(check(matrix,i,j+1,count))  
		dodfs(matrix,i,j+1,count); 
	//check left
	if(check(matrix,i,j-1,count))  
		dodfs(matrix,i,j-1,count); 
}
 
int main()
{
	int matrix[SIZE][SIZE] = {
						{-1, 0, -1, 0, -1},
						{-1, -1, 0, 0, 0},
						{0, 0, 0, 0, -1},
						{0, -1, 0, 0, 0},
						{-1, 0, -1, -1, -1},
 				};

	int i,j,count=0,mpoint=0;
	maxpoint = 0;
	for(i=0;i<SIZE;i++)
	{
		for(j=0;j<SIZE;j++)
		{
			if(matrix[i][j] == -1)
			{
				matrix[i][j] = count;
				maxpoint=1;
				dodfs(matrix,i,j,count);
				count++;
				mpoint = mpoint > maxpoint ? mpoint : maxpoint;
			}
		}
	}
	
	cout<<endl<<"Count is :"<<count;
	cout<<endl<<"Max point is :"<<mpoint;
	system("pause");
	return 0;
}

