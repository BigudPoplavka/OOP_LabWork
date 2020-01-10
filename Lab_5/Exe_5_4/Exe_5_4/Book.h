#pragma once
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

class Book
{
private:
	string title_;
	string author_;
	int year_;

public:
	Book();
	Book(string title, string author, int year);
	~Book();

	string getTitle() const;
	string getAuthor() const;
	int getYear();

	void setTitle(const string& title);
	void setAuthor(const string& author);
	void setYear(int year);
};