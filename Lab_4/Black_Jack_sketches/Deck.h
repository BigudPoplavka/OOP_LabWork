#pragma once
#include "Card.h"
#include <vector>

class Deck
{
private:
	static const int max_cards_ = 52;

public:
	bool isStandartDeck;
	std::vector<Card> cards;

	Deck();
	Deck(bool DeckStatus);
	~Deck();

	void SetDeck();
	void SetBigDeck();
	void Shufle();
	Card& GetCard();
};