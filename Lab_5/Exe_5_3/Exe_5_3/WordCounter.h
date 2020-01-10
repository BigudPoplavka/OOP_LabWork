#pragma once
#include <fstream>
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <iterator>
#include <string>
#include <map>
#include <vector>

using namespace std;

int max_chars = 3;
int max_words = 7;
int word_count = 0;

char delimiters[] = { ' ', '.', ',', '-', ':', ';', '!' };

vector<string> SplitString(string& str, char* delimiter, int size)
{
	vector<string> res_;
	string tmp;
	string tmp_;
	int offset = 0;

	for (int symb = 0; symb < str.size(); symb++)
	{
		for (int i = 0; i < size; i++)	//проверяем разделители
			if (str[symb] == delimiter[i])
			{
				tmp = "";
				tmp = str.substr(offset, symb - offset);
				res_.push_back(tmp);
				offset = symb + 1;

				break;
			}

		if (symb == str.size() - 1)  //последний символ
		{
			tmp = "";
			tmp = str.substr(offset, symb - offset + 1);
			res_.push_back(tmp);
		}
	}
	return res_;
}

//инициализация 
void MapInitialize(map<string, int> map, char* delimiters)
{
	ifstream fs;
	fs.open("sonet.txt");
	while (!fs.eof())
	{
		string tmp;
		cin >> tmp;

		vector<string> res = SplitString(tmp, delimiters, 7);
		for (int i = 0; i < res.size(); i++)
		{
			cout << res[i] << endl;
			if (res[i].size() != 0) map[res[i]]++;	  //наращиваем ключи
		}
	}
	fs.close();
}
