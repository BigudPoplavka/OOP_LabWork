#include <iostream>
#include <stdio.h>
#include <cstring>
#include "Vector.h"
#include "Matrix.h"
#include "Fraction.h"
#include "Airplane.h"

int main(){
	setlocale(LC_ALL, "ru");

	//EXE_1
	int size = 5;

	Vector vector(size);
	vector.PrintVector();
	std::cout << vector.getSize() << std::endl;
	vector.~Vector();

	std::cout << std::endl;

	//EXE_2
	int rows = 5, cols = 3;

	Matrix WakeUpNeo(rows, cols);
	WakeUpNeo.PtintMatrix();
	std::cout << WakeUpNeo.GetAt(2, 3) << std::endl;
	WakeUpNeo.~Matrix();

	std::cout << std::endl;

	//EXE_3 
	int a = 3;
	int b = 5;
	int c = 10;
	int d = 38;
	
	Fraction res_1(1, 1);
	Fraction res_2(1, 1);
	Fraction res_3(1, 1);
	Fraction res_4(1, 1);

	Fraction expr_1(a, b);
	Fraction expr_2(c, d);
	
	res_1 = expr_1 + expr_2;
	res_2 = expr_1 - expr_2;
	res_3 = expr_1 * expr_2;
	res_4 = expr_1 / expr_2;

	std::cout << std::endl;

	//EXE_4
	const int arr_size = 3;

	Airplane Boing_H66H("", "", 1, 1);
	Airplane Boing_732A("", "", 1, 1);
	Airplane Boing_732B("", "", 1, 1);

	Airplane AirArray[arr_size] = { Boing_H66H, Boing_732A, Boing_732B };

	//with getter / setter
	Boing_H66H.setModel("SATAN'S");
	Boing_H66H.setAirCompany("HELL_UNDERGROUNDLINES");
	Boing_H66H.setYear(2666);
	Boing_H66H.setNumberOfUsers(Boing_H66H.RandomFlight());

	Boing_732A.setModel("BOING_732_A");
	Boing_732A.setAirCompany("PENDEL_AIRLINES");
	Boing_732A.setYear(2016);
	Boing_732A.setNumberOfUsers(Boing_732A.RandomFlight());

	Boing_732B.setModel("BOING_732_B");
	Boing_732B.setAirCompany("PENDEL_AIRLINES");
	Boing_732B.setYear(2019);
	Boing_732B.setNumberOfUsers(Boing_732B.RandomFlight());

	//with constructor
	Airplane MadeFromPaper("PAPER", "PAPER_AIRLINES", 2019, 1310);

	//output
	AirArray->SortInfo(AirArray, arr_size);
	for (int i = 0; i < arr_size; i++)
	{
		AirArray[i].FlightInfo();
		AirArray[i].AirInfo();
	}

	//clearning
	delete[] AirArray;
}