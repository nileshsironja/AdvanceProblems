// MoonJourney.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <vector> 
#include <list>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <functional>
#include <numeric>
#include <cstdlib>
#include <cmath>
#include <cstdio>
#include <fstream>
#include <ctime>
#include <cassert>

using namespace std; // }}}
int visited[100001];
int totalcnt = 0;
int cnt = 0;
//vector<vector<int> > pairs(100001);

list<int> *ad;
void dodfs(int v)
{
	visited[v] = 1;
	cnt++;
	 
	list<int>::iterator it;
	for(it = ad[v].begin(); it != ad[v].end(); it++)
	{
		if(!visited[*it])
			dodfs(*it);
	}
    
}

int main()
{ 
    int N, I;
    cin >> N >> I;
    
	ad = new list<int>[N];

    for (int i = 0; i < I; ++i) {
        int a, b;
        cin >> a >> b;
        ad[a].push_back(b);
        ad[b].push_back(a);
    }
 
    long long result = 0;
    
	//vector<vector<int> >::iterator it = pairs.begin(); 
	list<int>::iterator it;
	int sum[100001];int k=0;
	for(int i=0;i<N;i++)
	{
		cnt = 0;
		//vector<int>::iterator itr = it->begin();
		//if(itr == it->end()) break;

		if(!visited[i])
		{
		   dodfs(i);
		   sum[k++] = cnt;
		}
	}
	long long total = 0;
    for(int i=0;i<k;i++)
		for(int j=i+1;j<k;j++)
		total = total + sum[i] * sum[j];
    
	
	cout << total << endl;
    return 0;
}

/*

4 2
0 1
2 3

*/
