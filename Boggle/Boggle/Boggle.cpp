// Boggle.cpp : main project file.

#include "stdafx.h"
#include<iostream>
#include<stdio.h>
#include<string>
#define M 3
#define N 3
using namespace std;

string dic[] = {
				"GEEKS","FOR","QUIZ","GO"	 
				};

string word;
int a;
int check(string word)
{
	int i; 


	for(i=0;i<M;i++)
	{
		if(!dic[i].compare(word))
			{cin>>a;
		return 1;} 
	}
	return 0;
}

void dfsword(char boggle[][N],int *visited,int p,int q,string word)
{
	int i,j;

	
	word = word + boggle[p][q];
	*((visited+p)+q) = 1;
	if(check(word))
	 {
		  
		 cout<<endl<<word; 
		 return;
	 }
	//for (int row=i-1; row<=i+1 && row<M; row++)
      //for (int col=j-1; col<=j+1 && col<N; col++)

    cout<<endl<<word;
	for(i=p-1; i<=p+1 &&  i<M;i++)
	{
		for(j=q-1; j<=q+1 && j<N;j++)
		{ 
			if(i>=0 && j>=0 && !*((visited+i)+j))
			dfsword(boggle,visited,i,j,word);
			
		}
	} 
	word.erase(word.length()-1);
	*((visited+p)+q) = 0;
}

void findWords(char boggle[][N])
{
	int i = 0,j = 0;
	//for(i=0;i<M;i++)
	//	cout<<endl<<dic[i]; 
	int *visited = (int *) malloc(sizeof(int)*M*N);
	 memset(visited,0,sizeof(int)*M*N);
	 string word;

	for(i=0;i<M;i++)
	{
		for(j=0;j<N;j++)
		{
			memset(visited,0,sizeof(int)*M*N);
			dfsword(boggle,visited,i,j,word);
		}
	} 
}


// Driver program to test above function
int main()
{
    char boggle[M][N] = {{'G','I','Z'},
                       {'U','E','K'},
                       {'Q','S','E'}};
 
    cout << "Following words of dictionary are present\n";
    findWords(boggle);
	system("pause");
    return 0;
}