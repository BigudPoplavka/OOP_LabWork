#include "Vector.h"


Vector::Vector() {}                 //empty constructor
									//overload constructors
Vector::Vector(int size)
{
	if (size < 0) size = 0;
	else size_ = size;

	elem_ = new double[size];
	for (int i = 0; i < size; i++) elem_[i] = i * 1.0;
}
Vector::Vector(int size, double elem)
{
	size_ = size;
	elem_ = &elem;
}
Vector::Vector(int size, double& elem)
{
	size_ = size;
	elem_ = &elem;
}
Vector::~Vector() { delete[] elem_; }		//destructor


//overloading operator 
double& Vector::operator[] (int index)
{
	return elem_[index];
}

//get / set
int Vector::getSize() { return size_; }		   
double Vector::getElem() { return *elem_; }

void Vector::setSize(int& size) { size_ = size; }
void Vector::setElem(int index, double elem) { elem_[index] = elem; }

//voids
void Vector::PrintVector()					
{
	for (int i = 0; i < size_; i++)
		std::cout << elem_[i] << " ";
	printf("\n");
}