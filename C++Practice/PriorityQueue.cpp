// C++Practice.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
//#ifdef ONCE 1
#include<iostream>
#include<algorithm>
#include<queue>
#include<map>
#include<stack>
using namespace std;

#ifdef DEBUG


#include <queue>
#include <iostream>
using namespace std;

class Person {
public:
	Person(int age,int sal) : age(age),sal(sal) {}
	int age;
	int sal;
};

bool operator<(const Person& a, const Person& b) {
	return a.age < b.age;
}

int main() {
	priority_queue<Person> Q;
	for (int i : {1, 10, 2, 9, 3, 8, 4, 7, 5, 6})
		Q.push(Person(i%3,i));
	while (!Q.empty()) {
		Person p = Q.top();
		Q.pop();
		cout << p.age << " ";
	}
	return 0;
}


#endif // DEBUG








//int main()
//{
//	priority_queue<int,char> Q;
//
//	Q.push(make_pair(5,'t'));
//	Q.push(make_pair(22,'r'));
//	Q.push(make_pair(23,'m'));
//	 
//	priority_queue<int,char> q = Q;
//	while (!q.empty())
//	{
//		cout << endl << q.top();
//		q.pop();
//	}
//	
//	stack<int> st;
//
//	st.push(8);
//	st.push(10);
//	st.push(12);
//
//	stack<int> stc = st;
//	while (!stc.empty())
//	{
//		cout<<endl<<stc.top();
//		stc.pop();
//	}
//
//
//	map<int, int> mp;
//
//	mp.insert(pair<int, int>(1, 40));
//	mp.insert(pair<int, int>(1, 50));
//	mp.insert(pair<int, int>(3, 45));
//
//
//	map<int, int>::iterator it = mp.begin();
//
//	while (it != mp.end())
//	{
//		cout << it->first << " " << it->second << endl;
//		it++;
//	}
//
//
//
//
//
//	return 0;
//}
//#endif