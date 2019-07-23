// Amazon.cpp.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
using namespace std;




struct Q
{
	int x, y;
	int state;
};
struct Q q[1001 * 1001];

bool isOk(int x, int y,int row,int col)
{
	if (x < 0 || y < 0 || x >= row || y >= col)
		return false;
	return true;

}

int removeObstacle(int numRows, int numColumns, int **lot)
{
	// WRITE YOUR CODE HERE
	int front = 0, rear = 0;

	q[0].x = 0;
	q[0].y = 0;

	int m=0, n = 0;
	while (front <= rear)
	{
		m = q[front].x;
		n = q[front].y;

		//top
		if (isOk(m - 1, n, numRows, numColumns) && lot[m-1][n]!=-1)
		{
			if (lot[m - 1][n] == 9)
			{
				return q[front].state + 1;
			}
			rear = rear + 1;
			q[rear].x = m - 1;
			q[rear].y = n;
			q[rear].state = q[front].state + 1;
			lot[m - 1][n] = -1;
		}
		//down
		if (isOk(m + 1, n, numRows, numColumns) && lot[m + 1][n] != -1)
		{
			if (lot[m + 1][n] == 9)
			{
				return q[front].state + 1;
			}
			rear = rear + 1;
			q[rear].x = m + 1;
			q[rear].y = n;
			q[rear].state = q[front].state + 1;
			lot[m + 1][n] = -1;
		}
		//left
		if (isOk(m , n-1, numRows, numColumns) && lot[m][n-1] != -1)
		{
			if (lot[m][n-1] == 9)
			{
				return q[front].state + 1;
			}
			rear = rear + 1;
			q[rear].x = m;
			q[rear].y = n-1;
			q[rear].state = q[front].state + 1;
			lot[m][n-1] = -1;
		}
		//right
		if (isOk(m, n + 1, numRows, numColumns) && lot[m][n + 1] != -1)
		{
			if (lot[m][n+1] == 9)
			{
				return q[front].state + 1;
			}
			rear = rear + 1;
			q[rear].x = m;
			q[rear].y = n + 1;
			q[rear].state = q[front].state + 1;
			lot[m][n + 1] = -1;
		} 

		front = front + 1;
	}

	return 0;
}
// FUNCTION SIGNATURE ENDS

int main()
{

	
	
	return 0;
}

