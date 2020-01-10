#pragma once
#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include "Book.h"

class BookSorter
{
private:

public:
	bool operator()(Book* book_1, Book* book_2)
	{
		if (book_1->getAuthor() < book_2->getAuthor())	//первичный ключ
			return true;
		else if (book_1->getAuthor() == book_2->getAuthor())	//вторичный ключ
			return book_1->getTitle() < book_2->getTitle();
		else return false;
	}
};

class BookFinder
{
private:
	int first_;
	int last_;

public:
	BookFinder(int first, int last)
	{
		first_ = first;
		last_ = last;
	}

	bool operator()(Book* book_1)	//поиск книг в диапазоне от года a до года b 
	{
		int tmp = book_1->getYear();
		return tmp >= first_ && tmp <= last_;
	}
};