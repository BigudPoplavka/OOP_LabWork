#include <iostream>
#include <stdio.h>
#include <iterator>
#include "DataManager.h"


int main()
{
	DataManager<int> DM_Int;
	DataManager<char> DM_Char;
	DataManager<double> DM_Double;

	cout << "\n\n# WORK WITH DATA-MANAGER: INT \n";
	DM_Int.push(1);
	DM_Int.push(2);
	DM_Int.push(3);
	DM_Int.push(4);

	int i1 = DM_Int.peek();
	int i2 = DM_Int.pop();
	int i3 = DM_Int.peek();

	cout << i1 << "\n" << i2 << "\n" << i3 << endl;
	DM_Int.PrintData();
	cout << endl;


	cout << "\n\n# WORK WITH DATA-MANAGER: CHAR \n\n";
	char* word_1 = new char[7]{ 'B', 'i', 'z', 'z', 'a', 'r', 'e' };
	char* word_2 = new char[9]{ 'A', 'd', 'v', 'e', 'n', 't', 'u', 'r', 'e' };

	DM_Char.push('J');
	DM_Char.push('o');
	DM_Char.push('j');
	DM_Char.push('o');
	DM_Char.push(word_1, 7);
	DM_Char.push(word_2, 9);

	cout << DM_Char.popLower() << endl;
	cout << DM_Char.popUpper() << endl;
	DM_Char.PrintData();


	cout << "\n\n# WORK WITH DATA-MANAGER: DOUBLE \n";
	double Pi = 3.14;
	double e = 2.7;
	double g = 9.8;

	DM_Double.push(Pi);
	DM_Double.push(e);
	DM_Double.push(g);

	DM_Double.PrintData();

	system("pause");
	return 0;
}