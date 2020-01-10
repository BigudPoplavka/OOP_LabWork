#pragma once
#include <iostream>
#include <stdio.h>
#include <iterator>
#include <algorithm>
#include <vector>

using namespace std;

template<typename T>
class Cache
{
private:
	vector<T>CACHE_;
public:
	const int max_size_ = 100;

	Cache() 
	{ 
		cout << "# Created new Cache: " << typeid(T).name() << " type" << endl;
	}
	~Cache() 
	{ 
		cout << "# Deleted Cache! " << typeid(T).name() << " type" << endl;
	}

	void put(T elem) { CACHE_.push_back(elem); }
	void operator += (T elem) { this->put(elem); }
	bool contains(T elem)
	{		
		for (int i = 0; i < CACHE_.size(); i++)
			if (CACHE_[i] == elem) 
				return true;
		return false;
	}
};


//явная специализация
template<>
class Cache<string>
{
private:
	vector<string>CACHE_;
public:
	const int max_size_ = 100;
	
	Cache() 
	{ 
		cout << "# Created new Cache: string type" << endl;
	}
	~Cache() 
	{ 
		cout << "# Deleted Cache! string type" << endl;
	}

	void put(string elem) { CACHE_.push_back(elem); }
	void operator += (string elem) { this->put(elem); }

	bool contains(string elem)
	{
		for (int i = 0; i < CACHE_.size(); i++)
			if (CACHE_[i][0] == elem[0]) 
				return true;
		return false;
	}

	void add(string elem)
	{
		if (CACHE_.size() >= max_size_)
			cout << "# Can't add new elem! Cache size = 100 (max size)";
		else CACHE_.push_back(elem);
	}
};