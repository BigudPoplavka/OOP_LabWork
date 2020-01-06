#pragma once
#include "Deck.h"
#include <vector>

class DeckPlace
{
private:
	

public:
	std::vector<Deck> my_decks_;

	DeckPlace();
	~DeckPlace();

	void setDeck();
	void ShuffleCards();
	Card& getCard();

};