#include "Fraction.h"


static int object_counter_;
Fraction res;

Fraction::Fraction() {}                 //empty constructor
									//overload constructors
Fraction::Fraction(int numerator, int denominator)
{
	numerator_ = numerator;
	denominator_ = denominator;
	object_counter_++;
}

Fraction::~Fraction()		//destructor
{
	object_counter_--;
}

//overloading operator 
Fraction& Fraction::operator +(Fraction& expr)
{	
	res = Fraction((this->numerator_ * expr.denominator_) + (expr.numerator_ * this->denominator_), 
					(this->denominator_ * expr.denominator_));
	return res;
}

Fraction& Fraction::operator -(Fraction& expr)
{
	res = Fraction((this->numerator_ * expr.denominator_) - (expr.numerator_ * this->denominator_),
		(this->denominator_ * expr.denominator_));
	return res;
}

Fraction& Fraction::operator *(Fraction& expr)
{
	res = Fraction((this->numerator_ * expr.numerator_), (this->denominator_ * expr.denominator_));
	return res;
}

Fraction& Fraction::operator /(Fraction& expr)
{
	res = Fraction((this->numerator_ * expr.denominator_), (this->denominator_ * expr.numerator_));
	return res;
}

//get / set   
int Fraction::getNumerator() {return numerator_;}
int Fraction::getDenominator() {return denominator_;}
void Fraction::setNumerator(int& numerator) {numerator_ = numerator;}
void Fraction::setDenominator(int& denominator) {denominator_ = denominator;}

//voids
int DigitCount(double num)
{
	return num ? 1 + DigitCount(num / 10) : 0;        //if (n != 0) return 1 + schet(n / 10);
}
void Fraction::printAsFraction(double& decimal_fraction)
{	
	int cnt = 0, n = 0, k = 1;

	int befDot = (int)(decimal_fraction);           //0.344 -> 0 
	double temp = (decimal_fraction - befDot);		//0.344
	cnt = DigitCount(temp) - 1;						//4 - 1 = 3

	/*												
	if (cnt == 1) k = 10;
	else if (cnt == 2) k = 100;
	else if (cnt == 3) k = 1000;
	...
	*/
	for (int i = 0; i < cnt; i++) k *= 10;
	
	Fraction res((temp * k), k);
}

void Fraction::printAsFraction(char* decimal_fraction)
{
	//TODO 
}

int Fraction::gcd(int n, int m)
{
	int res = 1;
	while (m != 0)
	{
		res = m;
		m = n % m;
		n = res;
	}

	return res;
}

//<= To Be Continued