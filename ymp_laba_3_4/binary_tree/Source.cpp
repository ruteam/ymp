#include <fstream>
#include <string>
//#include "queue.h"
#include "Tree.h"
#include <queue>
#include <stack>
using namespace std;
//int count_even(Tree t)
//{
//	int result = 0;
//	if (t)
//		result = (t->info % 2 == 0 ? 1 : 0) + count_even(t->left) + count_even(t->right);
//	return result;
//}
//
//using TElem = Tree;
//struct STACK
//{
//	STACK() {}
//	void push(TElem elem) {}
//	Tree pop() {}
//	bool empty() {}
//};
//
////Обход в глубину
//int count_even_stack(Tree root)
//{
//	int result = 0;
//	STACK s;
//	Tree t = root;
//	while (t)
//	{
//		result = (t->info % 2 == 0 ? 1 : 0);
//		if (t->left)
//		{
//			if (t->right)
//				s.push(t->right);
//			t = t->left;
//		}
//		else
//			if (t->right)
//				t = t->right;
//			else
//				if (s.empty())
//					t = nullptr;
//				else
//					t = s.pop();
//	}
//	return result;
//}
//
//struct QUEUE
//{
//	QUEUE() {}
//	Tree dequeue() {}
//	void enqueue(TElem elem) {}
//	bool empty() {}
//};
//
//int count_even_queue(Tree root)
//{
//	int result = 0;
//	Tree t = root;
//	QUEUE q;
//	q.enqueue(t);
//	while (!q.empty())
//	{
//		t = q.dequeue();
//		result = (t->info % 2 == 0 ? 1 : 0);
//		if (t->left)
//			q.enqueue(t->left);
//		if (t->right)
//			q.enqueue(t->right);
//	}
//	return result;
//}
//
//void add(Tree& t, TInfo elem)
//{
//	if (!t)
//		t = new NODE(elem);
//	else
//		if (elem < t->info)
//			add(t->left, elem);
//		else
//			if (elem > t->info)
//				add(t->right, elem);
//			else
//				t->count++;
//}
//
//Tree search(const Tree& root, TInfo elem)
//{
//	Tree t = root, ptr = nullptr;
//	while (t && !ptr)
//	{
//		if (elem < t->info)
//			t = t->left;
//		else
//			if (elem > t->info)
//				t = t->right;
//			else
//				ptr = t;
//	}
//	return ptr;
//}
//
//Tree Build_Search(std::string file_name)
//{
//	std::ifstream file(file_name);
//	Tree root = nullptr;
//	int elem;
//	while (file >> elem)
//		add(root, elem);
//	file.close();
//	return root;
//}
//
////Печать в возрастающем порядке
//void print_order(Tree t)
//{
//	if (t)
//	{
//		print_order(t->left);
//		for (int i = 1; i <= t->count; ++i)
//			std::cout << t->info << ' ';
//		print_order(t->right);
//	}
//}
//
////r - Поддерево
//
//
//
//
//Tree Build_Formula(std::ifstream& file)
//{
//	char c = file.get();
//	Tree result = new NODE(' ');
//	if (c >= '0' && c <= '0')
//		result->info = c;
//	else
//	{
//		result->left;
//		result->left = Build_Formula(file);
//		result->info = file.get();
//		result->right = Build_Formula(file);
//		c = file.get();
//	}
//	return result;
//}
//
//std::string print_to_string(const Tree& t)
//{
//	std::string result = "";
//	if (!t->left && !t->right)
//		result += t->info;
//	else
//		result = '(' + print_to_string(t->left) + t->info + print_to_string(t->right) + ')';
//	return result;
//}
//
//int calc(const Tree& t)
//{
//	int result;
//	if (!t->left && !t->right)
//		result = t->info - '0';
//	else
//	{
//		int left = calc(t->left);
//		int right = calc(t->right);
//		switch (t->info)
//		{
//		case '+':
//			result = left + right;
//			break;
//		case '*':
//			result = left * right;
//			break;
//		case '-':
//			result = left - right;
//			break;
//		}
//	}
//	return result;
//}
//
//int rec_count_on_level(Tree t, int level, int i = 0)
//{
//	int result = 0;
//
//	if (t)
//	{
//		if (i == level)
//			result++;
//		else if (i < level)
//		{
//			if (t->left)
//				result += rec_count_on_level(t->left, level, i + 1);
//			if (t->right)
//				result += rec_count_on_level(t->right, level, i + 1);
//		}
//	}
//
//	return result;
//}
//
//int count_on_level(Tree t, int level)
//{
//	int result = 0;
//	if (t)
//	{
//		queue q;
//		q.push({ 0, t });
//		while (!q.empty())
//		{
//			Pair current = q.pop();
//			if (current.level == level)
//				result++;
//			else if (current.level < level)
//			{
//				if (current.tree->left)
//					q.push({ current.level + 1, current.tree->left });
//				if (current.tree->right)
//					q.push({ current.level + 1, current.tree->right });
//			}
//		}
//	}
//	return result;
//}
//
//int main()
//{
//	ifstream file("tree.txt");
//	int count;
//	file >> count;
//	Tree root = Build_Balance(file, count);
//	Print(root, 0);
//	
//	int level = 0;
//	while (level < count / 2)
//	{
//		cout << "\n\n======[ " << level << " ]======\n";
//		cout << "Rec:    " << rec_count_on_level(root, level);
//		cout << "\nNo rec: " << count_on_level(root, level);
//		level++;
//	}
//
//	Clear(root);
//	cin.get();
//	return 0;
//}

void task_rec(Tree& t, int level, int& count)
{
	if (t)
	{
		if (level)
		{
			task_rec(t->left, level - 1, count);
			task_rec(t->right, level - 1, count);
		}
		else
			++count;
	}
}

int task_rec2(Tree& t, int level)
{
	int result = 0;
	if (t)
	{
		if (level)
		{
			result += task_rec2(t->left, level - 1);
			result += task_rec2(t->right, level - 1);
		}
		else
			++result;
	}
	return result;
}

//int count_on_level(Tree t, int level)
//{
//	int result = 0;
//	if (t)
//	{
//		queue q;
//		q.push({ 0, t });
//		while (!q.empty())
//		{
//			Pair current = q.pop();
//			if (current.level == level)
//				result++;
//			else if (current.level < level)
//			{
//				if (current.tree->left)
//					q.push({ current.level + 1, current.tree->left });
//				if (current.tree->right)
//					q.push({ current.level + 1, current.tree->right });
//			}
//		}
//	}
//	return result;
//}

int task_1(Tree t, int sum = 0)
{
	if (t)
	{
		if (!t->right && !t->left)
			sum += t->info;
		else
		{
			if (t->right)
				sum = task_1(t->right, sum);
			if (t->left)
				sum = task_1(t->left, sum);
		}
	}
	return sum;
}

int task_1_1(Tree t)
{
	int sum = 0;
	if (t)
	{
		queue<Tree> q;
		q.push(t);
		while (!q.empty())
		{
			Tree tmp = q.front();
			q.pop();

			if (!tmp->right && !tmp->left)
				sum += tmp->info;
			else
			{
				if (tmp->right)
					q.push(tmp->right);
				if (tmp->left)
					q.push(tmp->left);
			}
		}
	}
	return sum;
}

bool task_2(Tree& t)
{
	bool result = true;
	if (t)
	{
		if (!t->right && !t->left)
			result = false;
		else
		{
			if (t->right && !task_2(t->right))
				delete_element(t->right, t->right->info);

			if (t->left && !task_2(t->left))
				delete_element(t->left, t->left->info);
		}
	}
	return result;
}

bool task_2_1(Tree& t)
{
	auto isLeaf = [](Tree tmp)
	{
		return !tmp->right && !tmp->left;
	};
	bool result = false;
	if (t)
	{
		queue<Tree> q;

		if (isLeaf(t))
			delete_element(t, t->info);
		else
			q.push(t);

		while (!q.empty())
		{
			Tree tmp = q.front();
			q.pop();

			if (tmp->right)
			{
				if (isLeaf(tmp->right))
					result = delete_element(tmp->right, tmp->right->info);
				else
					q.push(tmp->right);
			}

			if (tmp->left)
			{
				if (isLeaf(tmp->left))
					result = delete_element(tmp->left, tmp->left->info);
				else
					q.push(tmp->left);
			}
		}
	}
	return result;
}

int task_3(Tree t)
{
	int count = 0;
	if (t)
	{
		count = t->info < 0 ? 1 : 0;
		if (t->left)
			count += task_3(t->left);
		if (t->right)
			count += task_3(t->right);
	}
	return count;
}

int task_3_1(Tree t)
{
	int count = 0;
	if (t)
	{
		queue<Tree> q;
		q.push(t);
		while (!q.empty())
		{
			Tree tmp = q.front();
			q.pop();
			count += tmp->info < 0 ? 1 : 0;
			if (tmp->right)
				q.push(tmp->right);
			if (tmp->left)
				q.push(tmp->left);
		}
	}
	return count;
}

//// *????????????* ////
int task_4(Tree t, int max = 0)
{
	if (t)
	{
		if (t->left)
			task_4(t->left, abs(t->info) > max ? abs(t->info): max);
		if (t->right)
			task_4(t->right, abs(t->info) > max ? abs(t->info) : max);
	}
	return max;
}

int main()
{
	ifstream file("tree.txt");
	int count;
	file >> count;
	Tree root = Build_Balance(file, count);
	Print(root, 0);

	//int n, result = 0;
	//cin >> n;
	//task_rec(root, n, result);
	//cout << result;
	//cout << ' ' << task_rec2(root
	//	, n);

	//=============[ TASK 1 ]=============
	std::cout << "========[ TASK 1 ]========\n";
	std::cout << task_1(root);
	std::cout << '\n';
	std::cout << task_1_1(root);

	//=============[ TASK 2 ]=============
	/*std::cout << "\n\n========[ TASK 2 ]========\n";
	if (task_2_1(root))
		Print(root, 0);*/
	
	//=============[ TASK 3 ]=============
	std::cout << "\n\n========[ TASK 3 ]========\n";
	std::cout << task_3(root);
	std::cout << '\n';
	std::cout << task_3_1(root);
	std::cout << '\n';

	//=============[ TASK 4 ]=============
	std::cout << "\n\n========[ TASK 4 ]========\n";
	std::cout << task_4(root);
	std::cout << '\n';
	//std::cout << task_3_1(root);

	Clear(root);
	std::cin.get();
	return 0;
}