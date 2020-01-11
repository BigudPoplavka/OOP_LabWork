#pragma once
#include <iostream>
#include <stdio.h>
#include <iterator>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

template<typename T>
class Cache
{
private:

public:
	vector<T>CACHE_;
	const int max_size_ = 100;

	Cache()
	{
		cout << "# Created new Cache: " << typeid(T).name() << " type |" << "size " << max_size_ << endl;
		for (int i = 0; i < max_size_; i++)
			CACHE_.push_back(0);
	}

	Cache(int n)
	{
		cout << "# Created new Cache: " << typeid(T).name() << " type |" << "size " << n << endl;
		for (int i = 0; i < n; i++)
			CACHE_.push_back(0);
	}

	~Cache()
	{
		cout << "# Deleted Cache! " << typeid(T).name() << " type" << endl;
	}

	void add(T elem) { CACHE_.push_back(elem); }
	void operator += (T elem) { this->add(elem); }  //не обязательно
	void clear() { CACHE_.clear(); }
	void print()
	{
		if (CACHE_.size() != 0)
			for (int i = 0; i < CACHE_.size(); i++)
				cout << CACHE_[i] << endl;
		else throw "# ERROR!!! Cache is empty!";
	}

	bool contains(T elem)
	{
		for (int i = 0; i < CACHE_.size(); i++)
			if (CACHE_[i] == elem)
				return true;
		return false;
	}
};

template<>
class Cache<string>
{
public:
	vector<string>CACHE_;
	const int max_size_ = 100;

	Cache()
	{
		cout << "# Created new Cache: string type |" << "size " << max_size_ << endl;
		for (int i = 0; i < max_size_; i++)
			CACHE_.push_back("0");
	}

	Cache(int n)
	{
		cout << "# Created new Cache: string type |" << "size " << n << endl;
		for (int i = 0; i < n; i++)
			CACHE_.push_back("0");
	}

	~Cache()
	{
		cout << "# Deleted Cache! string type" << endl;
	}

	void add(string elem) { CACHE_.push_back(elem); }
	void operator += (string elem) { this->add(elem); }  //не обязательно
	void clear() { CACHE_.clear(); }
	void print()
	{
		if (CACHE_.size() != 0)
			for (int i = 0; i < CACHE_.size(); i++)
				cout << CACHE_[i] << endl;
		else throw "# ERROR!!! Cache is empty!";
	}

	bool contains(string elem)
	{
		for (int i = 0; i < CACHE_.size(); i++)
			if (CACHE_[i] == elem)
				return true;
		return false;
	}
};