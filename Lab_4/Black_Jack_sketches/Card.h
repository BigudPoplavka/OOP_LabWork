#pragma once
#include <iostream>
#include <stdio.h>
#include <exception>
#include <string>

class Card
{
private:
	int value_;
	wchar_t suit_;

public:

	enum Position
	{
		IN_HAND, DECK_HEAP, OUT_GAME
	};

	Position position_;

	Card(int value, wchar_t suit);
	~Card();

	int GetValue();
	wchar_t GetSuit();

	void ChangePos(Position pos); //for shuffle
	friend std::iostream& operator << (std::iostream& iostr, Card card); //for card output
};