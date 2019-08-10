#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
typedef pair<int,int> pi;
struct Person
{
	int height, weight;
};
int main()
{

	#ifdef MIN
	priority_queue<pi, vector<pi>, greater<pi> > Q;
	#else
	priority_queue<pi> Q;
	#endif
	Q.push(make_pair(5,3));
	Q.push(make_pair(6,9));
	Q.push(make_pair(13,2));
	Q.push(make_pair(23,8));
	
	
	pair<int,int> p = Q.top();
	//cout<<p.first<<" "<<p.second;

	while(!Q.empty())
	{
		p = Q.top();
		cout<<p.first<<" "<<p.second<<endl;
		Q.pop();
	}

	return 0;
}



