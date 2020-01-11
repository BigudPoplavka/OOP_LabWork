#pragma once
#include <iostream>
#include <stdio.h>
#include <string>

class ICalculator
{
public:
	virtual int add(int a, int b) = 0;
	virtual ~ICalculator() {}
};