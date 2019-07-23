#include "stdafx.h"
//#include<iostream>
//using namespace std;
//// Complete the checkSortation function below.
//void checkSortation(int arr_count, int* arr) {
//
//	int start = 0, end = 0, yes = 0, no = 0, i = 0, dontcome = 0;
//	bool check = true;
//	for (i = 1; i<arr_count; i++)
//	{
//		if (arr[i] >= arr[i - 1])
//		{
//			if (check == false)
//			{
//				if(dontcome == 0)
//					end = i;
//				dontcome = 1;
//				
//				//no = 1;
//				//break;
//			}
//			continue;
//		}
//		else if (true == check && (arr[i] < arr[i - 1]))
//		{
//			if(dontcome == 1)
//			{
//			   no = 1;
//			  break;
//			}
//			start = i;
//			check = false;
//		}
//	}
//	if (i == arr_count && end==0)
//		end = i;
//	if (no)
//	{
//		printf("no");
//	}
//	else
//	{
//		printf("yes\n%d %d", start, end);
//	}
//
//}
//
///*
//
//case 1 : IF segment is at start of array
//case 2 : IF segment is at last of the array
//case 3 : IF segment is at middle of the array
//
//*/
//
//int main()
//{
//	int arr[] = { 3,1,2,4 };
//	checkSortation(4, arr);
//
//}
