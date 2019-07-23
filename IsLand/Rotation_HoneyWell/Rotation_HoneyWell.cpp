// Rotation_HoneyWell.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
using namespace std;
#define row 4
#define col 5
int rot=1;
int arr[row][col] = { {1,2,3,4,5},{6,7,8,9,10},{11,12,13,14,15},{16,17,18,19,20}};


void CalRotation(int p,int q)
{
	int storeno = arr[p][q];
	for(int i=p+1;i<row-p;i++)  //first col
	{
		int temp = arr[i][q];
		arr[i][q] = storeno;
		storeno = temp;
	}
	for(int i=q+1;i<col-q;i++)  //last row
	{
		int temp = arr[row-p-1][i];
		arr[row-p-1][i] = storeno;
		storeno = temp;
	}
	for(int i=row-p-2;i>=p;i--)  //last col
	{
		int temp = arr[i][col-q-1];
		arr[i][col-q-1] = storeno;
		storeno = temp;
	}
	for(int i=col-q-2;i>=q;i--)  //first row
	{
		int temp = arr[p][i];
		arr[p][i] = storeno;
		storeno = temp;
	}

}

void display()
{
	for(int i=0;i<row;i++)
	{
		for(int j=0;j<col;j++)
		{
			cout<<arr[i][j]<<" ";
		}
		cout<<endl;
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	display();
	cout<<endl<<endl;
	int k = 0;
	while(k++<14)
	for(int i=0;i<row/2;i++)
	{  
		CalRotation(i,i);
	}

	display();

	system("pause");
	return 0;
}

