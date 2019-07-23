// ChessGame.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#define SIZE 15
using namespace std;
int first,second;
int DP[SIZE][SIZE];
int recur(int x,int y)
{

	if(DP[x][y] != -1) return  DP[x][y];

	int result = 0;

	
	if(x-2 >=0 && y+1 < SIZE)
		result = result | !recur(x-2,y+1);
	if(x-2 >=0 && y-1 >= 0)
		result = result | !recur(x-2,y-1);
	if(x+1< SIZE && y-2 >=0) 
		result = result | !recur(x+1,y-2);
	if(x-1 >=0 && y-2 >=0)
		result = result | !recur(x-1,y-2);

	DP[x][y] = result;

	return result;

}

int main()
{
	int T;

	cin>>T;
	for(int i=0;i<SIZE;i++)
		{
			for(int j=0;j<SIZE;j++)
			{
				DP[i][j] = -1;
			}
		}

		DP[0][0] = DP[0][1] = DP[1][0] = DP[1][1] = 0;

	while(T--)
	{
		//first = 0 , second = 0;
		int x,y;
		cin>>x>>y;
		
		recur(x-1,y-1);
		if(DP[x-1][y-1])
		cout<<"First"<<endl;
		else
		cout<<"Second"<<endl;
	}

	return 0;
}

