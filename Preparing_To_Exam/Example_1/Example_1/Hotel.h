#pragma once
#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include "Room.h"

using namespace std;

class Hotel
{
private:
	int rooms_count_;
	Room** ROOMS_;
	
public:
	Hotel(int n);
	~Hotel();

	void show();
};