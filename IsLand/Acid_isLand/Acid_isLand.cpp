// Acid_isLand.cpp : main project file.

#include "stdafx.h"
#include<iostream>
#define ROW 5
#define COL 5
using namespace std;

int matrix[ROW][COL];
int visited[ROW][COL];
int cnt1,cnt2;
/*
cell 2 empty
cell 0 stone
cell 1 metal

5
3 3
3 3
1 1 1
1 2 1
0 1 1

4 5
2 4
1 0 1 0 1
1 1 1 1 1
1 1 2 1 1
1 0 1 1 1
 
*/

struct queue
{
	int x,y;
};
struct queue Q[ROW*COL];	
int check(int i,int j,int m,int n)
{ 
	if(i>=0 && j>=0 && i<m && j<n && !visited[i][j] && matrix[i][j] == 1)
	{
	  return 1;
	}
	//for empty cell
 	else if(matrix[i][j] == 2 && i-1>=0 && j-1>=0 && j+1<n && i+1<m && !visited[i][j] && visited[i-1][j] && visited[i+1][j] && visited[i][j-1] && visited[i][j+1]) //in mid
	{ 
		cnt2 = cnt1;
		//by tripun
		visited[i][j] = 1;
 		return 1;
	}
    return 0;
} 
void dobfs(int i,int j,int m,int n)
{
	//for stone material
		
	
	int f=0,r=0;
	Q[r].x = i;
	Q[r].y = j;
	r++;
	int first = 1;
	while(f != r)
	{
		if(Q[f].x == -1 && Q[f].y == -1)
		{
 		    cnt1++;
			 
			f++;
			//by tripun
			if(f==r || (Q[f].x == -1 && Q[f].y == -1))
				cnt1--;
			else
			{
			Q[r].x = -1;
			Q[r].y = -1;
			r++;
			}
			continue;
		}
		i = Q[f].x;
		j = Q[f].y;

		if(matrix[i][j] == 0 || visited[i][j])
		{
			f++;
			continue;
		}

		visited[i][j] = 1;

		if(check(i-1,j,m,n)) //up
		{
			Q[r].x = i-1;
			Q[r].y = j;
			r++;
		}
		if(check(i+1,j,m,n)) //down
		{
			Q[r].x = i+1;
			Q[r].y = j;
			r++;
		}
		if(check(i,j-1,m,n)) //left
		{
			Q[r].x = i;
			Q[r].y = j-1;
			r++;
		}
		if(check(i,j+1,m,n)) //right
		{
			Q[r].x = i;
			Q[r].y = j+1;
			r++;
		}
		
		f++;
		if(first)
		{
		 Q[r].x = -1;
		 Q[r].y = -1;
		 r++;
		 first = 0;
		 cnt1++;
		 
		}

		
 
	}
	
}
int main()
{
	int t,cases=1;
	cin>>t;
	while(t--)
	{
		int m,n,i,j,s,e;
		cin>>m>>n;
		cin>>s>>e;
		for(i=0;i<m;i++)
		  for(j=0;j<n;j++)
			  cin>>matrix[i][j];
		 
		
		
		memset(visited,0,sizeof(visited));
		cnt1=0,cnt2=0;
		dobfs(s-1,e-1,m,n);
		 
		cout<<endl<<"Case #"<<cases++<<endl;
		cout<<cnt2+1<<" "<<cnt1-1;
	}
	system("pause");
	return 0;
}
