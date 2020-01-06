#pragma once
#include "Deck.h"
#include "Card.h"

class Hand
{
private:

public:
	int card_count_;
	int card_score_;
	static const int card_max_count = 12;

	Card* my_cards[card_max_count];

	Hand();
	~Hand();

	void TakeCard(Card &card);
	void PrintHand();
	void PrintHandDealer();
	void PrintScore();
	void PrintScoreDealer();
	void Refresh();
};
