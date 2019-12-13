#include "CargoPlane.h"

//constructors&destructor
CargoPlane::CargoPlane() 
{
	YearOfIssue_ = 2019;
	baggage_ = 1;
	max_baggage_ = 400;
	model_ = "Dornier";
	airCompany_ = "AirWeight";

	int length_ = 30;
	int width_ = 40;
}

CargoPlane::CargoPlane(int max_baggage, int length, int width)
{
	max_baggage_ = max_baggage;
	length_ = length;
	width_ = width;

	model_ = "Dornier";
	airCompany_ = "AirWeight";
}

CargoPlane::~CargoPlane(){}

//getters&setters
int CargoPlane::getLength() { return length_; }
int CargoPlane::getWidth() { return width_; }

//voids

//implementation
void CargoPlane::AirInfo()
{
	printf("\n");
	printf("\n===================================================\n");
	std::cout << cargo_info_ << std::endl;
	std::cout << "- Model: " << model_ << std::endl;
	std::cout << "- AirCompany: " << airCompany_ << std::endl;
	printf("- Year: %d\n", YearOfIssue_);
	printf("- Current cargo: %d\n", baggage_);
	printf("- Max cargo: %d\n", max_baggage_);
	printf("- Length: %d\n", length_);
	printf("- Width: %d\n", width_);
}

int CargoPlane::RandomFlight()
{
	printf("\n Shipment delivered! \n");

	srand(time(0));
	baggage_ = 1 + rand() % this->max_baggage_;

	return baggage_;
	baggage_ = 0;
}

void CargoPlane::Imitation()
{
	this->AirInfo();
	this->RandomFlight();
}

void CargoPlane::Load(int weight)
{
	if (weight > max_baggage_)
	{ 	
		std::cout << err_msg_cargo_ << std::endl;
		printf("\n");
	}
	else
	{ 
		baggage_ = weight;
		std::cout << cargo_loaded_ << std::endl;
	}
}