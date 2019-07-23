#include<iostream>
using namespace std;
#ifdef DEBUG

class BirdInterface
{
public:
	virtual void fly() = 0;
	virtual void sound() = 0;
};

class Crock:public BirdInterface
{
public:
	void fly()
	{
		cout << endl << "I'm a bird; able to fly";
	}
	void sound()
	{
		cout << endl << "sound kav kav";
	} 
};

//client requirement to make toybird to make sound
class ToyBird
{
public:
	void fly()
	{
		cout << endl << "I don't fly";
	}
};

class ToyBirdAdapter :public ToyBird
{
	BirdInterface *bird;
public:
	ToyBirdAdapter(BirdInterface *bi)
	{
		bird = bi;
	}
	void makesound()
	{
		bird->sound();
	}
};

int main()
{
	//BirdInterface *birdInter = new BirdInterface();
	Crock *cr = new Crock();
	cr->fly();
	cr->sound();

	ToyBirdAdapter *tba = new ToyBirdAdapter(cr);
	tba->fly();
	tba->makesound();

	return 0;
}


#endif // DEBUG





