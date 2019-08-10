/*program for topological sort*/

#include<iostream>
#include<list>
#include<stack>
#include<algorithm>
using namespace std;

#define N 10
stack<int> st;

list <int> *adjList;
int visited[N] = {0};

void doDfs(int index)
{

	if(visited[index])
		return;
	
	visited[index] = 1;
	list<int>::iterator it = adjList[index].begin();
	for( ; it != adjList[index].end(); it++)
	{
	    doDfs(*it); 
	}
	
	st.push(index);
	return;
}

void doTopoSort(list<int>*adjList)
{
	for(int i=0;i<N;i++)
	{
		if(adjList[i].size() != 0 && !visited[i])
		{
			doDfs(i);
			visited[i] = 1;
		}		
	}
}


int main()
{
	//1->3 ; 3->5; 3->9; 9->5;
	
	adjList = new list<int>[10];

	adjList[1].push_back(3);
	adjList[3].push_back(5);
	adjList[3].push_back(9);
	adjList[9].push_back(5);

	
	/*
	for(int i=0;i<N;i++)
	{
		if(adjList[i].size() != 0)
		{
			cout<<endl<<"Index :"<<endl;
			list<int>::iterator it = adjList[i].begin();
			for( ; it != adjList[i].end(); it++)
			{
				cout<<*it<< "  ";
			}
		}
	}*/

	doTopoSort(adjList);
	cout<<endl<<"Result";
	while(!st.empty())
	{
		cout<<st.top();
		st.pop();
	}
	return 0;
}
