#pragma once
#include "Hand.h"

class Gamer
{
private:

public:
	int score_;
	int money_balance_ = 50000;

	Hand* hand;

	Gamer();
	Gamer(int money);
	virtual ~Gamer() { delete hand; }

	virtual void printBalance();
	virtual int getBalance();
};