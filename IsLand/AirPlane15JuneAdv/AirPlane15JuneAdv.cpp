// AirPlane15JuneAdv.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
//#include<iostream>
//#define S 5
//#define N 9
//using namespace std;
//
//int game[N][S] = {
//					{1,0,1,1,0},
//					{2,2,2,2,2},
//					{2,1,0,2,1},
//					{1,2,0,1,2},
//					{2,2,2,2,2},
//					{0,0,0,0,1},
//					{1,0,0,1,1},
//					{0,2,1,2,2},
//					{1,1,1,1,1},
//				 };
//	
//int state[N][S];
//
//void copy()
//{
//	for(int i=0;i<N;i++)
//		for(int j=0;j<S;j++)
//			state[i][j] = game[i][j];	
//
//}
//
//void bombed(int rows)
//{
//	for(int i=rows;i>=0;i--)
//		for(int j=0;j<5;j++)
//			if(state[i][j] == 2)
//				state[i][j] = 0;
//}
//int maxcoin(int mcoins,int pos,int rows,int bomb)
//{
//	//if reached at destination
//	if(rows < 0)
//		return mcoins;
//	//if out of boundary in game zone
//	if(pos < 0 && pos > rows)
//		return mcoins;
//	//if running out of coin
//	if(mcoins < 0)
//		return mcoins;
//	//if it's a coin
//	if(state[rows][pos] == 1)
//		mcoins++;
//	//if it's a enemy
//	if(state[rows][pos] == 2)
//		mcoins--;
//
//	int amax=0,bmax=0;
//	//if bomb is there. With BOMB;
//	if(bomb && rows > 4)
//	{
//		bombed(rows);
//		bomb = 0;
//
//		int lpos = maxcoin(mcoins,pos-1,rows-1,bomb);
//		int tpos = maxcoin(mcoins,pos,rows-1,bomb);
//		int rpos = maxcoin(mcoins,pos+1,rows-1,bomb);
//	
//		int lcoins = 0, rcoins = 0;
//
//		amax = mcoins > (rcoins = (lcoins = (lpos > tpos) ? lpos : tpos) > rpos ? lcoins : rpos ) ? mcoins : rcoins;
//
//		bomb = 1;
//		copy(); 
//		//return mcoins;
//	}
//	//Without BOMB;
//		//cout<<"rows :"<<rows<<" bomb :"<<bomb<<endl;
//		int lpos = maxcoin(mcoins,pos-1,rows-1,bomb);
//		int tpos = maxcoin(mcoins,pos,rows-1,bomb);
//		int rpos = maxcoin(mcoins,pos+1,rows-1,bomb);
//	
//		int lcoins = 0, rcoins = 0;
//		bmax = mcoins > (rcoins = (lcoins = (lpos > tpos) ? lpos : tpos) > rpos ? lcoins : rpos ) ? mcoins : rcoins;
//		return amax>bmax?amax:bmax;
//}
//
//int main()
//{
//	copy();
//
//	int ans = maxcoin(0,2,N-1,1);
//
//	cout<<ans;
//
//	system("pause");
//	return 0;
//}
//
