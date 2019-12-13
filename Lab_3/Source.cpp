#include "PassengerPlane.h"
#include "CargoPlane.h"
#include "MilitaryPlane.h"

int main()
{
//SETTINGS
	setlocale(LC_ALL, "EN");

//GLOBAL
	PassengerPlane AIRPLANES[2];
	CargoPlane CARGOPLANES[3];
	MilitaryPlane MILITARYPLANES[2];

//AIRPLANES
	PassengerPlane Boing_732A(2019, 100, 280, "Boing", "DoNNU_Airlines");
	Boing_732A.Load(256);
	
	PassengerPlane Boing_732B(2019, 200, 290, "Boing", "DoNNU_Airlines");
	Boing_732B.Load(270);
	
	AIRPLANES[0] = Boing_732A;
	AIRPLANES[1] = Boing_732B;

	for (int i = 0; i < 2; i++)
		AIRPLANES[i].Imitation();

//CARGO AIRPLANES
	printf("\n\n\nLoading cargo on cargo airplanes...\n");

	CargoPlane CPlane_1(300, 30, 35);
	CPlane_1.Load(200);

	CargoPlane CPlane_2(300, 30, 35);
	CPlane_2.Load(300);

	CargoPlane CPlane_3(350, 45, 45);
	CPlane_3.Load(327);

	CARGOPLANES[0] = CPlane_1;
	CARGOPLANES[1] = CPlane_2;
	CARGOPLANES[2] = CPlane_3;

	for (int i = 0; i < 3; i++)
		CARGOPLANES[i].Imitation();

//MILITARY AIRPLANES
	printf("\n\n\nLoading equipment on military airplanes...\n");

	MilitaryPlane stels_1;		//setters... why not?
	stels_1.setBombsMax(20);
	stels_1.setNumber(356);
	stels_1.Load(18);

	MilitaryPlane stels_2;
	stels_2.setBombsMax(20);
	stels_2.setNumber(357);
	stels_2.Load(15);

	MILITARYPLANES[0] = stels_1;
	MILITARYPLANES[1] = stels_2;

	for (int i = 0; i < 2; i++)
		MILITARYPLANES[i].Imitation();

	printf("\n");
	system("pause");
	return 0;
}
