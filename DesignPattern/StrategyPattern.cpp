// DesignPattern.cpp : Defines the entry point for the console application.
//



#include "stdafx.h"
#include<iostream>
using namespace std;
class kickFighter;
class rollFighter;
class kickManFront;
class kickManBack;
class rollMan;

#ifdef DEBUG
 

class kickFighter
{
public:
	virtual void kick() = 0;
	
};

class rollFighter
{
public:
	virtual void roll() = 0;
	
};


class kickManFront:public kickFighter
{
public:
	void kick()
	{
		cout << endl << "Awesome front kick";
	}

};
class kickManBack:public kickFighter
{
public:
	void kick()
	{
		cout << endl << "Awesome back kick";
	}

};

class rollMan:public rollFighter
{
public:
	void roll()
	{
		cout << endl << "Awesome front roll";
	} 
};



class Fighter
{
	//kick,jump,roll,crunch; kick and roll are optional
private:

public:
	kickFighter * kickF;
	rollFighter *rollF;
	Fighter() {}
	Fighter(kickFighter *a, rollFighter *b)
	{
		kickF = a;
		rollF = b;
	}
	void jump()
	{
		cout << endl << "Awesome jump";
	}
	void crunch()
	{
		cout << endl << "Awesome crunch";
	}
	void kicks()
	{
		kickF->kick();
	}
	void rolls()
	{
		rollF->roll();
	}
	void setkick(kickFighter *kF)
	{
		kickF = kF;
	}
};


class Nilesh :public Fighter
{
public:
	Nilesh() {};
	Nilesh(kickFighter &a, rollFighter &b)
	{
		kickF = &a;
		rollF = &b;
	}
	void display()
	{
		cout << endl << "nilesh";
	}
	
};

int main()
{
	kickManFront nilesh;
	rollMan sironja;

	Fighter *nilu = new Nilesh(nilesh, sironja);
	nilu->kicks();
	nilu->rolls();
	
	kickManBack vicky; 

	Fighter *nilus = new Nilesh(vicky, sironja);
	nilus->kicks();
	nilus->rolls();

	return 0;
}

#endif // DEBUG


