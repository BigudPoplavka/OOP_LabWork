#include "Book.h"

Book::Book()
{
	title_ = "Книга";
	author_ = "Автор";
	year_ = 2020;
}

Book::Book(string title, string author, int year)
{
	title_ = title;
	author_ = author;
	year_ = year;
}

Book::~Book() {}

string Book::getTitle() const { return title_; }
string Book::getAuthor() const { return author_; }
int Book::getYear() { return year_; }

void Book::setTitle(const string& title) { title_ = title; }
void Book::setAuthor(const string& author) { author_ = author; }
void Book::setYear(int year) { year_ = year; }
