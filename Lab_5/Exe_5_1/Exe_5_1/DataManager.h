#pragma once
#include <iostream>
#include <ostream>
#include <fstream>
#include <iterator>
#include <algorithm>
#include <deque>
#include <vector>

using namespace std;

template<class T>
class DataManager
{
private:
	string   dumpFile_ = "dump.dat";
	static const int MAX_ = 64;
	vector<char> Replace_{ '.', ',', '-', ':', ';', '!', '?', '\"', '\'' };

public:
	deque<T> DATA_;

	DataManager();
	~DataManager();

	T peek();
	T pop();

	void push(T elem);
	void push(T* elems, size_t n);
	void SaveToFile();
	void LoadFromFile();
	void PrintData();

	char pushChar(char elem);
	char popUpper();
	char popLower();

};


//implementation

template<class T>
DataManager<T>::DataManager()
{
	cout << "# Created Data-Manager: " << typeid(T).name() << " type" << endl;
	DATA_.clear();
}

template<class T>
DataManager<T>::~DataManager() { DATA_.clear(); }

template<class T>
T DataManager<T>::peek() { return DATA_.back(); }

template<class T>
T DataManager<T>::pop()
{
	try
	{
		if (DATA_.size() < 2)
		{
			return DATA_[0];
			DATA_.pop_back();
			this->LoadFromFile();
		}
		else
		{
			DATA_.erase(DATA_.end() - 1);
			return DATA_[DATA_.size() - 2];
		}
	}
	catch (out_of_range e)
	{
		cout << "# Incorrect index!" << endl;
		cout << "# Bug waw detected in  |  " << typeid(T).name() << " DataManager<T>::pop()  |" << endl;
		cout << "# File: DataManager.h  | " << endl;
	}

}

template<class T>
void DataManager<T>::push(T elem)
{
	DATA_.push_back(elem);
	if (DATA_.size() > MAX_)
		SaveToFile();
}

template<class T>
void DataManager<T>::push(T* elems, size_t n)
{
	for (int i = 0; i < n; i++)
	{
		DATA_.insert(DATA_.cend(), *elems);
		elems++;
	}

	if (DATA_.size() > MAX_)
		SaveToFile();
}

template<class T>
void DataManager<T>::SaveToFile()
{
	ofstream saving;
	saving.open(dumpFile_);

	for (int i = 0; i < DATA_.size(); i++)
	{		
		saving.write(((char*)&DATA_[i]), sizeof(T));
	}
	DATA_.erase(DATA_.begin() + 1, DATA_.end());

	saving.close();
}

template<class T>
void DataManager<T>::LoadFromFile()
{
	ifstream loading;
	loading.open(dumpFile_);

	char* bufTemp = new char[MAX_ * sizeof(T)];
	loading.read(bufTemp, MAX_ * sizeof(T));

	DATA_.clear();
	for (int i = 0; i < MAX_; i++)
		DATA_.push_back((T)bufTemp[i]);

	loading.close();
}


template<>
char DataManager<char>::pushChar(char elem)
{
	for (int i = 0; i < Replace_.size(); i++)
		if (elem == Replace_[i])
		{
			DATA_.push_back('_');
			return Replace_[i];
			break;
		}
}

template<>
char DataManager<char>::popUpper()
{
	try
	{
		int index = DATA_.size() < 2 ? 0 : DATA_.size() - 2;
		char ans = toupper(DATA_[index]);
		DATA_.erase(DATA_.begin() + index);

		if (DATA_.size() <= 0)
			this->LoadFromFile();

		return ans;
	}
	catch (out_of_range e)
	{
		cout << "# Incorrect index!" << endl;
		cout << "# Bug waw detected in  |  char DataManager<char>::popUpper()  |" << endl;
		cout << "# File: DataManager.h  | " << endl;
	}
}

template<>
char DataManager<char>::popLower()
{
	try
	{
		int index = DATA_.size() < 2 ? 0 : DATA_.size() - 2;
		char ans = tolower(DATA_[index]);
		DATA_.erase(DATA_.begin() - 1 + index);

		if (DATA_.size() <= 0)
			this->LoadFromFile();

		return ans;
	}
	catch (out_of_range e)
	{
		cout << "# Incorrect index!" << endl;
		cout << "# Bug waw detected in  |  char DataManager<char>::popLower()  |" << endl;
		cout << "# File: DataManager.h  | " << endl;
	}

}

template<class T>
void DataManager<T>::PrintData()
{
	ostream_iterator<T> printer(cout, " ");   //( ostream&, char * delimiter )

	cout << "Data collection: ";
	copy(DATA_.begin(), DATA_.end(), printer);
}
