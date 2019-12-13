#pragma once
#include "Airplane.h"
#include "ILoadable.h"
#include <ctime>
#include <fstream>
#include <iterator>
#include <string>

class PassengerPlane : public ILoadable, public Airplane
{
private:
	int MaxUsers_;
	int localUsers_;

	std::string airpl_info = "***************AIRPLANES***************";
	std::string err_msg_users_ = "ERROR! Users limit exceeded!";
	std::string msg_users_ = "Current users: ";
	std::string msg_max_users_ = "Max users: ";

public:

	int YearOfIssue_;
	int baggage_;
	int max_baggage_;
	int percentage_;

	std::string model_;
	std::string airCompany_;

	std::string err_msg_cargo_ = "ERROR! Load limit exceeded!";
	std::string msg_cur_ = "Current baggage: ";
	std::string msg_max_ = "Max baggage: ";

	//constructors&destructor
	PassengerPlane();
	PassengerPlane(int year, int maxUsers, int maxBaggage, std::string mod, std::string aircomp);
	~PassengerPlane();

	//get / set
	int getYear();
	int getMaxUsers();
	int getLocalUsers();
	int getBaggage();
	int getMaxBaggage();
	std::string getModel();
	std::string getCompany();

	void setMaxBaggage(int max_baggage);

	//voids
	void FlightInfo();

	//serialize/deserialize -> work with file
	void serialize(std::string name);
	void deserialize(std::string name);
	void serialize();
	void deserialize();

	//implementation
	void AirInfo() override;
	int RandomFlight() override;
	void Imitation() override;	  //I BELIVE I CAN FLY

	void ILoadable::Load(int weight) override;
};