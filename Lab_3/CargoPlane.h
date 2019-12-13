#pragma once
#include "PassengerPlane.h"
#include "ILoadable.h"

class CargoPlane: public PassengerPlane, public ILoadable
{
private:
	std::string cargo_info_ = "************CARGO Planes************";
	std::string cargo_loaded_ = "Shipment loaded!";

protected:
	int length_;
	int width_;

public:
	//constructors&destructor
	CargoPlane();
	CargoPlane(int max_baggage, int length, int width);
	~CargoPlane();

	//getters&setters
	int getLength();
	int getWidth();

	//voids

	//implementation
	void AirInfo();
	int RandomFlight();
	void Imitation();

	void Load(int baggage) override;
};