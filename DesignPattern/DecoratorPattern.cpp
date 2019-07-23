#include<iostream>
#include<string>
using namespace std;

class Coffee
{
public:
	virtual double getvalue() =  0 ;
	virtual string ingredients() =  0 ;
};

class SimpleCoffee :public Coffee
{
public:
	double getvalue()
	{
		return 1.0;
	}
	string ingredients()
	{
		return " Simple Coffee ";
	}

};


class CoffeeDecorator :public Coffee
{ 
public:
	Coffee * obj;
	CoffeeDecorator(Coffee *ob)
	{
		obj = ob;
	}
	double getvalue()
	{
		return obj->getvalue();
	}
	string ingredients()
	{
		return obj->ingredients();
	}

};


class CoffeeWithMilk :public CoffeeDecorator
{
public:
	CoffeeWithMilk(Coffee *co):CoffeeDecorator(co)
	{

	}
	double getvalue()
	{
		return 0.5 + obj->getvalue();
	}
	string ingredients()
	{
		return " milk ";
	}
  
};

class CoffeeWithSugar :public CoffeeDecorator
{
public:
	CoffeeWithSugar(Coffee *co) :CoffeeDecorator(co)
	{

	}
	double getvalue()
	{
		return 0.7 + obj->getvalue();
	}
	string ingredients()
	{
		return " sugar ";
	}

};

int main()
{
	
	Coffee *cf = new SimpleCoffee();
	cout<<cf->ingredients()<<" "<<cf->getvalue();
	Coffee *cm = new CoffeeWithMilk(cf);
	cout <<endl<< cm->ingredients() << " " << cm->getvalue();
	Coffee *cs = new CoffeeWithSugar(cf);
	cout << endl << cs->ingredients() << " " << cs->getvalue();


	return 0;
}



