#include "DeckPlace.h"

DeckPlace::DeckPlace()
{

	ShuffleCards();
}

DeckPlace::~DeckPlace() {}

void DeckPlace::setDeck()
{

}

void DeckPlace::ShuffleCards()
{

}

Card& DeckPlace::getCard()
{
	return my_decks_[0].GetCard();
}