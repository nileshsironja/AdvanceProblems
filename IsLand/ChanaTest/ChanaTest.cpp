// ChanaTest.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<math.h>
using namespace std;

// A Backtracking program  in C++ to solve Sudoku problem
#include <stdio.h>
 
// UNASSIGNED is used for empty cells in sudoku grid
#define UNASSIGNED 0
 
// N is used for size of Sudoku grid. Size will be NxN
#define N 400

int Num;
// This function finds an entry in grid that is still unassigned
bool FindUnassignedLocation(int grid[N][N], int &row, int &col);
 
// Checks whether it will be legal to assign num to the given row,col
bool isSafe(int grid[N][N], int row, int col, int num);
 
/* Takes a partially filled-in grid and attempts to assign values to
  all unassigned locations in such a way to meet the requirements
  for Sudoku solution (non-duplication across rows, columns, and boxes) */
bool SolveSudoku(int grid[N][N])
{
    int row, col;
 
    // If there is no unassigned location, we are done
    if (!FindUnassignedLocation(grid, row, col))
       return true; // success!
 
    // consider digits 1 to 9
    for (int num = 1; num <= Num; num++)
    {
        // if looks promising
        if (isSafe(grid, row, col, num))
        {
            // make tentative assignment
            grid[row][col] = num;
 
            // return, if success, yay!
            if (SolveSudoku(grid))
                return true;
 
            // failure, unmake & try again
            grid[row][col] = UNASSIGNED;
        }
    }
    return false; // this triggers backtracking
}
 
/* Searches the grid to find an entry that is still unassigned. If
   found, the reference parameters row, col will be set the location
   that is unassigned, and true is returned. If no unassigned entries
   remain, false is returned. */
bool FindUnassignedLocation(int grid[N][N], int &row, int &col)
{
    for (row = 0; row < Num; row++)
        for (col = 0; col < Num; col++)
            if (grid[row][col] == UNASSIGNED)
                return true;
    return false;
}
 
/* Returns a boolean which indicates whether any assigned entry
   in the specified row matches the given number. */
bool UsedInRow(int grid[N][N], int row, int num)
{
    for (int col = 0; col < Num; col++)
        if (grid[row][col] == num)
            return true;
    return false;
}
 
/* Returns a boolean which indicates whether any assigned entry
   in the specified column matches the given number. */
bool UsedInCol(int grid[N][N], int col, int num)
{
    for (int row = 0; row < Num; row++)
        if (grid[row][col] == num)
            return true;
    return false;
}
 
/* Returns a boolean which indicates whether any assigned entry
   within the specified 3x3 box matches the given number. */
bool UsedInBox(int grid[N][N], int boxStartRow, int boxStartCol, int num)
{
	for (int row = 0; row < sqrt((double)Num); row++)
        for (int col = 0; col < sqrt((double)Num); col++)
            if (grid[row+boxStartRow][col+boxStartCol] == num)
                return true;
    return false;
}
 
/* Returns a boolean which indicates whether it will be legal to assign
   num to the given row,col location. */
bool isSafe(int grid[N][N], int row, int col, int num)
{
    /* Check if 'num' is not already placed in current row,
       current column and current 3x3 box */
    return !UsedInRow(grid, row, num) &&
           !UsedInCol(grid, col, num) &&
           !UsedInBox(grid, row - row%(int)sqrt(double(Num)) , col - col%(int)sqrt(double(Num)), num);
}
 
/* A utility function to print grid  */
bool checkprintGrid(int grid[N][N])
{
	int arr[N];
	for(int i=0;i<N;i++)
		arr[i] = 0;
	int half = Num/2;
    for (int row = 0; row < (int)sqrt(double(Num)); row++)
    {
       for (int col = 0; col < (int)sqrt(double(Num)); col++)
	   {
             //printf("%d ", grid[row][col]);
             //printf("\n");
		    int no1 = grid[row][col];
			 
			for(int k=half+col;k<Num;k++)
			{
				if(grid[k][half+row] == no1)
					return false;
			}

			int no2 = grid[Num - row][Num - col];
			for(int k=half+col-1;k<Num;k++)
			{
				if(grid[k][half-row] == no2)
					return false;
			}
			 
	   }
    }





	for (int row = 0; row < (int)sqrt(double(Num)); row++)
    {
       for (int col = 0; col < (int)sqrt(double(Num)); col++)
	   {
             //printf("%d ", grid[row][col]);
             //printf("\n");
		    int no1 = grid[row][col];
			 
			for(int k=half+col;k<Num;k++)
			{
				if(grid[half+row][k] == no1)
					return false;
			}

			int no2 = grid[Num - row][Num - col];
			for(int k=half+col-1;k<Num;k++)
			{
				if(grid[half-row][k] == no2)
					return false;
			}
			 
	   }
    }










	return true;
}
 
/* Driver Program to test above functions */
int main()
{
    // 0 means unassigned cells
    /*int grid[N][N] = {{3, 0, 6, 5, 0, 8, 4, 0, 0},
                      {5, 2, 0, 0, 0, 0, 0, 0, 0},
                      {0, 8, 7, 0, 0, 0, 0, 3, 1},
                      {0, 0, 3, 0, 1, 0, 0, 8, 0},
                      {9, 0, 0, 8, 6, 3, 0, 0, 5},
                      {0, 5, 0, 0, 9, 0, 6, 0, 0},
                      {1, 3, 0, 0, 0, 0, 2, 5, 0},
                      {0, 0, 0, 0, 0, 0, 0, 7, 4},
                      {0, 0, 5, 2, 0, 6, 3, 0, 0}};*/

	int grid[N][N];
	cin>>Num;
	cin>>Num;
	for(int i=0;i<Num;i++)
	{
		for(int j=0;j<Num;j++)
		{
			cin>>grid[i][j];
		}
	}

    if (SolveSudoku(grid) == true)
          //cout<<"1"<<endl;
		  if(checkprintGrid(grid))
			  cout<<"1"<<endl;
		  else 
			  cout<<"0"<<endl;
    else
          cout<<"0"<<endl;
 
    return 0;
}





/*

4
4
1 0 0 0
0 0 2 0
0 3 0 0
0 0 0 4



*/






//
//char str[3001];
//char strr[3000001];
//
//int main()
//{
//	int a,b;
//	int arr[125]={0},arrr[125]={0};
//
//	cin>>a>>b;
//	char ch;
//	for(int i=0;i<a;i++)
//	{
//		 cin>>ch;
//		 arr[ch]++;
//	}
//	cin>>strr;
//
//	for(int i=0;i<a-1;i++)
//	{
//		 arrr[strr[i]]++;
//	}
//
//	int ans = 0,k=0;
//	for(int i=a-1; i<=b;i++,k++)
//	{
//		arrr[strr[i]]++;
//		//COMPARE
//		bool chk = false;
//		for(int j=65;j<=123;j++)
//		{
//		   if(arr[j] != arrr[j])
//		   {
//		      chk = true;
//			  break;
//		   }
//		}
//		if(false == chk)
//			ans++;
//	    arrr[strr[k]]--;
//	}
//
//	cout<<ans;
//
//	//system("pause");
//
//}




/*

3
10

abc
abcdefghabc


*/








	

























// 
////int arr[100001],Q[100001][2];
//
//
//long long int check(int A, int B)
//{
//	long long int num = 25, fact = 1;
//	int k = 2;
//	for(int i = 26; i <= 24+B; i++,k++)
//	{
//	   num = (num * i) % 10000000; 
//	   fact = (fact * k) % 10000000; 
//	}
//	//for(int i = 24; i <= 24+B; i++)
//	//{
//	   num = (num / fact);
//	//}
//	return num;
//	//num = (num /
//}
//
//int main()
//{
//
//	int A,B;
//	cin>>A>>B;
//
//	if(A > 24 && B > 24)
//	{
//		if((A-B) == 2 || (B-A) == 2)
//		{
//			if(A>B)
//			cout<<check(A,B);
//			else
//			cout<<check(B,A);
//		}
//		else
//		{
//			cout<<"0";
//		}
//	}
//
//	else if((A == 25  && B < 24))
//	{
//		//if(A>B)
//		cout<<check(A,B);
//		//else
//		//check(B,A);
//	}
//
//	else if(B == 25 && A < 24)
//	{
//	   cout<<check(B,A);
//	}
//	else
//		cout<<"0";
//
//
//
//
//
//
//
//
//
//
//
//
//}
//


/*int T,N,Q;
	cin>>N;
	for(int i=1;i<=N;i++)
		cin>>arr[i];
	int A,B,C,D;
	cin>>Q;
	int chk = 0;
	while(Q--)
	{
		if(chk == 0)
		cin>>A>>B;
		if(Q)
		cin>>C>>D;
		else
			C = 0,D = 0;
		if(A == C && B == D)
		{
			chk = 1;
			Q--;
			continue;
		}
		else
			chk = 0;

		int l = N - A + 1;
		for(int k = A; k <= B; k++)
		{
			int temp = arr[k];
			arr[k] = arr[l];
			arr[l] = temp;
			l--; 
		}
		 
		
	}
	for(int i=1;i<=N;i++)
			cout<<arr[i]<<" ";
	 cout<<endl;*/
//}
	//system("pause");

//
//int main()
//{
//	//cout<<"hello";
//
//	
//	int T;
//	cin>>T;
//
//	char stack[100];
//	
//	while(T--)
//	{
//		cin>>str;
//		int top = 0;
//		int strlength = strlen(str);
//		//logic
//	    bool balance = true;
//		for(int i=0; i< strlength && str[i]; i++)
//		{
//			if(str[i] == '{' || str[i] == '(' || str[i] == '[')
//				stack[top++] = str[i];
//			else if(str[i] == '}' && top >=0 ) 
//			{
//				if(stack[top-1] == '{')
//				{
//					top--;
//				}
//				else
//				{
//					balance = false;
//					break;
//				}
//			}
//			else if(str[i] == ')'  && top >=0 )  
//			{
//				if(stack[top-1] == '(')
//				{
//					top--;
//				}
//				else
//				{
//					balance = false;
//					break;
//				}
//			}
//			else if(str[i] == ']'  && top >=0 )
//			{
//				if(stack[top-1] == '[')
//				{
//					top--;
//				}
//				else
//				{
//					balance = false;
//					break;
//				}
//			
//			} 
//			else
//			{
//			 		balance = false;
//					break;
//			}
//		}
//		if(balance == false || top > 0 )
//		{
//			cout<<"\nNot Balance";
//		}
//		else
//		{
//			cout<<"\nBalance";
//		} 
//	}
//
//
//
//	system("pause");
//	return 0;
//}
//
