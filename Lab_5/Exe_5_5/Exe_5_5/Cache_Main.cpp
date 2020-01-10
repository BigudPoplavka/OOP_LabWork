#include "Cache.h"

int main()
{
	setlocale(LC_ALL, "RUSSIAN");

	Cache<int> CacheInt;
	Cache<string> CacheStr;

	CacheInt.put(1);
	CacheInt.put(2);
	CacheInt.put(3);
	CacheInt += 5;

	CacheStr.add("I draw ");
	CacheStr.add("manga");
	CacheStr.add("progressive-metal");
	CacheStr += "DJENT";

	bool b1 = CacheInt.contains(2);
	bool b2 = CacheInt.contains(8);
	bool b3 = CacheStr.contains("manga");
	bool b4 = CacheStr.contains("djent-metal");

	cout << b1 << "\n" << b2 << "\n" << b3 << "\n" << b4 << endl;

	system("pause");
	return 0;
}