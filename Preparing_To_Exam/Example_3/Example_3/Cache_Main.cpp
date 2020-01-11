#include "Cache.h"
#include <stdio.h>

int main()
{
	Cache<string> Cache_;	//100 strings "0" - default constructor
	Cache<string> Cache_str(1);	// 1 string "0" & 5 other strings...
	Cache_str.add("I");
	Cache_str.add("play");
	Cache_str.add("progressive");
	Cache_str.add("metal");
	Cache_str += "Djent - it's so low!";

	Cache_str.print();
	Cache_str.clear();

	system("pause");
	return 0;
}