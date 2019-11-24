#pragma once

#include <iostream>
#include <stdio.h>
#include <cstring>
#include <sstream>
#include <cmath>


class Fraction
{
private:
	int numerator_;
	int denominator_;
	

public:
	size_t& Count() { static size_t c = 0; return c; }   ///created objects counter

	Fraction();                //empty constructor
								  //overload constructors
	Fraction(int numerator, int denominator);

	~Fraction();		//destructor

	//overloading operator 
	Fraction& operator +(Fraction& expr);
	Fraction& operator -(Fraction& expr);
	Fraction& operator *(Fraction& expr);
	Fraction& operator /(Fraction& expr);

	//get / set 
	int getNumerator();		  
	int getDenominator();
	void setNumerator(int& numerator);
	void setDenominator(int& denominator);

	//voids
	static void printAsFraction(double& decimal_fraction);
	static void printAsFraction(char* decimal_fraction);
	static int gcd(int n, int m);

};