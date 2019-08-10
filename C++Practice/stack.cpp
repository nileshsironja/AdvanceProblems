#include<iostream>
#include<stack>
#include<string.h>
#define SIZE 8
using namespace std;

typedef pair<int,int> pairInt;

int main()
{
	stack<pairInt> st;
	
	st.push(make_pair(4,5));
	st.push(make_pair(14,51));
	st.push(make_pair(42,54));
	st.push(make_pair(34,52));

	while(!st.empty())
	{
		pairInt pi = st.top();
		cout<<endl<<pi.first<<" "<<pi.second;
		st.pop();
	}
	return 0;
}

