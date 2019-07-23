// dijkastras.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;
 
int cnt = 0;
list<string> lst;
int checkpal(string str,int i,int j)
{
	int k;

	
	while(i<=j)
	{
		if(str[i] != str[j])
		return 0;
		i++,j--;
	}
	return 1;
}
void addinlst(string str,int i,int j)
{
	string kstr;

	 
	auto it = kstr.cbegin();
	 

	
		 kstr.insert (it,str.begin()+i,str.begin()+j);
		
		//std::cout << *it;
	
	lst.push_back(kstr);
	
}
int palindrome(string str) {
int i,j;

for(i=0;i<str.length();i++)
{
	for(j=i;j<str.length();j++)
	{
		if(str[i] == str[j])
		{
		   string kstr;
		   auto it= kstr.cbegin();

		   		 kstr.insert (it,str.begin()+i,str.begin()+j);
 
				 list<string>::iterator its = lst.begin();
				 int ch = 0;
				 for( ;its != lst.end();its++)
				 {
					 if( kstr.compare(*its))
					{
						ch = 1;
						break;
					}
				 }

				 if(ch)
					 continue;
		 int isp = checkpal(str,i,j);
		 cnt+=isp;
		 if(isp)
		 {
		   addinlst(str,i,j);
		 }
		}
	}
}
return cnt;

}

int main() {
 //   ofstream fout(getenv("OUTPUT_PATH"));
    int res;
    string _str;
    getline(cin, _str);
    //cin>>_str;
	//cin>>str;
    res = palindrome(_str);
    cout <<res<<endl;
    
    //fout.close();
    
    system("pause");
    return 0;
}
