// Bus_Route.cpp : main project file.

#include "stdafx.h"
#include<iostream>
#define N 5001
using namespace std;

int mat[N][N];
int val[N][N];
int startpt[N];
int check[N];

int n;
/*input

2
7 7
1 3
3 4
3 5
4 6
2 3
5 6
6 7

*/

void dodfs(int v)
{
	int i;
	for(i=1; val[v][i] ;i++)
	{ 
		  mat[v][i]++;
		  dodfs(val[v][i]);
	   
	} 
}

int main()
{
	int t,m,a,b,cases=1;
	cin>>t;
	while(t--)
	{
	  cin>>n>>m;
	  memset(mat,0,sizeof(mat));
	  while(m--)
	  {
	    cin>>a>>b;
		startpt[b] = 1;
		check[a]++;
	    val[a][check[a]] = b;
		
	  }

	  for(a=1;a<=n;a++)
	  {
		  for(b=1;b<=n;b++)
		  {
			  cout<<val[a][b]<<" ";
		  }
		  cout<<endl;
	  }
	   
	  for(b=1;b<=n;b++)
		 if(!startpt[b])
		  dodfs(b);
  
	  int max = INT_MIN;
	  for(a=0;a<n;a++)
	  {
		  for(b=0;b<n;b++)
			  {
				  if(mat[a][b] > max)
				  max = mat[a][b];
				  //cout<<" "<<mat[a][b];
		  }
		  //cout<<endl;
	  }
	  cout<<"Case #"<<cases<<endl<<max<<endl;
	}
	
    return 0;
}
