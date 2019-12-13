#include "MilitaryPlane.h"

//constructors&destructor
MilitaryPlane::MilitaryPlane()
{
	int bombs_cur_ = 0;
	int bombs_max_ = 10;
	int number_ = 000;
}

MilitaryPlane::MilitaryPlane(int bombs_max, int number)
{
	int bombs_cur_ = RandomFlight();
	int bombs_max_ = bombs_max;
	int number_ = number;
}

MilitaryPlane::~MilitaryPlane(){}

//get / set
int MilitaryPlane::getBombsCur() { return bombs_cur_; }
int MilitaryPlane::getBombsMax() { return bombs_max_; }
int MilitaryPlane::getNumber() { return number_; }

void MilitaryPlane::setBombsMax(int bombs_max) { bombs_max_ = bombs_max; }
void MilitaryPlane::setNumber(int number) { number_ = number; }

//voids

//implementation
void MilitaryPlane::AirInfo()
{
	printf("\n");
	printf("\n===================================================\n");
	std::cout << military_info_ << std::endl;
	std::cout << "- Name: " << name_ << std::endl;
	printf("- Current bombs count: %d\n", bombs_cur_);
	printf("- Max bombs count: %d\n", bombs_max_);
}

int MilitaryPlane::RandomFlight()
{
	printf("\n Mission complete! Press F to pay respect...\n");

	srand(time(0));
	bombs_cur_ = 1 + rand() % this->bombs_max_;

	return bombs_cur_;
	bombs_cur_ = 0;
}

void MilitaryPlane::Imitation()
{
	this->AirInfo();
	this->RandomFlight();
}

void MilitaryPlane::Load(int baggage)
{
	if (baggage > bombs_max_)
		bombs_cur_ = bombs_max_;
	else
	{
		bombs_cur_ = baggage;
		std::cout << "EQUIPMENT LOADED!" << std::endl;
	}
}