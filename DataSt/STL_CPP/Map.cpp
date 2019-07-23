// STL_CPP.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<algorithm>
#include<map>
using namespace std;

int main()
{
 
  std::map<char,int> mymap;
  std::map<char,int>::iterator itlow,itup;

  mymap['a']=20;
  mymap['f']=40;
  mymap['c']=60;
  mymap['d']=80;
  mymap['i']=100;

  //itlow=mymap.lower_bound ('b');  // itlow points to b
  itup=mymap.upper_bound ('a');   // itup points to e (not d!)
  //cout<<"uper bo"<<itup->first<<" "<<itup->second<<endl;

  char ch = itup->first-1;
  //cout<<endl<<"tst :"<<ch<<endl;

  mymap.erase('a','d');        // erases [itlow,itup)

  // print content:
  /*for (std::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
    std::cout << it->first << " => " << it->second << '\n';
   */

	system("pause");
	return 0;
}

