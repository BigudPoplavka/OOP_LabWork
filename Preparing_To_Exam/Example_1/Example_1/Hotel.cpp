#include "Hotel.h"
#include <string>

Hotel::Hotel(int n)
{
	ROOMS_ = new Room*[n];
	for (int i = 0; i < n; i++)
		ROOMS_[i] = new Room(i + 1, 30);
	rooms_count_ = n;
}

Hotel::~Hotel() 
{
	for (int i = 0; i < rooms_count_; i++)
		delete[] ROOMS_[i];
	delete[] ROOMS_;
}

void Hotel::show()
{
	for (int i = 0; i < rooms_count_; i++)
			cout << "Room ¹" << ROOMS_[i]->getNum() 
			<< " (" << ROOMS_[i]->getPrice() << ")" << endl;
}