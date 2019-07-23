// snake_ladder.cpp : main project file.

#include "stdafx.h"
//#include<iostream>
//#include<limits.h>
//using namespace std;
//#define N 30
//int moves[N];
//int visited[N];
//int ncnt = INT_MAX;
//
//
//void dodfs(int v,int cnt)
//{
//	int i,chk = v, kchk = 0;
//	//cout<<endl<<cnt;
//
//	for(i=v;i<29;i++)
//	{
//	  cout<<endl<<cnt;
//	  
//	  if(moves[i] != -1 && !visited[i])
//	  {     
//		   visited[i] = 1;
//
//			if(kchk)
//			cnt++;
//			dodfs(moves[i],cnt);
//			cnt--;
//			kchk = 0; 
//	  }/*
//	  else if( moves[i] != -1 && moves[i] < i)
//	  { 
//			cnt++;
//			chk = i+1;
//	  }*/
//	  if(i-chk == 6)
//	  {
//		    cnt++;
//			chk = i;
//
//			if( moves[i] != -1 && moves[i] < i)
//			  chk = i - 1;
//	  }
//	  if(i+1 == 29)cnt++;
//	  kchk++;
//	} 
//	 
//
// 	if(ncnt > cnt)
//	{
//		ncnt = cnt; 
//	} 
//}
//
//int getMinDiceThrows()
//{
//	//int cnt = 0;
//	dodfs(0,0);
//	return ncnt;
//}

// Driver program to test methods of graph class
/*int main()
{
    // Let us construct the board given in above diagram
    
    for (int i = 0; i<N; i++)
        moves[i] = -1;
 
    // Ladders
    moves[2] = 21;
    moves[4] = 7;
    moves[10] = 25;
    moves[19] = 29;
    
	// Snakes
    moves[25] = 19;
    moves[20] = 8;
    moves[16] = 3;
    moves[18] = 6;
	 
    cout << "Min Dice throws required is " << getMinDiceThrows() << endl;

	 for (int i = 0; i<N; i++)
        cout<<" "<<visited[i];
 

	system("pause");

    return 0;
}*/
