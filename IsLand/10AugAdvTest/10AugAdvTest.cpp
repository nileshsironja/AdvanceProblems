// 10AugAdvTest.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#define CNT 3
#define SIZE 61
using namespace std;

/*

15
10
4 5
6 2
10 2
10
8 5
9 1
10 2
24
15 3
20 4
23 7
39
17 8
30 5
31 9
60
57 12
31 19
38 16



18
25
57
86
339
*/


int T,N;
struct Gate
{
	int no,fm;
};
struct Gate G[CNT];

void empty(int arr[])
{
	for(int i=0;i<=N;i++)
		arr[i] = 0;
}
void copy(int arr1[],int arr2[])
{
	for(int i=0;i<=N;i++)
		arr1[i] = arr2[i];
}

int absl(int a, int b)
{
	if(a > b)
		return a-b;
	else
		return b-a;
}
int arr1[SIZE],arr2[SIZE],arr3[SIZE];

int insert(int arr[],int gateno,int left)
{
	int gno = G[gateno].no;
	int person = G[gateno].fm;
	int minlen = 0;
	if(left)
	{
		int counts = 0, j = 0;
		for(int i = gno;  person && j <= N ; j++)
		{
			if(i == gno && arr[i] == 0)
			{
				minlen++;
				arr[i] = 1; 
				person--;
			}	
			else
			{
				if(i-j > 0 && person && arr[i-j] == 0)  //fill left first then right
				{
			  		arr[i-j] = 1;
					minlen += (j + 1);
					person--;
				}
				if(i+j <= N  && person && arr[i+j]  == 0)  //fill left first then right
				{
			  		arr[i+j] = 1;
					minlen += (j + 1);
					person--;
				}
			}
		}
	}
	else
	{
		int counts = 0, j = 0;
		for(int i = gno;  person && j <= N; j++)
		{
			if(i == gno && arr[i] == 0)
			{
				minlen++;
				arr[i] = 1;
				person--;
			}
			else
			{
			    if(i+j <= N  && person && arr[i+j] == 0)  //fill left first then right
				{
			  		arr[i+j] = 1;
					minlen += (j + 1);
					person--;
				}
				if(i-j >0 &&  person && arr[i-j] == 0)  //fill left first then right
				{
			  		arr[i-j] = 1;
					minlen  += (j + 1);
					person--;
				}
			}
		}
	} 
	return minlen;
}
 
int fill(int one,int two,int thr)
{
	int min1=0,min2=0,min3=0,finalmin=9999999;
	for(int i=0; i<= 1 ; i++)
	{
		empty(arr1);
		if(i == 0)
			min1 = insert(arr1,one,1);
		else
			min1 = insert(arr1,one,0);

		
		for(int j=0; j<= 1 ; j++)
		{
			empty(arr2); 
			copy(arr2,arr1);
			if(j == 0)
			min2 = insert(arr2,two,1);
			else
			min2 = insert(arr2,two,0);
			 
			for(int k=0; k<= 1 ; k++)
			{
				empty(arr3); 
				copy(arr3,arr2);
				if(k == 0)
				min3 = insert(arr3,thr,1);
				else
				min3 = insert(arr3,thr,0);

				if(finalmin > min1+min2+min3)
					finalmin = min1+min2+min3;
			}
		}
	}
	return finalmin;
}
 

int main()
{

	cin>>T;
	while(T--)
	{
		cin>>N;
		for(int i=0;i<CNT;i++)
			cin>>G[i].no>>G[i].fm;
		 
		finalmin=9999999;
		int minans = 999999;
		for(int i=0;i<CNT;i++)
		{
			for(int j=0;j<CNT;j++)
			{
				for(int k=0;k<CNT;k++)
				{
					if(i == j || j == k || k == i)
						continue;
					int ans = fill(i,j,k,0);
					if(minans > ans)
						minans = ans;
				}
			}
		}

		cout<<"ANS : "<<minans<<endl;
	}
	return 0;
}




//working fill
//int fill(int one,int two,int thr)
//{
//	int min1=0,min2=0,min3=0,finalmin=9999999;
//	for(int i=0; i<= 1 ; i++)
//	{
//		empty(arr1);
//		if(i == 0)
//			min1 = insert(arr1,one,1);
//		else
//			min1 = insert(arr1,one,0);
//
//		
//		for(int j=0; j<= 1 ; j++)
//		{
//			empty(arr2); 
//			copy(arr2,arr1);
//			if(j == 0)
//			min2 = insert(arr2,two,1);
//			else
//			min2 = insert(arr2,two,0);
//			 
//			for(int k=0; k<= 1 ; k++)
//			{
//				empty(arr3); 
//				copy(arr3,arr2);
//				if(k == 0)
//				min3 = insert(arr3,thr,1);
//				else
//				min3 = insert(arr3,thr,0);
//
//				if(finalmin > min1+min2+min3)
//					finalmin = min1+min2+min3;
//			}
//		}
//	}
//	return finalmin;
//}
 