//// flipK.cpp : Defines the entry point for the console application.
////
//
#include "stdafx.h"
//#include <iostream>
//#include <fstream>
//#include <string>
//using namespace std;
//
//
//#define COL 4
//#define COLNAME 15 
//#define DATASIZE 10000
//
//int unique[DATASIZE];
//int mandate[DATASIZE];
//int id[DATASIZE];
//int email[DATASIZE];
//int uni = 0, man = 0;
//enum types
//{
//	STRING,
//	EMAIL,
//	PHONE
//};
//
//typedef enum types type_;
//
//struct config
//{
//	char col[COLNAME];
//	type_ type;
//	bool ismandate;
//	bool isunique; 
//
//};
//
//typedef struct config Config;
//
//Config conf[COL];
//
//int readconf = 0;
//void readConfig(char gfg[])
//{
//
//
//	// Declaration of delimiter
//	const char s[2] = ",";
//	char* tok;
//
//	// Use of strtok
//	// get first token
//	tok = strtok(gfg, s);
//
//	// Checks for delimeter
//	int col = 0;
//	while (tok != 0) {
//		//printf(" %s\n", tok);
//
//		// Use of strtok
//		// go through other tokens
//		
//		if(col == 0)
//		strcpy(conf[readconf].col, tok);
//
//		else if (col == 1)
//		{
//			if (!strcmp("string", tok))
//				conf[readconf].type = STRING;
//			if (!strcmp("email", tok))
//				conf[readconf].type = EMAIL;
//			if (!strcmp("phone", tok))
//				conf[readconf].type = PHONE;
//			//strcpy(conf[col].col, tok);
//		}
//		else if (col == 2)
//		{
//			if (!strcmp("true", tok))
//				conf[readconf].ismandate = true;
//			else
//				conf[readconf].ismandate = false;
//		}
//		else if (col == 3)
//		{
//			if (!strcmp("true", tok))
//				conf[readconf].isunique = true;
//			else
//				conf[readconf].isunique = false;
//		} 
//		col++;
//		tok = strtok(0, s);
//	} 
//		readconf++;
//}
//
//
//void EvalConfig(char gfg[])
//{
//
//
//	// Declaration of delimiter
//	const char s[2] = ",";
//	char* tok;
//
//	// Use of strtok
//	// get first token
//	tok = strtok(gfg, s);
//
//	// Checks for delimeter
//	int col = 0; int storeid = -1,i=0;
//	while (tok != 0) {
//		//printf(" %s\n", tok);
//
//		// Use of strtok
//		// go through other tokens
//		
//		
//		//for (int i = 0; i < readconf; i++)
//		{
//		 
//			if (conf[i].type == EMAIL)
//			{
//				int count = 0;
//				if (tok[0] == '@')
//					email[storeid]++;
//				else
//				{
//					for (int i = 1; i < strlen(tok); i++)
//					{
//						if (tok[i] == '@')
//						{
//							if (count == 0)
//								count = 1;
//
//							else if (count == 1 || tok[i + 1] == '\0')
//							{
//								email[storeid]++;
//
//								break;
//							}
//						}
//					}
//				}
//
//				 
//			}
//
//			if (conf[i].isunique)
//			{
//				//if(storeid)
//                
//				//else
//				id[atoi(tok)]++;
//				storeid = atoi(tok);
//			}
//			if (conf[i].ismandate)
//			{
//				if(tok[0]=='/0')
//				mandate[storeid]++;
//			}
//			if (conf[i].isunique)
//			{
//				unique[atoi(tok)]++;
//			}
//			tok = strtok(0, s);
//			i++;
//		}
//		
//	}
//}
//
//int main()
//{
//
//	string line;
//	string input;
//	cout << "input file path: config ->";
//	//cin >> input;
//	ifstream myfile("D:\\config.txt");
//	int i = 0;
//	if (myfile.is_open())
//	{
//		while (getline(myfile, line))
//		{
//			char *cstr = new char[line.length() + 1];
//			strcpy(cstr, line.c_str());
//
//			//cout << line << '\n';
//			if (i == 0)
//			{
//				//first line
//				i++;
//				continue;
//			}
//			else
//			{
//				readConfig(cstr);
//			}
//			 
//		}
//		myfile.close();
//	}
//
//
//	cout << "input file path: data ->";
//	//cin >> input;
//	ifstream myfile_("D:\\input.txt");
//    i = 0;
//	if (myfile_.is_open())
//	{
//		while (getline(myfile_, line))
//		{
//			char *cstr = new char[line.length() + 1];
//			strcpy(cstr, line.c_str());
//
//			//cout << line << '\n';
//			if (i == 0)
//			{
//				//first line
//				i++;
//				continue;
//			}
//			else
//			{
//				EvalConfig(cstr);
//			}
//
//		}
//		myfile.close();
//	}
//
//	cout << endl << "Email error at id :";
//	for (int i = 0; i < DATASIZE; i++)
//	{
//		if (email[i])
//		{
//			cout <<" "<< i;
//		} 
//	}
//	cout << endl << "Id is not unique :";
//	for (int i = 0; i < DATASIZE; i++)
//	{
//		if (unique[i]>=2)
//		{
//			cout <<" "<< i;
//		}
//	}
//	
//	cout << endl << "Id is mandate :";
//	for (int i = 0; i < DATASIZE; i++)
//	{
//		if (mandate[i])
//		{
//			cout <<" "<< i;
//		}
//	}
//
//
//	return(0);
//}
//
// 