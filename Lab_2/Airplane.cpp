#include <iostream>
#include <stdio.h>
#include "Airplane.h"

//constructors&destructor
Airplane::Airplane(std::string mod, std::string aircomp, short year, int Users)
{
	model_ = mod;
	airCompany_ = aircomp;
	YearOfIssue_ = year;
	NumberOfUsers_ = Users;
}

Airplane::~Airplane(){}

	//get / set
	void Airplane::setModel(std::string model) { model_ = model; }
	void Airplane::setAirCompany(std::string comp) { airCompany_ = comp; }
	void Airplane::setYear(const int year) { YearOfIssue_ = year; }
	void Airplane::setNumberOfUsers(const int NU) { NumberOfUsers_ = NU; }

	std::string Airplane::getModel() { return model_; }
	std::string Airplane::getCompany() { return airCompany_; }
	short Airplane::getYear() { return YearOfIssue_; }
	int Airplane::getUsers() { return NumberOfUsers_; }


	//voids
	int Airplane::RandomFlight()
	{
		srand(time(0));
		double neizv = 0.0;
		int x = 1 + rand() % this->NumberOfUsers_;
		// 100    Users
		// neizv	x
		neizv = (x * 100) / NumberOfUsers_; 
		percentage_ = (int)neizv;
		local_users_ = x;

		return x;
	}
	//imitation
	void Airplane::Imitation()
	{
		for (int i = 0; i < 3; i++) {

			printf("\nImitation ¹%d\n", i + 1);
			this->RandomFlight();
			this->FlightInfo();
		}
	}
	//sorting
	void Airplane::SortInfo(Airplane arr[], const int &arr_size)
	{
		int min_perc = 0;
		int min_pos = 0;
		Airplane tmp("", "", 0, 0);

		for (int i = 0; i < arr_size; i++)
		{
			min_pos = i;
			min_perc = arr[i].RandomFlight();
			tmp = arr[i];
			for (int j = i + 1; j < arr_size; j++)
			{
				if (arr[j].RandomFlight() < min_perc)
				{
					min_pos = j;
					min_perc = arr[j].RandomFlight();
				}
			}
			arr[min_pos] = arr[i];
			arr[i] = tmp;
		}
	}

	//outInfo
	void Airplane::FlightInfo() {
		printf("------------------------------------------");
		printf("- Max users: %d\n", NumberOfUsers_);
		printf("- Local users: %d\n", local_users_);
		printf("- Percentage: %d%%\n", percentage_);
		printf("------------------------------------------");
	}

	void Airplane::AirInfo() {
		printf("\n");
		printf("------------------------------------------");
		printf("- Model: %s\n", model_);
		printf("- Company: %s\n", airCompany_);
		printf("- Year of issue: %d\n", YearOfIssue_);
		printf("- Max users: %d\n", NumberOfUsers_);
		printf("------------------------------------------");
	}

	//   serialize/deserialize
	void Airplane::serialize(std::string name) {
		system("cls");

		std::ofstream out(name);

		if (out.is_open()) {
			out << std::endl;
			out << "- model: " << model_ << std::endl;
			out << "- AirCompany: " << airCompany_ << std::endl;
			out << "- YearOfIssue: " << YearOfIssue_ << std::endl;
			out << "- NumberofUsers: " << NumberOfUsers_ << std::endl;
			out << "- Local Users: " << local_users_ << std::endl;
			out << "- Percentage: " << percentage_ << std::endl;
		}
		out.close();
	}

	void Airplane::deserialize(std::string name) {
		system("cls");
		std::string line;
		std::ifstream in(name);
		if (in.is_open()) {
			while (getline(in, line)) {
				std::cout << line << std::endl;
			}
		}

	}

	void Airplane::serialize() {

		std::ofstream out("example.txt");

		if (out.is_open()) {
			out << std::endl;
			out << "- model: " << model_ << std::endl;
			out << "- AirCompany: " << airCompany_ << std::endl;
			out << "- YearOfIssue: " << YearOfIssue_ << std::endl;
			out << "- NumberofUsers: " << NumberOfUsers_ << std::endl;
			out << "- Local Users: " << local_users_ << std::endl;
			out << "- Percentage: " << percentage_ << std::endl;
		}
		out.close();
	}
	void Airplane::deserialize() {
		system("cls");
		std::string line;
		std::ifstream in("example.txt");
		if (in.is_open()) {
			while (std::getline(in, line)) {
				std::cout << line << std::endl;
			}
		}
	}
