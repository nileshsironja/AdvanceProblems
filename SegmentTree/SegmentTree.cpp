// SegmentTree.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include<iostream>
using namespace std;

#define SIZE 10
int arr[SIZE] = {6,4,2,4,7,8,6,3,2,4};
int tree[2*SIZE+1];
void buildSegment(int node, int start, int end)
{
	if (start == end)
	{
		 tree[node] = arr[start];
		 return;
	}

	int mid = (start + end) / 2;

    buildSegment(node * 2+1, start, mid);
	buildSegment(node * 2 + 2, mid+1, end);

	tree[node] = tree[node * 2+1] < tree[node * 2 + 2] ? tree[node * 2 + 1] : tree[node * 2 + 2];

}

//check in which segment value fall
void update(int node, int start, int end, int id, int val)
{
	if (start == end)
	{
		arr[id] = val;
		tree[node] = val;
		
		//return;
	}
	else
	{
		int mid = (start + end) / 2;

		if (start <= id && id <= mid)
			update(node * 2+1, start, mid, id, val);
		else
			update(node * 2 + 2, mid + 1, end, id, val);

		tree[node] = tree[node * 2+1] + tree[node * 2 + 2];
	}
}

//for update 3 conditions
//value fall in a specified range
//value fall outside of a range
//value partially fall in a given range

int query(int node,int start,int end,int r1,int r2)
{
	//outside
	if (r2<start || r1>end)
	{
		return 0;
	}
	//inside the range
	if (r1 <= start && r2 >= end)
	{
		return tree[node];
	}

	int mid = (start + end) / 2;
	int n1 = query(node * 2+1, start, mid, r1, r2);
	int n2 = query(node * 2+2, mid+1, end, r1, r2);
	return n1 + n2;
}

int min_query(int node, int start, int end, int r1, int r2)//for RMQ
{
	//outside
	if (r2<start || r1>end)
	{
		return 0;
	}
	//inside the range
	if (r1 <= start && r2 >= end)
	{
		return tree[node];
	}

	int mid = (start + end) / 2;
	int n1 = min_query(node * 2 + 1, start, mid, r1, r2);
	int n2 = min_query(node * 2 + 2, mid + 1, end, r1, r2);
	return n1 > n2 ? n1 : n2;
}

int main()
{

	buildSegment(0,0,SIZE-1);
 
	//update(0, 0, SIZE-1, 3, 58);

	cout << "sum 3 - 6  :" << min_query(0,0,SIZE-1,0,1);
    return 0;
}

