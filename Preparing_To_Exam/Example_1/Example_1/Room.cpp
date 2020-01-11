#include "Room.h"

Room::Room(int num, int price)
{
	num_ = num;
	price_ = price;
}

Room::~Room() {}

int Room::getNum() { return num_; }
int Room::getPrice() { return price_; }