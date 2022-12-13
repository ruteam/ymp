#include <fstream>
#include <set>
#include "trietree.h"

void task(TrieTree& t, int is_vowels = -1, std::string word = "")
{
	if (is_vowels != -2)
	{
		std::set<char> vowels = { 'a', 'e', 'o', 'i', 'u',  'y' };

		if (t->eow)
			std::cout << word << '\n';

		for (size_t i = 0; i < 26; ++i)
			if (t->ptrs[i])
				if (is_vowels == -1)
					task(t->ptrs[i], vowels.count(char(i + 'a')), word + char(i + 'a'));
				else
					task(t->ptrs[i], is_vowels == 1 && !vowels.count(char(i + 'a')) ? 0 : is_vowels == 0 && vowels.count(char(i + 'a')) ? 1 : -2, word + char(i + 'a'));
	}
}

int main()
{
	std::ifstream file("text.txt");
	TrieTree root;
	init(root);
	std::string word;
	while (std::getline(file, word))
		if (word.length())
			add(root, word, 0);
	file.close();
	print(root, "");
	std::cout << "------------\n";
	task(root);
	clear(root);
	return 0;
}


