
#include "stdafx.h"
#include<iostream>
#include<vector>
#include<string>
using namespace std;
 
vector<string> missingWords(string str, string ttr) {

	vector<string> str;

	string strs;
	int ptr = 0, loc = 0, lc;
	string::iterator it;

	char strc[100001] = { '\0' };
	for (it = str.begin(), loc = 0; it != str.end(); it++, loc++)
	{
		strc[loc] = *it;
	}
	strc[loc] = '\0';

	ptr = 0, loc = 0, lc;
	char strt[100001] = { '\0' };
	for (it = ttr.begin(), loc = 0; it != ttr.end(); it++, loc++)
	{
		strt[loc] = *it;
	}
	strt[loc] = '\0';




}

string longestEvenWord(string str) {
	//str1.copy(ch,13,0);
	string strs;
	int ptr = 0, loc = 0, lc;
	string::iterator it;

	char strc[100001] = {'\0'};
	for (it = str.begin(),loc=0; it != str.end(); it++,loc++)
	{
		strc[loc] = *it;
	}
	strc[loc] = '\0';

	loc = 0, lc = 0;
	int len = 0;
	for (int i = 0; strc[i]; i++,loc++)
	{
		if (strc[i] == ' ')
		{
			if (ptr % 2 == 0 && (loc - lc) > len)
			{
				strs.clear();
				while (ptr--)
				{
					strs.push_back(strc[lc]); 
					lc++;
				}
				len = loc - lc;
			}

			ptr = 0;
			lc = loc + 1;
		}
		else
		{
			ptr++;
		}

	}
	if (ptr % 2 == 0 && (loc - lc) > len)
	{
		strs.clear();
		while (ptr--)
		{
			strs.push_back(strc[lc]);
			lc++;
		}
		len = loc - lc;
	}

	 
	return strs;
}


int main()
{
	//ofstream fout(getenv("OUTPUT_PATH"));

	string sentence = "You can do it the way you like";
	//getline(cin, sentence);

	string result = longestEvenWord(sentence);

	cout << result << "\n";

	 

	return 0;
}