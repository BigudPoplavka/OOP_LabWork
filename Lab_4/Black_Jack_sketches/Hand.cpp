#include "Card.h"
#include "Hand.h"
#include <iostream>
#include <string>

Hand::Hand()
{
	card_count_ = 0;
	card_score_ = 0;
}

Hand::~Hand()
{
	for (int i = 0; i < card_max_count; i++)
		delete my_cards[i];
}

void Hand::TakeCard(Card &card)
{
	my_cards[card_count_] = new Card(card);
	if (my_cards[card_count_]->GetValue() != 14)
	{
		for (int i = 0; i < card_count_ - 1; i++)
		{
			if (my_cards[i]->GetValue() == 14)
			{
				if (card_score_ + my_cards[card_count_]->GetValue() > 21)
				{
					card_score_ -= 11;
					card_score_ += 1;
					card_score_ += my_cards[card_count_]->GetValue();
				}
			}
		}
		//card_score_ += 10 <= my_cards[card_count_]->GetValue() ? 10 : my_cards[card_count_]->GetValue();
		if (card_score_ += 10 <= my_cards[card_count_]->GetValue())
			card_score_ += 10;
		else
			card_score_+= my_cards[card_count_]->GetValue();
	}
	else if (card_count_ + 11 <= 21) card_score_ += 11;
	else card_score_ += 1;

	card_count_++;
}

void Hand::PrintHand()
{
	for (int i = 0; i < card_count_; i++)
		std::cout << my_cards[i] << " " << std::endl;
}

void Hand::PrintHandDealer()
{
	std::cout << "The Diller's hand" << my_cards[0] << std::endl;
}

void Hand::PrintScore()
{
	std::cout << "The Player has " << card_score_ << "points" << std::endl;
}

void Hand::PrintScoreDealer()
{
	std::cout << "The Diller has " << card_score_ << "points" << std::endl;
}

void Hand::Refresh()
{
	card_count_ = 0;
	card_score_ = 0;
}

