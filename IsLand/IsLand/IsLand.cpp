// IsLand.cpp : main project file.

#include "stdafx.h"
#include<iostream>
#include<stdio.h>
#define ROW 6
#define COL 5
using namespace std;

int check(int mat[][COL],int i,int j,int visited[][COL])
{
	if(i>=0 && j>=0 && i<COL && j<COL && mat[i][j] && !visited[i][j])
	{
		visited[i][j] = 1;
		return 1;
	}
	return 0;
}

void dodfs(int mat[][COL],int i,int j,int visited[][COL])
{
	//8 directions
	if(check(mat,i-1,j,visited)) 
		 dodfs(mat,i-1,j,visited);
	if(check(mat,i,j-1,visited))
		dodfs(mat,i,j-1,visited);
	if(check(mat,i+1,j,visited))
		dodfs(mat,i+1,j,visited);
	if(check(mat,i,j+1,visited))
		dodfs(mat,i,j+1,visited);
	if(check(mat,i-1,j-1,visited))
		dodfs(mat,i-1,j-1,visited);
	if(check(mat,i-1,j+1,visited))
		dodfs(mat,i-1,j+1,visited);
	if(check(mat,i+1,j-1,visited))
		dodfs(mat,i+1,j-1,visited);
	if(check(mat,i-1,j+1,visited))
		dodfs(mat,i-1,j+1,visited);
	return;
}
 
int countIslands(int mat[][COL],int count)
{
	int i,j,m,n;
	int visited[ROW][COL];

	memset(visited,0,sizeof(int)*ROW*COL);

	for(i=0;i<ROW;i++)
	{
		for(j=0;j<COL;j++)
		{
			if(mat[i][j] && !visited[i][j])
			{
				dodfs(mat,i,j,visited);count++;
			} 
		}
	}
	return count;
}


int main()
{
	 int M[][COL]= {  {1, 1, 0, 0, 0},
        {0, 1, 0, 0, 1},
        {1, 0, 0, 1, 1},
        {0, 0, 0, 0, 0},
        {1, 0, 0, 0, 0},
		{0, 0, 0, 1, 0},
    };
	int count = 0;
    printf("Number of islands is: %d\n", countIslands(M,count));
  	
	system("pause");
	return 0;
}
