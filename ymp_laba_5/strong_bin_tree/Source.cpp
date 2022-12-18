#include <fstream>
#include <set>
#include "trietree.h"

//����������� ��� ����
//��������� �����
//��������� �����

//��������� ���������� ����, ������� ���������� � �������� ���������
//������� ��� �����, ������������ � ��������� ���������
//��������� �����-�������� ������, ������������ � �������� ���������

void print_all(TrieTree& t, std::string word = "")
{
	if (all_ptrs_empty(t))
		std::cout << word << '\n';
	else
		for (size_t i = 0; i < 26; ++i)
			if (t->ptrs[i])
				print_all(t->ptrs[i], word + char(i + 'a'));
}

void count_words(TrieTree& t, int& count)
{
	if (t->eow)
		++count;
	for (size_t i = 0; i < 26; ++i)
		if (t->ptrs[i])
			count_words(t->ptrs[i], count);
}

int count_words(TrieTree& t)
{
	int count = 0;
	if (t->eow)
		count = 1;
	for (size_t i = 0; i < 26; ++i)
		if (t->ptrs[i])
			count += count_words(t->ptrs[i]);
	return count;
}

void copy(TrieTree& t, TrieTree& tc)
{
	if (t)
	{
		tc = new NODE(t->eow);
		for (size_t i = 0; i < 26; ++i)
			if (t->ptrs[i])
				copy(t->ptrs[i], tc->ptrs[i]);
	}
}

TrieTree copy(TrieTree& t)
{
	TrieTree tc = nullptr;
	if (t)
	{
		for (size_t i = 0; i < 26; ++i)
			if (t->ptrs[i])
				tc->ptrs[i] = copy(t->ptrs[i]);
	}
	return tc;
}

int count_sub(TrieTree& t, std::string sub, int i)
{
	int count = 0;
	if (sub.length() < i + 1)
		count = count_words(t);
	else 
		if (t->ptrs[sub[i] - 'a'])
			count = count_sub(t->ptrs[sub[i] - 'a'], sub, i + 1);
	return count;
}

void clear_sub(TrieTree& t, std::string sub, int i)
{
	if (sub.length() < i + 1)
		clear(t);
	else
	{
		if (t->ptrs[sub[i] - 'a'])
			clear_sub(t->ptrs[sub[i] - 'a'], sub, i + 1);
		if (!t->eow && all_ptrs_empty(t))
		{
			delete t;
			t = nullptr;
		}
	}
}

TrieTree copy_sub(TrieTree& t, std::string sub, int i = 0)
{
	TrieTree result = nullptr;
	if (t)
	{
		if (sub.length() < i + 1)
			result = copy(t);
		else
		{
			if (t->ptrs[sub[i] - 'a'])
				result = copy_sub(t->ptrs[sub[i] - 'a'], sub, i + 1);
			TrieTree pr = new NODE;
			pr->ptrs[sub[i] - 'a'] = result;
			result = pr;
		}
	}
	return result;
}

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
	//task(root);
	//print_all(root);
	/*int count = 0;
	count_words(root, count);
	std::cout << count;
	std::cout << ' ';
	std::cout << count_words(root);*/
	/*TrieTree cpy;
	copy(root, cpy);
	print(cpy, "");*/
	//clear(cpy);

	std::string subword;
	std::cin >> subword;
	std::cin.ignore();
	//std::cout << count_sub(root, subword, 0);
	//clear_sub(root, subword, 0);
	//print_all(root);
	TrieTree cpyy;
	cpyy = copy_sub(root, subword);
	print(cpyy, "");
	clear(cpyy);
	clear(root);
	return 0;
}


