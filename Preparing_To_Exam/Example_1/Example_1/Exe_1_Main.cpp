#include "Hotel.h"
#include "Room.h"

int main()
{
	setlocale(LC_ALL, "RUSSIAN");

	Hotel* hotel = new Hotel(5);
	hotel.show();

	system("pause");
	return 0;
}
