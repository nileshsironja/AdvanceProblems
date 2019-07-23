// Product_Manufacturing.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#define S 8
#include<iostream>
using namespace std;

int D,E,F,d,e;
int N;
int i,j,k;
struct model
{
	int a,b,c,p; 
};
struct model M[S];

int maxsum = 0;

void getmax(int sum)
{
	if(sum > maxsum)
		maxsum = sum;
}

 
void fun(int t,int cnt)
{
	int count = 0;
	while(D- count*M[t].a > 0 && E- count*M[t].b > 0 && F- count*M[t].c > 0)
	{
		count++;
	}
	int sum = count*M[t].p; 
	getmax(sum);

}

void getprofit(int m,int n,int o)
{
	for(i=0;i<100;i++)
	{
		if(D- i*M[m].a < 0 || E-i*M[m].b < 0 || F-i*M[m].c < 0)
			break;

		//fun(m,i);

		int sum1 = i * M[m].p;

		getmax(sum1);

		D = (D - i * M[m].a);
		E = (E - i * M[m].b);
		F = (F - i * M[m].c);

		for(j=0;j<100;j++)
		{
			if(D- j*M[n].a < 0 || E- j*M[n].b < 0 || F- j*M[n].c < 0)
				break;

			int sum2 = j * M[n].p;

			getmax(sum2+sum1);

			D = (D - j * M[n].a);
			E = (E - j * M[n].b);
			F = (F - j * M[n].c);
			int cnt =0;
			for(k=0;k<100;k++)
			{
//				cout<<endl<<i<<" "<<j<<" "<<k;

				if(D- k*M[o].a < 0 || E- k*M[o].b < 0 || F- k*M[o].c < 0)
					break;

				 //sum = k * M[m].p;

				//getmax(sum);

				D = (D -  M[o].a);
				E = (E -  M[o].b);
				F = (F -  M[o].c);
				//cnt = cnt + k ;
			}

			if(k > 0)
			{
				int sum3 = (k-1) * M[o].p;

				getmax(sum1+sum2+sum3);

				D = (D + (k-1) * M[o].a);
				E = (E + (k-1) * M[o].b);
				F = (F + (k-1) * M[o].c);
			}
			D = (D + j * M[n].a);
			E = (E + j * M[n].b);
			F = (F + j * M[n].c);
		}
		
		D = (D + i * M[m].a);
		E = (E + i * M[m].b);
		F = (F + i * M[m].c);

	}
}

/*

5
6 8 12 3 2
3
2 2 2 5
3 4 6 10
1 1 1 6

5
6 8 13 3 2
3
1 2 3 5
2 3 4 4
1 1 2 3


*/

void calculate()
{
	for(i=0;i<N;i++)
	{
		for(j=0;j<N-1;j++)
		{
			/*if(i == j)
				continue;*/
			for(k=0;k<N-1;k++)
			{
				/*if(j == k || k == i)
					continue;
				*/

				getprofit(i,j,k);
				
				//cout<<maxsum;

			}
		}
	}

}

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		cin>>D>>E>>F>>d>>e;
		cin>>N;
		for(i=0;i<N;i++)
			cin>>M[i].a>>M[i].b>>M[i].c>>M[i].p;

		calculate();
		cout<<endl<<maxsum;
	}

	return 0;
}

