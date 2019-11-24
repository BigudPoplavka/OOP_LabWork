#pragma once

#include <iostream>
#include <cstdio>
#include <string>
#include <ctime>
#include <fstream>
#include <iterator>
#include <algorithm>


class Airplane
{
private:
	short YearOfIssue_;
	int NumberOfUsers_;
	int local_users_;
	std::string model_;
	std::string airCompany_;

public:
	int percentage_;

	Airplane(std::string mod, std::string aircomp, short year, int Users);
	~Airplane();

	//get / set
	std::string getModel();
	std::string getCompany();

	short getYear();
	int getUsers();

	void setModel( std::string m);
	void setAirCompany(std::string a);
	void setYear(const int year);
	void setNumberOfUsers(const int NU);

	//voids
	int RandomFlight();
	//I BELIVE I CAN FLY
	void Imitation();
	//sorting
	void SortInfo(Airplane array[], const int& size);

	//outInfo
	void FlightInfo();
	void AirInfo();

	//   serialize/deserialize -> work with file
	void serialize(std::string name);
	void deserialize(std::string name);
	void serialize();
	void deserialize();
};