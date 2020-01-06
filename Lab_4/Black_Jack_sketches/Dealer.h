#pragma once
#include "Deck.h"
#include "Gamer.h"

class Dealer: public Gamer
{
private:
	const int sum_ = 16;
	int sum_curr_;

public:
	//constructors & destructor
	Dealer();

	int GetDealerSum();
	int GetDealerCurrSum();
};