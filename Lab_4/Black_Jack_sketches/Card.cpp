#include "Card.h"
#include <iostream>

Card::Card(int value, wchar_t suit)
{
	value_ = value;
	suit_ = suit;
	position_ = Position::DECK_HEAP;
}

Card::~Card() {}

int Card::GetValue() { return value_; }
wchar_t Card::GetSuit() { return suit_; }

void Card::ChangePos(Position pos)
{
	position_ = pos;
}

std::wostream& operator << (std::wostream& iostr, Card card)
{
	std::wstring str;
	wchar_t ch = '0';

	if (card.GetValue() > 10)
	{
		if (card.GetValue() == 11)
			ch = 'J';
		else if (card.GetValue() == 12)
			ch = 'Q';
		else if (card.GetValue() == 13)
			ch = 'K';
		else if (card.GetValue() == 14)
			ch = 'A';
	}
	else
		str.append(std::to_wstring(card.GetValue()));
	if (ch != '0')
		str.append(1, ch);  //добавить в конец строки n символов ch -> дописали номер
	str.append(1, card.GetSuit()); // -> дописали масть

	iostr << str;
	return iostr;
}