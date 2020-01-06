#include "Gamer.h"
#include <iostream>
#include <stdio.h>

Gamer::Gamer() {}

Gamer::Gamer(int money)
{
	hand = new Hand();
	money_balance_ = money;
}

int Gamer::getBalance() { return money_balance_; }

void Gamer::printBalance()
{
	std::cout << "Balance of Player = " << money_balance_ << "$ " << std::endl;
}