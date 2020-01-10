#include "WordCounter.h"

int main()
{
	int max_chars = 3;
	int max_words = 7;
	int word_count = 0;

	char delimiters[] = { ' ', '.', ',', '-', ':', ';', '!' };

	map<string, int> map_;
	MapInitialize(map_, delimiters);

	for (int i = 0; i < map_.size(); i++)
	{
		map<string, int>::iterator MapIterator = map_.begin();
		map<string, int>::iterator MapMax = map_.begin();

		for (MapIterator; MapIterator != map_.end(); MapIterator++)
			if (MapIterator->first.size() > max_chars) 
				MapMax = MapIterator;

		if (MapMax->first.size() > max_chars && MapMax->second >= max_words)
			cout << "Word: " << MapMax->first << " | count: " << MapMax->second << endl;
	}


	system("pause");
	return 0;
}
