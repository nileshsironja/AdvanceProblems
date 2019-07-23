// BST.cpp : main project file.

#include "stdafx.h"
// C++ program to find k'th largest element in BST
#include<iostream>
#include<climits>
using namespace std;
 
// A BST node
struct Node
{
    int key;
    Node *left, *right;
};
 
// A function to find
int KSmallestUsingMorris(Node *root, int k)
{
    // Count to iterate over elements till we
    // get the kth smallest number
    int count = 0;
 
    int ksmall = INT_MIN; // store the Kth smallest
    Node *curr = root; // to store the current node
 
    while (curr != NULL)
    {
 
        if (curr->left == NULL)
        {
            count++;
             if (count==k)
                ksmall = curr->key;
             curr = curr->right;
        }
        else
        {
             Node *pre = curr->left;
            while (pre->right != NULL && pre->right != curr)
                pre = pre->right;
 
            // building links
            if (pre->right==NULL)
            {
                //link made to Inorder Successor
                pre->right = curr;
                curr = curr->left;
            }
             else
            {
                 pre->right = NULL;
 
                count++;
                 if (count==k)
                    ksmall = curr->key;
 
                curr = curr->right;
            }
        }
    }
    return ksmall; //return the found value
}
 
// A utility function to create a new BST node
Node *newNode(int item)
{
    Node *temp = new Node;
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}
 
/* A utility function to insert a new node with given key in BST */
Node* insert(Node* node, int key)
{
    /* If the tree is empty, return a new node */
    if (node == NULL) return newNode(key);
 
    /* Otherwise, recur down the tree */
    if (key < node->key)
        node->left  = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
 
    /* return the (unchanged) node pointer */
    return node;
}
 
void findkth(Node *root,int *ptr,int k,int *str)
{
	if(!root || k < 0)return;
	
	findkth(root->left,ptr,k,str);
	*str = *str + 1;
	//cout<<endl<<*str;
	if(k == *str){*ptr = root->key;}
	findkth(root->right,ptr,k,str);
}
int kthlarge(Node *root, int k)
{
	int retvalue;
	if(!root)return -1;
	else
	{
		retvalue = kthlarge(root->left,k);
		//if(!k)
		//	return root->key;

		retvalue = kthlarge(root->right,k-1);
	}
	return retvalue;

}
// Driver Program to test above functions
int main()
{
    /* Let us create following BST
              50
           /     \
          30      70
         /  \    /  \
       20   40  60   80 */
    Node *root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);
 
   // for (int k=1; k<=7; k++)
   //    cout << KSmallestUsingMorris(root, k) << " ";

	int ptr,str = 0;

	//findkth(root,&ptr,4,&str);
	cout<<kthlarge(root,5);
	cout<<ptr;
	system("pause");
    return 0;
}