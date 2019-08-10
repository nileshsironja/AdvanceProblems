#include<iostream>
#include<queue>
#include<string.h>
#define SIZE 8
using namespace std;

typedef pair<int,int> pairInt;
pairInt pi;

int dirx[SIZE] = {1,4,2,5,6,7,6,5};
int diry[SIZE] = {2,6,1,5,7,1,4,9};

int main()
{
	queue<pairInt> Q;
	int x,y,lvl=0;
	bool visited[SIZE][SIZE];
	
	memset(visited,  false, sizeof(visited));
	
	Q.push(make_pair(3,5));
	Q.push(make_pair(2,6));
	Q.push(make_pair(12,16));
	Q.push(make_pair(32,46));

	//pi = Q.front();
	//cout<<pi.first<<"  "<<pi.second<<endl;

	
	
	while(!Q.empty())
	{
		pi = Q.front();
		//cout<<pi.first<<"  "<<pi.second<<endl;
		x = pi.first, y = pi.second;
		if(x == -1 && y == -1)
		{
	    	Q.push(make_pair(x,y));
	    	Q.pop();
	    	continue;
		}
		visited[x][y] = true;
		lvl++;
		for(int i=0;i<SIZE;i++)
		{
			int m = x+dirx[i], n = y+diry[i];
			if(checkValid(m,n) && !visited[m][n])	
			{
				Q.push(make_pair(m,n));
			}	
		}			
		Q.pop();
	}
	
	
	return 0;

}
