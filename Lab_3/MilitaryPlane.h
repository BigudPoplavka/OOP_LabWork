#pragma once
#include "Airplane.h"
#include "ILoadable.h"

class MilitaryPlane : public Airplane, public ILoadable
{
private:
	int bombs_cur_;
	int bombs_max_;
	int number_;

	std::string name_ = "STELS";

	std::string military_info_ = "**********MILITARY AIRPLANES**********";

protected:

public:
	//constructors&destructor
	MilitaryPlane();
	MilitaryPlane(int bombs_max, int number);
	~MilitaryPlane();

	//get / set
	int getBombsCur();
	int getBombsMax();
	int getNumber();

	void setBombsMax(int bombs_max);
	void setNumber(int number);

	//voids

	//implementation
	void AirInfo() override;
	int RandomFlight() override;
	void Imitation() override;

	void Load(int baggage) override;
};