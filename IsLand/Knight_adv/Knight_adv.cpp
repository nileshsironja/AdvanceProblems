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
struct queue Q[ROW*COL];
int visited[ROW][COL];
int matrix[][COL] = {
							{9,1,9,9,9},
							{9,9,9,3,9},
							{9,5,9,9,9},
							{9,9,9,1,9},
							{9,9,9,9,9}, 
						};
	


struct queue chkmin(int front,int rear)
{
    struct queue minver;
	minver.x = -1;
	minver.y = -1;
	int sum = INT_MAX;
	while(Q[front].x != -1 && Q[front].y != -1)
	{
	    if(sum > matrix[Q[front].x][Q[front].y])
		{
			sum = matrix[Q[front].x][Q[front].y];
			minver = Q[front];
				  

		}

		front++;

	}
	return minver;

}

int dobsf(int i,int j,int k)
{
	int sum = 0;
 
	int front=0,rear=0;
	Q[rear].x = i;
	Q[rear].y = j;
	rear++;
	int first = 0;
	while(front!=rear)
	{
		
		//8 directions. 		
		if(first)
		{
			struct queue min_item = chkmin(front,rear);
			while(Q[front].x != -1 && Q[front].y != -1)
			front++;
			 
		    i = min_item.x;
			j = min_item.y;
	     	//first=0;
		}
		 
		if(i==0)
		{sum+=matrix[i][j];break;}

        if(visited[i][j] == k)
		continue;

		visited[i][j] = k;
 		//case 1
		if((i-1)>=0 && (j-2)>=0 && visited[i-1][j-2] != k)
		{
			Q[rear].x = i-1;
			Q[rear].y = j-2;
			rear++;
		}
		
		//case 2
		if((i-2)>=0 && (j-1)>=0 && visited[i-2][j-1] != k)
		{
			Q[rear].x = i-2;
			Q[rear].y = j-1;
			rear++;
		}
		
		//case 3
		if((i-1)>=0 && (j+2) < COL && visited[i-1][j+2] != k )
		{
			Q[rear].x = i-1;
			Q[rear].y = j+2;
			rear++;
		}
		
		//case 4
		if((i-2)>=0 && (j+1) < COL && visited[i-2][j+1] != k)
		{
			Q[rear].x = i-2;
			Q[rear].y = j+1;
			rear++;
		}
		

		//case 5
		if((i-2)>=0 && (j-2)>=0 && visited[i-2][j-2] != k)
		{
			Q[rear].x = i-2;
			Q[rear].y = j-2;
			rear++;
		}
		
		//case 6
		if((i-2)>=0 && (j+2)>=0 && visited[i-2][j+2] != k)
		{
			Q[rear].x = i-2;
			Q[rear].y = j+2;
			rear++;
		}
		//visited[i][j] = 1;			
		Q[rear].x = -1;
		Q[rear].y = -1;
		rear++;
		sum+=matrix[i][j]; 
		front++;
		first = 1;
	}
	 
	return sum;

}

int find_minMoves()
{
	
	
	//memset(visited,0,sizeof(int)*ROW*COL);
	int sum=INT_MAX;
	int i = 0;
	for(i=0;i<COL;i++)
	{ 
      int min_sm =	dobsf(ROW-1,i,i+1); 
	  if(min_sm < sum)
		  sum = min_sm;
	}
	return sum; 
}


//find min moves required by knight to attack the given soldier.
int main()
{
	cout<<endl<<"Min Sum is :"<<find_minMoves();
//	getchar();
	system("pause");
	return 0;
}