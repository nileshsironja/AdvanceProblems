// 30SepAdvTest.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#define SIZE 20
using namespace std;

int shapes[SIZE][SIZE];
int strn[SIZE][SIZE];
int cpstrn[SIZE][SIZE];
int visited[SIZE][SIZE];
int exits[SIZE+SIZE];

int T,N;

//struct Q
//{
//	int i,j;
//};

//struct Q queue[SIZE*SIZE*50];
int cnt = 0;
void dobfs(int ii,int jj,int dir)
{
	int f=-1,r=-1;
	int p,q;
	//queue[++r].i = ii;
	//queue[r].j = jj;
	p = ii;
	q = jj;
	
	while(1)
	{
		//p = queue[++f].i;
		//q = queue[f].j;

		if(!visited[p][q] && shapes[p][q])
		{
			cnt++;
			visited[p][q] = 1;
		}

		if(shapes[p][q] == 1 && strn[p][q])   //shape 1
		{
			strn[p][q]--;
			if(!strn[p][q])
			{
				exits[p]++;
				exits[N+q]++;
			}
			if(dir == 1)//right
			{ 
				//++r;
				if(p == 0)
					p = N-1; 
				else
					p = p-1;
				//queue[r].j = q;   
				dir = 3;
			}

			else if(dir == 2)//left
			{
				
				//++r;
				if(q == N-1)
					q = 0;
				else
					q = q+1;
				//queue[r].i = p;   
				dir = 1; 
			}

			else if(dir == 3)//up
			{
				//++r;
				if(p == N-1)
					p = 0; 
				else
					p = p+1;
				//queue[r].j = q;
				dir = 4;
			}
			else if(dir == 4)//down
			{
				//++r;
				if(q == 0)
					q = N-1; 
				else
					q = q-1;
				//queue[r].i = p;   
				dir = 2;    
			}
				
		} 
		else if(shapes[p][q] == 2  && strn[p][q])   //shape 2
		{
			strn[p][q]--;
			if(!strn[p][q])
			{
				exits[p]++;
				exits[N+q]++;
			}
			if(dir == 1)//right
			{ 
				//++r;
				if(p == 0)
					q = N-1; 
				else
					q = p-1;
				//queue[r].j = q;   
				dir = 2;
			}

			else if(dir == 2)//left
			{
				
				//++r;
				if(p == 0)
					p = N-1; 
				else
					p = p-1;
				//queue[r].j = q;
				dir = 3; 
			}

			else if(dir == 3)//up
			{
				//++r;
				if(p == N-1)
					p = 0; 
				else
					p = p+1;
				//queue[r].j = q;
				dir = 4;
			}
			else if(dir == 4)//down
			{ 
				++r;
				if(q == N-1)
					q = 0;
				else
					q = q+1;
				//queue[r].i = p;   
				dir = 1;    
			}
				
		}
		else if(shapes[p][q] == 3  && strn[p][q]) //shape 3
		{
			strn[p][q]--;
			if(!strn[p][q])
			{
				exits[p]++;
				exits[N+q]++;
			}
			if(dir == 1)//right
			{ 
				//++r;
				if(p == N-1)
					p = 0; 
				else
					p = p+1;
				//queue[r].j = q;   
				dir = 4;
			}

			else if(dir == 2)//left
			{
				//++r;
				if(q == N-1)
					q = 0;
				else
					q = q+1;
				//queue[r].i = p;
				dir = 1; 
			}

			else if(dir == 3)//up
			{
				//++r;
				if(q == 0)
					q = N-1; 
				else
					q = q-1;
				//queue[r].i = p;   
			 
				dir = 2;
			}
			else if(dir == 4)//down
			{ 
				//++r;
				if(p == 0)
					p = N-1; 
				else
					p = p-1;
				//queue[r].j = q;
				dir = 3;
			}
				
		}

		else if(shapes[p][q] == 4  && strn[p][q]) //shape 4
		{
			strn[p][q]--;
			if(!strn[p][q])
			{
				exits[p]++;
				exits[N+q]++;
			}
			if(dir == 1)//right
			{ 
				//++r;
				if(q == 0)
					q = N-1; 
				else
					q = q-1;
				//queue[r].i = p;   
			 
				dir = 2;
			}

			else if(dir == 2)//left
			{
					//++r;
				if(p == N-1)
					p = 0; 
				else
					p = p+1;
				//queue[r].j = q;   
				dir = 4; 
			}

			else if(dir == 3)//up
			{
			
				//++r;
				if(q == N-1)
					q = 0;
				else
					q = q+1;
				//queue[r].i = p;
				dir = 1;
			}
			else if(dir == 4)//down
			{ 
				++r;
				if(p == 0)
					p = N-1; 
				else
					p = p-1;
				//queue[r].j = q;
				dir = 3;
			}
				
		}

		else if(shapes[p][q] == 5  && strn[p][q]) //shape 5
		{
			strn[p][q]--;
			if(!strn[p][q])
			{
				exits[p]++;
				exits[N+q]++;
			}
			if(dir == 1)//right
			{ 
				//	++r;
				if(q == 0)
					q = N-1; 
				else
					q = q-1;
				//queue[r].i = p;   
			 
				dir = 2;
			}

			else if(dir == 2)//left
			{
				//++r;
				if(q == N-1)
					q = 0;
				else
					q = q+1;
				//queue[r].i = p;   
				dir = 1; 
			}

			else if(dir == 3)//up
			{
				//++r;
				if(p == N-1)
					p = 0; 
				else
					p = p+1;
				//queue[r].j = q;
				dir = 4;
			}
			else if(dir == 4)//down
			{ 
				//++r;
				if(p == 0)
					p = N-1; 
				else
					p = p-1;
				//queue[r].j = q;
				dir = 3;
			}
				
		}
		else
		{
			if(dir == 1)//right
			{ 
				if(exits[q+N] == N)break;
				//++r;
				if(q == N-1)
					q = 0;
				else
					q = q+1;
				//queue[r].i = p;
			}

			else if(dir == 2)//left
			{
				if(exits[N+q] == N)break;
				//++r;
				if(q == 0)
					q = N-1; 
				else
					q = q-1;
				//queue[r].i = p;   
			 
			}

			else if(dir == 3)//up
			{
				if(exits[p] == N)break;
				//++r;
				if(p == 0)
					p = N-1; 
				else
					p = p-1;
				//queue[r].j = q;   
			}
			else if(dir == 4)//down
			{
				if(exits[p] == N)break;
				//++r;
				if(p == N-1)
					p = 0; 
				else
					p = p+1;
				//queue[r].j = q;   
			}
		} 
	}



}




void copy()
{
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			visited[i][j] = 0;
			strn[i][j] = cpstrn[i][j];
			if(shapes[i][j] == 0)
			{
			  exits[N+j]++;
			  exits[i]++;
			}
		}
	}
}

void exitzero()
{
   for(int i=0;i<N;i++)
   {
	   exits[i] = 0;
	   exits[i+N] = 0;
   }

}

int main()
{
	cin>>T;
	int number;
	while(T--)
	{
		cin>>N;
		for(int i=0;i<N;i++)
		{
			for(int j=0;j<N;j++)
			{
				cin>>number;
				if(number == 0)
				{
					cpstrn[i][j] = 0;
					shapes[i][j] = 0;
					exits[i]++;
					exits[N+j]++;
				}
				else
				{
					shapes[i][j] = number/10;
					cpstrn[i][j] = number%10;
				}
			}
		}
	
		int maxs = 0;
		for(int i=0;i<N;i++)
		{
			for(int j=0;j<N;j++)
			{
				if(shapes[i][j] == 0)
				{
					cnt = 0;
					exitzero();
					copy();
					dobfs(i,j,1);
					if(maxs < cnt)
						maxs = cnt;

					cnt = 0;
					exitzero();
					copy();
					dobfs(i,j,2);
					if(maxs < cnt)
						maxs = cnt;

					cnt = 0;
					exitzero();
					copy();
					dobfs(i,j,3);
					if(maxs < cnt)
						maxs = cnt;

					cnt = 0;
					exitzero();
					copy();
					dobfs(i,j,4);
					if(maxs < cnt)
						maxs = cnt;
				}
			} 
		}

		cout<<"ans :"<<maxs;
	}

	return 0;
}



/*

5
5
0  0  0  32  0
0  21 0  0  14
0  0  11 0   0
47  11  0 0   34
11 0  0  11  0


*/