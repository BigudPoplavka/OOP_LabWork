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

	BookSorter BS;
	BookFinder BF(2000, 2011);


	cout << "\n\nКниги в алфавитном порядке:\n\n";
	sort(BOOKS.begin(), BOOKS.end(), BS);
	vector<Book*>::iterator i;
	for (i = BOOKS.begin(); i != BOOKS.end(); ++i)
	{
		cout << (*i)->getAuthor() << " \"" << (*i)->getTitle() << "\"" << std::endl;
	}

	std::cout << "\n\nКниги в диапазоне года издания 2000 - 2011:\n\n";
	std::vector<Book*>::iterator finder = find_if(BOOKS.begin(), BOOKS.end(), BF);
	while (finder != BOOKS.end())
	{
		cout << (*finder)->getAuthor() << " \"" << (*finder)->getTitle() << "\"" << std::endl;
		finder = find_if(++finder, BOOKS.end(), BF);
	}

	for (i = BOOKS.begin(); i != BOOKS.end(); ++i)
		delete (*i);
}