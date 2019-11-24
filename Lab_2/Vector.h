#pragma once

#include <iostream>
#include <stdio.h>
#include <cstring>


class Vector
{
private:                        //class data
	int size_;
	double* elem_;


public:
	Vector();                   //empty constructor
								//overload constructors
	Vector(int size);
	Vector(int size, double elem);
	Vector(int size, double& elem);	

	~Vector();		//destructor

	//overloading operator 
	double& operator[] (int index);

	//get / set
	int getSize();		   
	double getElem();

	//voids
	void setSize(int& size);		
	void setElem(int index, double elem);
	void PrintVector();		
};