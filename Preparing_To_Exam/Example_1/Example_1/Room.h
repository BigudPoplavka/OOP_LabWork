#pragma once
#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

class Room
{
private:
	int num_;
	int price_;

public:
	Room(int num, int price);
	~Room();

	int getNum();
	int getPrice();
};