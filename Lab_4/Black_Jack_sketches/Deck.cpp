#include "Deck.h"
#include <algorithm>
#include <random>
#include <ctime>

Deck::Deck()
{
	isStandartDeck = true;
	SetDeck();
}

Deck::Deck(bool DeckStatus)
{
	this->isStandartDeck = isStandartDeck;

	if (isStandartDeck)
		SetDeck();
	else
		SetBigDeck();
}

Deck::~Deck() {}

void Deck::SetDeck()
{
	for (int key = 6; key < 15; key++) {
		cards.push_back(Card(key, L'\u2665'));	//UNICODE -> Suits
		cards.push_back(Card(key, L'\u2666'));
		cards.push_back(Card(key, L'\u2663'));
		cards.push_back(Card(key, L'\u2660'));
	}
}

void Deck::SetBigDeck()
{
	for (int key = 2; key < 15; key++) {
		cards.push_back(Card(key, L'\u2665'));	//UNICODE -> Suits
		cards.push_back(Card(key, L'\u2666'));
		cards.push_back(Card(key, L'\u2663'));
		cards.push_back(Card(key, L'\u2660'));
	}
}

void Deck::Shufle()
{
	std::srand(std::time(nullptr));
	std::random_shuffle(cards.begin(), cards.end());
}

Card& Deck::GetCard()
{
	for (int i = 0; i < cards.size(); i++)
		if (cards[i].position_ == Card::DECK_HEAP)
		{
			cards[i].ChangePos(Card::IN_HAND);
				return cards[i];
		}
}