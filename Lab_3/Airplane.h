#pragma once
#include <iostream>
#include <stdio.h>
#include <string>
#include <ctime>

//abstract class
class Airplane
{
public:
	virtual void AirInfo() = 0;
	virtual int RandomFlight() = 0;
	virtual void Imitation() = 0;
	virtual ~Airplane(){}
};