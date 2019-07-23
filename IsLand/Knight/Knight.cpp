// Knight.cpp : main project file.

#include "stdafx.h"
#include <iostream>
#define ROW 5
#define COL 5
using namespace std;

struct queue
{
	int x,y;
};

void dobsf(int matrix[][COL],int visited[][COL],int *cnt,int i,int j)
{ 
	struct queue Q[100];
	int front=0,rear=0;
	Q[rear].x = i;
	Q[rear].y = j;
	rear++;
	int first = 1;
	while(front!=rear)
	{
		i = Q[front].x;
		j = Q[front].y; 

		//8 directions.
		if(matrix[i][j] == 2)
		{*cnt = *cnt + 1;break;}
 		
		if(visited[i][j] == 1)
		{
		  front++;
		  continue;
		}

		if(Q[front].x == -1 && Q[front].y == -1)
		{
			*cnt = *cnt + 1;
			front++;
			Q[rear].x = -1;
			Q[rear].y = -1;
			rear++;
			continue;
		}



		//case 1
		if((i-1)>=0 && (j-2)>=0 && !visited[i-1][j-2])
		{
			Q[rear].x = i-1;
			Q[rear].y = j-2;
			rear++;
		}
		
		//case 2
		if((i-2)>=0 && (j-1)>=0 && !visited[i-2][j-1])
		{
			Q[rear].x = i-2;
			Q[rear].y = j-1;
			rear++;
		}
		
		//case 3
		if((i-1)>=0 && (j+2) < ROW && !visited[i-1][j+2])
		{
			Q[rear].x = i-1;
			Q[rear].y = j+2;
			rear++;
		}
		
		//case 4
		if((i-2)>=0 && (j+1) < ROW && !visited[i-2][j+1])
		{
			Q[rear].x = i-2;
			Q[rear].y = j+1;
			rear++;
		}
		

		//case 5
		if((i+1)<ROW && (j-2)>=0 && !visited[i+1][j-2])
		{
			Q[rear].x = i+1;
			Q[rear].y = j-2;
			rear++;
		}
		
		//case 6
		if((i+2)<ROW && (j-1)>=0 && !visited[i+2][j-1])
		{
			Q[rear].x = i+2;
			Q[rear].y = j-1;
			rear++;
		}
		
		//case 7
		if((i+2)<ROW && (j+1) < ROW && !visited[i+2][j+1])
		{
			Q[rear].x = i+2;
			Q[rear].y = j+1;
			rear++;
		}
		
		//case 8
		if((i+1)<ROW && (j+2) < ROW && !visited[i+1][j+2])
		{
			Q[rear].x = i+1;
			Q[rear].y = j+2;
			rear++;
		}

		if(first)
		{
			Q[rear].x = -1;
			Q[rear].y = -1;
			rear++;
			first = 0;
		}
		visited[i][j] = 1;			
		front++;
	}
	 
}


int find_minMoves(int matrix[][COL],int i,int j)
{
	
	int visited[ROW][COL];
	memset(visited,0,sizeof(int)*ROW*COL);
	int count=0;
	dobsf(matrix,visited,&count,i,j);
	return count; 
}


//find min moves required by knight to attack the given soldier.
int main()
{
	int matrix[][COL] = {
							{0,0,0,0,0},
							{0,0,0,0,0},
							{0,0,0,0,0},
							{0,0,2,1,0},
							{0,0,0,0,0},
						};
	
	cout<<endl<<"Min no of moves are :"<<find_minMoves(matrix,3,3);
	getchar();
	system("pause");
	return 0;
}