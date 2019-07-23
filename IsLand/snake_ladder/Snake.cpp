// snake_ladder.cpp : main project file.

#include "stdafx.h"
#include<iostream>
#include<limits.h>
using namespace std;
#define N 30
int moves[N];
int visited[N];
int ncnt = INT_MAX;

//1.base condition/terminate condition
//2.corner cases
//3.optimized condition
//4.backtracking

void getMinDiceThrows(int index,int count)
{
	if(index > 30 || index < 0)  // 2.corner cases
		return;
	
	if(moves[index] == 30 || index == 30)  // 1. base / terminate condition
	{
		if(ncnt > count)
			ncnt = count;
		return;
	}

	if(count >= ncnt)   // 3. optimized condition
		return;
	 

	for(int i=1;i<=6;i++) // 4. backtracking loop
	{
		//ladder
		if(moves[index] != -1 && moves[index] > index)
			getMinDiceThrows(moves[index], count);
		//snack
		if(moves[index] != -1 && moves[index] < index)
			getMinDiceThrows(moves[index], count);

		getMinDiceThrows(index + i, count+1);

	}

}


// Driver program to test methods of graph class
int main()
{
    // Let us construct the board given in above diagram
    
    for (int i = 0; i<N; i++)
        moves[i] = -1;
 
    // Ladders
    moves[2] = 15;
   // moves[4] = 7;
    //moves[10] = 25;
    moves[19] = 23;
    
	// Snakes
    moves[24] = 17;
    moves[20] = 8;
    moves[16] = 3;
    moves[18] = 6;
	 
	getMinDiceThrows(0,0);
    cout << "Min Dice throws required is " <<ncnt << endl;

	// for (int i = 0; i<N; i++)
      //  cout<<" "<<visited[i];
 

	system("pause");

    return 0;
}
