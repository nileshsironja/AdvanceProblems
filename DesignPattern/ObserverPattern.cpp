#include<iostream>
#include<list>
using namespace std;

class Observer;
#ifdef DEBUG


class Observer
{
public:
	virtual void update(int, int) = 0;
};


class CurrentRunRate :public Observer
{
public:
	void update(int run, int wicket)
	{
		cout << endl << "Run :" << run << " Wicket :" << wicket;
	}
};

class AvgRunRate :public Observer
{
public:
	void update(int run, int over)
	{
		cout << endl << "avg run rate :" << run / over * 6;
	}

};

class Subject
{
	list<Observer*> ObserverList;
public:

	void addObserver(Observer *obj)
	{
		ObserverList.push_back(obj);
	}
	int getRun()
	{
		return 20;
	}
	int getWicket()
	{
		return 3;
	}
	void deleteObserver()
	{
		/*std::cout << "mylist contains:";
		for (std::list<int>::iterator it = mylist.begin(); it != mylist.end(); ++it)
			std::cout << ' ' << *it;*/
	}
	void notify()
	{
		//Observer *ob = ObserverList.front();
		//(ob)->update(getRun(),getWicket());
		list<Observer*>::iterator it = ObserverList.begin();
		for (; it != ObserverList.end(); it++)
		{
			//Observer *ob = it;
			(*it)->update(getRun(), getWicket());
		}

	}

};

int main()
{
	AvgRunRate avgrate;
	CurrentRunRate currate;
	Subject sub;
	sub.addObserver(&avgrate);
	sub.addObserver(&currate);
	sub.notify();

	return 0;
}


#endif // DEBUG


