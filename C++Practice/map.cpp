#include<iostream>
#include<map>
#include<algorithm>
using namespace std;

int main()
{
	#ifndef MAP
	multimap<int,int> intMap;
	#else
	map<int,int> intMap;
	#endif
	
	multimap<int,int> intMapCpy(intMap.begin(), intMap.end());
	
	//Insert
	intMap.insert(make_pair(1,11));
	intMap.insert(make_pair(2,12));
	intMap.insert(make_pair(3,13));
	intMap.insert(make_pair(4,14));
	intMap.insert(make_pair(5,15));
	intMap.insert(make_pair(5,25));	

	//Display
	cout<<endl<<"Display"<<endl;
	map<int,int>::iterator it = intMap.begin();
	
	for( ; it != intMap.end(); it++)
	{
	  cout<<it->first<<" map to "<<it->second<<endl;
	}
	
	//Find
	cout<<endl<<"Find"<<endl;
	int key = 5;
	it = intMap.find(key);
	int count = intMap.count(key);
	cout<<endl<<"Count :"<<count<<endl;
	while(count--)
	{
	  cout<<it->first<<" map to "<<it->second<<endl;  
	}
	
	//erase
	cout<<endl<<"Erase"<<endl;
	count = intMap.erase(key);
	cout<<endl<<"Erased "<<count<<endl;
	it = intMap.begin();
	
	for( ; it != intMap.end(); it++)
	{
	  cout<<it->first<<" map to "<<it->second<<endl;
	}
	
	//Size
	count = intMap.size();
	cout<<endl<<"Size is : "<< count;


	it = intMapCpy.begin();
	
	for( ; it != intMapCpy.end(); it++)
	{
	  cout<<it->first<<" map to "<<it->second<<endl;
	}

	
	return 0;
}

