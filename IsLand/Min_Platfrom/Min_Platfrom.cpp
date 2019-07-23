// Min_Platfrom.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#define N 5000
using namespace std;
//Segment Tree
struct Tree
{
	int arval;
	int dept;
	struct Tree *left,*right;
};
typedef struct Tree T;

int arr[N];

T *form_tree(T *root,int arr,int dep)
{
	if(!root)
	{
		root = (T*)malloc(sizeof(T));
		root->arval = arr;
		root->dept = dep;
		root->left = root->right = NULL;
		return root;
	}
	else
	{
	if(arr < root->arval) 
	{
		root->left = form_tree(root->left,arr,dep);
		if(root->arval < root->left->dept && root->dept > root->left->dept)
		{
		 return root;
		}
		else
		{
		    free(root->left);
			root->left = NULL;
			//return NULL;
		}
	}
	else if(arr > root->arval)
	{
	    root->right = form_tree(root->right,arr,dep);
		if(root->dept > root->right->arval && (root->dept > root->right->arval))
		{
		 return root;
		}
		else
		{
			free(root->right);
			root->right = NULL;
		    //return NULL;
		} 
	}
	}
}

int cnt_treenode(T *root,int cnt)
{
	if(root)
	{
		cnt_treenode(root->left,cnt);
		cnt++;
		cnt_treenode(root->right,cnt);
	}
	return cnt;
}

int main()
{
	T *root = NULL;
	int t,n;
	cin>>t;
	cin>>n;

	while(t--)
	{
		for(int i=0;i<n*2;i++)
			cin>>arr[i];
		
		for(int i=0;i<n;i+=2)
		root = form_tree(root,arr[i],arr[i+1]);
		cout<<"No of nodes :"<<cnt_treenode(root,0);
	}

	system("pause");
	return 0;
}

