#include "PassengerPlane.h"

PassengerPlane::PassengerPlane()
{
	YearOfIssue_ = 2019;
	MaxUsers_ = 200;
	localUsers_ = 1;
	baggage_ = 1;
	max_baggage_ = 400;
	model_ = "model";
	airCompany_ = "company";
}

PassengerPlane::PassengerPlane(int year, int maxUsers, int maxBaggage, std::string mod, std::string aircomp)
{
	YearOfIssue_ = year;
	MaxUsers_ = maxUsers;
	localUsers_ = RandomFlight();
	max_baggage_ = maxBaggage;
	model_ = mod;
	airCompany_ = aircomp;
}

PassengerPlane::~PassengerPlane() {}

//get / set
int PassengerPlane::getYear() { return YearOfIssue_; }
int PassengerPlane::getMaxUsers() { return MaxUsers_; }
int PassengerPlane::getLocalUsers() { return localUsers_; }
int PassengerPlane::getBaggage() { return baggage_; }
int PassengerPlane::getMaxBaggage() { return max_baggage_; }
std::string PassengerPlane::getModel() { return model_; }
std::string PassengerPlane::getCompany() { return airCompany_; }

void PassengerPlane::setMaxBaggage(int max_baggage) { max_baggage_ = max_baggage; }

//voids
void PassengerPlane::FlightInfo() {
	printf("\n--------------FLIGHT INFO----------------\n");
	printf("- Local users: %d\n", localUsers_);
	printf("- Percentage: %d%%\n", percentage_);
}

//serialize/deserialize -> work with file
void PassengerPlane::serialize(std::string name)
{
	system("cls");

	std::ofstream out(name);

	if (out.is_open()) {
		out << std::endl;
		out << "- model: " << model_ << std::endl;
		out << "- AirCompany: " << airCompany_ << std::endl;
		out << "- YearOfIssue: " << YearOfIssue_ << std::endl;
		out << "- NumberofUsers: " << MaxUsers_ << std::endl;
		out << "- Local Users: " << localUsers_ << std::endl;
		out << "- Percentage: " << percentage_ << std::endl;
	}
	out.close();
}

void PassengerPlane::deserialize(std::string name)
{
	system("cls");
	std::string line;
	std::ifstream in(name);
	if (in.is_open()) {
		while (getline(in, line)) {
			std::cout << line << std::endl;
		}
	}
}

void PassengerPlane::serialize()
{
	std::ofstream out("example.txt");

	if (out.is_open()) {
		out << std::endl;
		out << "- model: " << model_ << std::endl;
		out << "- AirCompany: " << airCompany_ << std::endl;
		out << "- YearOfIssue: " << YearOfIssue_ << std::endl;
		out << "- NumberofUsers: " << MaxUsers_ << std::endl;
		out << "- Local Users: " << localUsers_ << std::endl;
		out << "- Percentage: " << percentage_ << std::endl;
	}
	out.close();
}

void PassengerPlane::deserialize()
{
	system("cls");
	std::string line;
	std::ifstream in("example.txt");
	if (in.is_open()) {
		while (std::getline(in, line)) {
			std::cout << line << std::endl;
		}
	}
}

//implementation
void PassengerPlane::AirInfo() {
	printf("\n");
	printf("\n===================================================\n");
	std::cout << airpl_info << std::endl;
	std::cout << "- Model: " << model_ << std::endl;
	std::cout << "- AirCompany: " << airCompany_ << std::endl;
	printf("- Year: %d\n", YearOfIssue_);
	printf("- Max users in airplane : %d\n", MaxUsers_);
}

int PassengerPlane::RandomFlight()
{
	srand(time(0));
	double neizv = 0.0;
	int loc = 1 + rand() % this->MaxUsers_;
	// maxUsers   loc
	// 100%	     x%
	neizv = (loc * 100) / MaxUsers_;
	percentage_ = (int)neizv;
	localUsers_ = loc;

	return loc;
}

void PassengerPlane::Imitation()
{
	this->RandomFlight();
	this->AirInfo();
	this->FlightInfo();
}

void PassengerPlane::Load(int weight)
{
	if (weight > max_baggage_)
		std::cout << err_msg_cargo_ << std::endl;
	else
		baggage_ = weight;
}