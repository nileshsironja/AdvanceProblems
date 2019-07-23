// GameofStones.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#define SIZE 101
using namespace std;

int judge[SIZE][3];
int T,N;


/*
int playGame(int player,int N)
{
	if(N < 2 && player == 1){judge[N][player] = 2; return 2;}   //base condition
	if(N < 2 && player == 2){judge[N][player] = 1; return 1;}	//base condition

	if(judge[N][player] != -1) return judge[N][player]; //optimized
	
	//player 1
	if(player == 1)
	{
		int winner = playGame(2,N-2);
		judge[N][winner] = winner;
		winner = playGame(2,N-3);
		judge[N][winner] = winner;
		winner = playGame(2,N-5);
		judge[N][winner] = winner; 
	}
	else  //player 2
	{  
		int winner = playGame(1,N-2);
		judge[N][winner] = winner;
		winner = playGame(1,N-3);
		judge[N][winner] = winner;
		winner = playGame(1,N-5);
		judge[N][winner] = winner; 
	}
}
*/

int dp[SIZE];
void playGame()
{
	dp[0]=dp[1]=0;
	dp[2] = 1;
	dp[3] = 1;
	dp[4] = 1;
	dp[5] = 1;
	//dp[6] = 1;
	//dp[7] = 0;
	for(int i=6;i<SIZE;i++)
	{
		if(dp[i-2] == 0 || dp[i-3] == 0 || dp[i-5] == 0)
		{
			dp[i] = 1;
		} 
		else
			dp[i] = 0;
	}

}
int main()
{
	int p;
	cin>>p;

	while(p--)
	{
		cin>>N;
		/*for(int i=0;i<SIZE;i++)
		{
			judge[i][1] = -1;
			judge[i][2] = -1;
		}*/
		playGame();
		/*int first=0,second=0;
		for(int i=0;i<=N;i++)
		{
			if(judge[i][1] == 1)first++;
			else if(judge[i][1] == 2)second++;
			else if(judge[i][2] == 1)first++;
			else if(judge[i][2] == 2)second++;
		}
		if(first > second)	cout<<"1"<<endl;
		else	cout<<"2"<<endl;*/
		if(dp[N] == 0)cout<<"Second"<<endl;
		else cout<<"First"<<endl;
		
		//cout<<dp[N]<<endl;

	}


	return 0;
}

