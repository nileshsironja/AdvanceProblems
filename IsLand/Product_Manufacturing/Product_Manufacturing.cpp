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

void getfinalmax()
{
	if(maxsum < (maxsum + D*d + E*e))
		maxsum = maxsum + D*d + E*e;
}

void getprofit(int m,int n,int o)
{
	for(i=0;i<100;i++)
	{
		if(D- i*M[m].a < 0 || E-i*M[m].b < 0 || F-i*M[m].c < 0)
			break;
 
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
 				if(D- k*M[o].a < 0 || E- k*M[o].b < 0 || F- k*M[o].c < 0)
					break;
			}

			if(k > 0)
			{
				int sum3 = (k-1) * M[o].p;

				getmax(sum1+sum2+sum3);
				D = D - (k-1) * M[o].a;
				E = E - (k-1) * M[o].b;
				 
				getfinalmax();

				D = D + (k-1) * M[o].a;
				E = E + (k-1) * M[o].b;
				

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

void getprofit_1(int m,int o)
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
		  
			for(k=0;k<100;k++)
			{
 				if(D- k*M[o].a < 0 || E- k*M[o].b < 0 || F- k*M[o].c < 0)
					break;
			}

			if(k > 0)
			{
				int sum3 = (k-1) * M[o].p;

				getmax(sum1+sum3);

				D = D - (k-1) * M[o].a;
				E = E - (k-1) * M[o].b;
				 
				getfinalmax();

				D = D + (k-1) * M[o].a;
				E = E + (k-1) * M[o].b;
				

 			}
			D = (D + i * M[m].a);
			E = (E + i * M[m].b);
			F = (F + i * M[m].c);
		  
	}
}


void getprofit_2(int o)
{
 		  
			for(k=0;k<100;k++)
			{
 				if(D- k*M[o].a < 0 || E- k*M[o].b < 0 || F- k*M[o].c < 0)
					break;
			}

			if(k > 0)
			{
				int sum3 = (k-1) * M[o].p;

				getmax(sum3);

				D = D - (k-1) * M[o].a;
				E = E - (k-1) * M[o].b;
				 
				getfinalmax();

				D = D + (k-1) * M[o].a;
				E = E + (k-1) * M[o].b;
				
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

void No_production()
{
	if(maxsum + D*d + E*e > maxsum)
	{
		maxsum = maxsum + D*d + E*e;
	} 
}

void calculate()
{
	int ii,jj,kk;

	No_production();

	if(N == 1)
	{
		for(ii=0;ii<N;ii++)
		{
			getprofit_2(i);
		}
		return;
	}
 	
	if(N == 2)
	{
		for(ii=0;ii<N;ii++)
		{
			for(jj=0;jj<N-1;jj++)
			getprofit_1(ii,jj);
		}
		return;
	}

	for(ii=0;ii<N;ii++)
	{
		for(jj=0;jj<N-1;jj++)
		{
			if(ii == jj)
				continue;
			for(kk=0;kk<N-2;kk++)
			{
				if(jj == kk || kk == ii)
					continue;
				getprofit(ii,jj,kk);
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

