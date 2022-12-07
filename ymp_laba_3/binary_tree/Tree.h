#pragma once
#include <iostream>
#include <fstream>

using TInfo = int;

struct NODE
{
	TInfo info;
	NODE* left, * right;
	int count = 0;
	NODE() {}
	NODE(TInfo info, NODE* left = nullptr, NODE* right = nullptr) :info(info), left(left), right(right) {}
	~NODE()
	{
		left = nullptr;
		right = nullptr;
	}
};

using Tree = NODE*;

Tree Build_Balance(std::ifstream& file, int count)
{
	Tree result = nullptr;
	if (count)
	{
		int count_left = count / 2;
		int count_right = count - count_left - 1;
		int x;
		file >> x;
		result = new NODE(x);
		result->left = Build_Balance(file, count_left);
		result->right = Build_Balance(file, count_right);
	}
	return result;
}

void Clear(Tree& t)
{
	if (t)
	{
		Clear(t->left);
		Clear(t->right);
		delete t;
		t = nullptr;
	}
}

void Print(Tree t, int level)
{
	if (t)
	{
		Print(t->right, level + 1);
		for (int i = 1; i <= level; ++i)
			std::cout << "   ";
		std::cout << t->info << '\n';
		Print(t->left, level + 1);
	}
}
