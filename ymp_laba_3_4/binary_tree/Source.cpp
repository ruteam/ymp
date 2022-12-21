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
//
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



//Найти сумму листьев
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

//Удалить листовые элементы
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

//Найти количество отрицательных элементов
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

//Найти максимальный по модулю элемент
int task_4(Tree t)
{
	int max = abs(t->info);
	if (t)
	{
		if (t->left)
			max = task_4(t->left) > max ? task_4(t->left) : max;
		if (t->right)
			max = task_4(t->right) > max ? task_4(t->right) : max;
	}
	return max;
}

int task_4_1(Tree t)
{
	if (t)
	{
		queue<Tree> q;
		int max = t->info;
		q.push(t);
		while (!q.empty())
		{
			Tree tmp = q.front();
			q.pop();
			if (abs(tmp->info) > max)
				max = abs(tmp->info);
			if (tmp->left)
				q.push(tmp->left);
			if (tmp->right)
				q.push(tmp->right);
		}
		return max;
	}
}


//Найти значение самого левого листа
int task_5(Tree t)
{
	int result;
	if (t)
		if (!t->left && !t->right)
			result = t->info;
		else if (t->left)
			result = task_5(t->left);
	return result;
}

int task_5_1(Tree t)
{
	if (t)
	{
		queue<Tree> q;
		q.push(t);
		int result;
		while (!q.empty())
		{
			Tree tmp = q.front();
			q.pop();
			if (tmp->left)
				q.push(tmp->left);
			else if (!tmp->left && !tmp->right)
				result = tmp->info;
		}
		return result;
	}
}

//Заменить отрицательные элементы на их абсолютные величины
void task_6(Tree& t)
{
	if (t)
	{
		if (t->info < 0)
			t->info = abs(t->info);
		if (t->left)
			task_6(t->left);
		if (t->right)
			task_6(t->right);
	}
}

void task_6_1(Tree& t)
{
	if (t)
	{
		queue<Tree> q;
		q.push(t);
		while (!q.empty())
		{
			Tree tmp = q.front();
			q.pop();
			if (tmp->info < 0)
				tmp->info = abs(tmp->info);
			if (tmp->left)
				q.push(tmp->left);
			if (tmp->right)
				q.push(tmp->right);
		}
	}
}

//Напечатать значения листьев
void task_7(Tree t)
{
	if (t)
	{
		if (!t->right && !t->left)
			std::cout << t->info << ' ';
		if (t->right)
			task_7(t->right);
		if (t->left)
			task_7(t->left);
	}
}

void task_7_1(Tree t)
{
	if (t)
	{
		std::queue<Tree> q;
		q.push(t);
		while (!q.empty())
		{
			Tree tmp = q.front();
			q.pop();

			if (!tmp->right && !tmp->left)
				std::cout << tmp->info << ' ';
			if (tmp->right)
				q.push(tmp->right);
			if (tmp->left)
				q.push(tmp->left);
		}
	}
}

//Проверить входит ли элемент E в дерево T
int task_8(Tree t, int e)
{
	int result = 0;
	if (t)
	{
		if (t->info == e)
			result = 1;
		else if (!result)
		{
			if (t->right)
				result += task_8(t->right, e);
			if (t->left)
				result += task_8(t->left, e);
		}
	}
	return result;
}

bool task_8_1(Tree t, TInfo e)
{
	bool result = false;
	if (t)
	{
		std::queue<Tree> q;
		q.push(t);
		while (!q.empty() && !result)
		{
			Tree tmp = q.front();
			q.pop();
			
			if (tmp->info == e)
				result = true;
			else
			{
				if (tmp->right)
					q.push(tmp->right);
				if (tmp->left)
					q.push(tmp->left);
			}
		}
	}
	return result;
}

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

//Подсчитать количество элементов на n-ом уровне
int task_9(Tree t, int level, int i = 0)
{
	int result = 0;
	if (t)
	{
		if (i == level)
			result++;
		else if (i < level)
		{
			if (t->left)
				result += task_9(t->left, level, i + 1);
			if (t->right)
				result += task_9(t->right, level, i + 1);
		}
	}
	return result;
}

int task_9_1(Tree t, int level)
{
	int result = 0;
	if (t)
	{
		std::queue<std::pair<int, Tree>> q;
		q.push({ 0, t });
		while (!q.empty())
		{
			std::pair<int, Tree> current = q.pop();
			if (current.first == level)
				result++;
			else if (current.first < level)
			{
				if (current.second->left)
					q.push({ current.first + 1, current.second->left });
				if (current.second->right)
					q.push({ current.first + 1, current.second->right });
			}
		}
	}
	return result;
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
	std::cout << task_4_1(root);

	//=============[ TASK 5 ]=============
	std::cout << "\n\n========[ TASK 5 ]========\n";
	std::cout << task_5(root);
	std::cout << '\n';
	std::cout << task_5_1(root);
	
	//=============[ TASK 6 ]=============
	std::cout << "\n\n========[ TASK 6 ]========\n";
	{
		ifstream file("tree.txt");
		file >> count;
		Tree tmp_root = Build_Balance(file, count);
		task_6(tmp_root);
		Print(tmp_root, 0);
		Clear(tmp_root);
	}
	{
		ifstream file("tree.txt");
		file >> count;
		Tree tmp_root = Build_Balance(file, count);
		task_6_1(tmp_root);
		Print(tmp_root, 0);
		Clear(tmp_root);
	}
	std::cout << '\n';
	
	//=============[ TASK 7 ]=============
	std::cout << "\n\n========[ TASK 7 ]========\n";
	task_7(root);
	std::cout << '\n';
	task_7_1(root);

	//=============[ TASK 8 ]=============
	std::cout << "\n\n========[ TASK 8 ]========\n";
	if (task_8(root, -6))
		std::cout << "Yes";
	else
		std::cout << "No";
	std::cout << '\n';
	if (task_8_1(root, -6))
		std::cout << "Yes";
	else
		std::cout << "No";
	std::cout << '\n';

	//=============[ TASK 9 ]=============
	std::cout << "\n\n========[ TASK 9 ]========\n";
	std::cout << task_9(root, 1);
	std::cout << '\n';
	std::cout << task_9_1(root, 1);

	Clear(root);
	std::cin.get();
}