#include "Dealer.h"

Dealer::Dealer():Gamer(30000) {}

int Dealer::GetDealerSum() { return sum_; }
int Dealer::GetDealerCurrSum() { return sum_curr_; }