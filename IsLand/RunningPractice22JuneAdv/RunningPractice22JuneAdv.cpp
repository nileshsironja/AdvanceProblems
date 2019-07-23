// RunningPractice22JuneAdv.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
using namespace std;

int T,H,D;
int mins[6],secs[6],eng[6];

long long int TIMES = INT_MAX;
/*

5
130 30
4 50 7
5 0 5
5 10 4
5 20 3
5 30 2


91 30
4 50 7
5 0 5
5 10 4
5 20 3
5 30 2

*/

void getmin(int d, int h, long long int time, int level)
{
	if(h > H || d > D) return ; 
	if(level >= 5) return ;
	//statement for reducing the complexities
	if(time > TIMES)
		return ;
	//base condition
	if(d == D && h <= H)
	{
		 if( time < TIMES )
		 {
			 TIMES = time;
			 cout<<TIMES<<endl;
			 //return TIMES;
		 }
	} 
	for(int i = 0; i <= D; i++)
	{ 
		//cout<<endl<<"d :"<<d<<" "<<"h :"<<h;
   		getmin(d+i,eng[level]*(d+i),(mins[level]*60+secs[level])*(d+i),level+1); 
	} 
}

int main()
{ 
	cin>>T;
	while(T--)
	{
		cin>>H>>D;
		for(int i=0;i<5;i++)
			cin>>mins[i]>>secs[i]>>eng[i];
		TIMES = INT_MAX;
 		getmin(0,0,0,0);
		cout<<TIMES/60<<" "<<TIMES%60<<endl;
	}
	 
	return 0;
}



//my fucked solution with O(5^D) complexities, pruning
/*long long int getmin(int d, int h, long long int time)
{
	if(h > H || d > D) return TIMES;
 
	//base condition
	if(d == 0 && h <= H)
	{
		 if( time < TIMES )
		 {
			 TIMES = time;
			 cout<<TIMES<<endl;
			 return TIMES;
		 }
	}
 	long long int m,n,o,p,q;

	m = getmin(d-1,h+eng[0],time + mins[0]*60 + secs[0]);
	n = getmin(d-1,h+eng[1],time + mins[1]*60 + secs[1]);
	o = getmin(d-1,h+eng[2],time + mins[2]*60 + secs[2]);
	p = getmin(d-1,h+eng[3],time + mins[3]*60 + secs[3]);
	q = getmin(d-1,h+eng[4],time + mins[4]*60 + secs[4]);


	long long int cnt1=0,cnt2=0,cnt3=0;

	return ((cnt3 = ((cnt2 = (cnt1 = m > n ? m : n) > o ? cnt1 : o)) > p ? cnt2 :p) > q ? cnt3 : q);
}*/


/*

T = no of test cases
H = physical energy
D = Distance
M = mins
S = secs
Eg = energy ate

Input formate
T<=50
50<=H<=600  5<=D=<50 
M<6 S<59 Eg


5
130 30
4 50 7
5 0 5
5 10 4
5 20 3
5 30 2


91 30
4 50 7
5 0 5
5 10 4
5 20 3
5 30 2


3 30 11
3 50 5
4 10 3
4 30 2
4 50 1


10 5
6 10 6
6 29 5
6 39 4
6 49 3
6 59 2


600 40
3 11 20
3 18 16
3 36 14
3 41 13
3 56 12



Output 
150 20
159 50
76 40
34 55
137 11



*/

//approach 1 : use 5-for loops and get no of combinations = (D*D*D*D*D)
//approach 2 : use recursion technique = (D*D*D*D*D)
//approach 3 : use recustion technique = (5^D) and here i was got fucked.
