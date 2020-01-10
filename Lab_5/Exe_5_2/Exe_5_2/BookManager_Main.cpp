#include "BookManager.h"

int main()
{
	setlocale(LC_ALL, "RUSSIAN");

	vector<Book*> BOOKS;

	BOOKS.push_back(new Book("Война и мир", "Толстой Л.Н.", 2010));
	BOOKS.push_back(new Book("Подросток", "Достоевский Ф.М.", 2004));
	BOOKS.push_back(new Book("Обрыв", "Гончаров И.А.", 2010));
	BOOKS.push_back(new Book("Анна Каренина", "Толстой Л.Н.", 1999));
	BOOKS.push_back(new Book("Зов Ктулху", "Лавкрафт Г.Ф.", 2003));
	BOOKS.push_back(new Book("Хребты Безумия", "Лавкрафт Г.Ф.", 2004));
	BOOKS.push_back(new Book("Некрономикон", "Абдул АльХазред", 2000));
	BOOKS.push_back(new Book("Фауст", "Гёте И.В.", 2010));
	BOOKS.push_back(new Book("Пикник на обочине", "Стругацкие Б.Н. и А.Н.", 2011));
	BOOKS.push_back(new Book("Трудно быть Богом", "Стругацкие Б.Н. и А.Н.", 2011));
	BOOKS.push_back(new Book("Солярис", "Станислав Герман Лем", 2019));

	//использование лямба-функции
	cout << "Книги выпущенные позже 2009: " <<
	count_if(BOOKS.begin(), BOOKS.end(), [](Book* book) {return book->getYear() > 2009; }) << endl;

	vector<Book*>::iterator i;
	for (i = BOOKS.begin(); i != BOOKS.end(); i++)
		delete (*i);
}