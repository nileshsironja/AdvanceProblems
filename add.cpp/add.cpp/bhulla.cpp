// add.cpp.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<limits.h>
#include<list>
#include<algorithm>
using namespace std;


int main()
{
	 int T,N;
	cin>>T;

	
	 int min1 = INT_MAX,min2 = INT_MAX,min3 = INT_MAX;
	 int a,b,c,f,s,t,no;
	while(T--)
	{
	  cin>>N;
	  cin>>a>>b>>c;
	  f=1,s=1,t=1;
	  no = (a<b)?(a<c?a:c):(b<c?b:c);
	  if(no == a && f)
	  {
		  if(min1 > a)
			  min1 = a;
		  f = 0, s = 1, t = 1;
	  }
	  if(no == a && !f)
	  {
		  no = (b<c)?b:c;
		  if(no == b && s)
		  {
			  if(min2 > b)
				  min2 = b;
			  f = 1, s = 0, t = 1;
		  }
		  else
		  {
		    
		  
		  }

	  }
		  

	  cout<<min1+min2+min3<<endl;
	  
 	}
	return 0;
}

/*  
	  N-=2;j=0;
	  min1 = INT_MAX,min2 = INT_MAX,min3 = INT_MAX;
	  while(N--)
	  {
		  
		  if(j==0)
		  {j++;
			cin>>a>>b>>c>>d>>e>>f>>g>>h>>i;
			//a , d , g

		  no1 = (a<d)?(a<g?a:g):(d<g?d:g);
	      no2 = (b<e)?(b<h?b:h):(e<h?e:h);
		  no3 = (c<f)?(c<i?c:i):(f<i?f:i);
		  no = (no1<no2)?(no1<no3?no1:no3):(no2<no3?no2:no3);

		  if(no == a)
		  {
			min1 = no;
			no1 = (e<h)?e:h;
			no2 = (f<i)?f:i;
			no = no1<no2?no1:no2;
			if(no == e || no == i)
			{
				  min2 = e;
				  min3 = i;
			}
			else 
			{
			      min2 = h;
				  min3 = f;
			} 
			 
		  }

		  else if(no == b)
		  {
			  //cout<<" in b ";
			min2 = no;
			no1 = (d<g)?d:g;
			no2 = (f<i)?f:i;
			no = no1<no2?no1:no2;
			if(no == d || no == i)
			{
				  min1 = d;
				  min3 = i;
			}
			else 
			{
			      min1 = g;
				  min3 = f;
			}
		  }

		  
  		  else if(no == c)
		  {
			min3 = no;
			no1 = (d<g)?d:g;
			no2 = (e<h)?e:h;
			no = no1<no2?no1:no2;
			if(no == d || no == h)
			{
				  min1 = d;
				  min2 = h;
			}
			else
			{
			      min1 = g;
				  min2 = e;
			}
		  }

		  else if(no == d)
		  {
			min1 = no;
			no1 = (b<h)?b:h;
			no2 = (c<i)?c:i;
			no = no1<no2?no1:no2;
			if(no == b || no == i)
			{
				  min2 = b;
				  min3 = i;
			}
			else
			{
			      min2 = h;
				  min3 = c;
			}		  
		  }

		  
		  else if(no == e)
		  {
			min2 = no;
			no1 = (a<g)?a:g;
			no2 = (c<i)?c:i;
			no = no1<no2?no1:no2;
			if(no == a || no == i)
			{
				  min1 = a;
				  min3 = i;
			}
			else
			{
			      min1 = g;
				  min3 = c;
			}		  
		  }

		  else if(no == f)
		  {
			  
			min3 = no;
			no1 = (a<g)?a:g;
			no2 = (b<h)?b:h;
			no = no1<no2?no1:no2;
			if(no == a || no == h)
			{
				  min1 = a;
				  min2 = h;
			}
			else
			{
			      min1 = g;
				  min2 = b;
			}		  
		  }

		  else if(no == g)
		  {
			 
			min1 = no;
			no1 = (b<e)?b:e;
			no2 = (c<f)?c:f;
			no = no1<no2?no1:no2;
			if(no == b || no == f)
			{
				  min2 = b;
				  min3 = f;
			}
			else
			{
			      min2 = e;
				  min3 = c;
			}
		  }
		  else if(no == h)
		  {
			min2 = no;
			no1 = (a<d)?a:d;
			no2 = (c<f)?c:f;
			no = no1<no2?no1:no2;
			if(no == a || no == f)
			{
				  min1 = a;
				  min3 = f;
			}
			else
			{
			      min1 = d;
				  min3 = c;
			}
		  }

		  else if(no == i)
		  {
			min3 = no;
			no1 = (a<d)?a:d;
			no2 = (b<e)?b:e;
			no = no1<no2?no1:no2;
			if(no == a || no == e)
			{
				  min1 = a;
				  min2 = e;
			}
			else
			{
			      min1 = d;
				  min3 = b;
			}
		  }


		  }
		  else
		  {
		  cin>>a>>b>>c;
		  
		  no = (a<b)?(a<c?a:c):(b<c?b:c);

		  if(no == a)
		  {
			if(min1 > no)
				min1 = no;
		  
		  }
		  else if(no == b)
		  {
			  if(min2 > no)
				min2 = no;
		  
		  }
		  else
		  {
			  if(min3 > no)
				min3 = no;
		  
		  }
		  }*/