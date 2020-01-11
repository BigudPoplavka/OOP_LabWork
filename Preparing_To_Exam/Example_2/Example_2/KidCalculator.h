#pragma once
#include "ICalculator.h"

using namespace std;

class KidCalculator: public ICalculator
{
private:
	const int max_ = 10;

public:
	KidCalculator();
	~KidCalculator();

	int ICalculator::add(int a, int b) override;
};

KidCalculator::KidCalculator() { cout << "# Created Kid Calculator!" << endl; }
KidCalculator::~KidCalculator() {}

int KidCalculator::add(int a, int b)
{
	try
	{
		if (a + b < 0 || a + b > 10) throw "You not ready for this!";
		else return a + b;
	}
	catch(const char* exc_msg)
	{
		cout << exc_msg << endl;
		return max_;
		cout << "It max value for you now..." << endl;
	}

	/*	variant 2
	if(res > 10 || res < 0) throw 1

	catch(int e)
	{
		if(e == 1) ...
	}
	*/
}