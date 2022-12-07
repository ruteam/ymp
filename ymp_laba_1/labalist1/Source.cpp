#include <Windows.h>
#include <fstream>
#include "My_list.h"

//Задача 7. Удалить первую подпоследовательность из нечетных чисел
//1. create_by_stack: (15 13 11 9) 6 7 5 4 3 2 1
//2. create_by_queue: 1 2 3 4 (5 7) 6 9 11 13 15
//3. create_by_order: 1 2 3 4 5 6 (7 9 11 13 15)

void create_list(LIST& list, const char* fileName);
void isContinue(LIST& list);

bool task(LIST& list)
{
	ptrNODE p = list.get_head();
	bool isDelete = false;

	while (p->next && p->next->next && !isDelete)
	{
		if (*p->next->info % 2 != 0 && *p->next->next->info % 2 != 0)
		{
			while (p->next && *p->next->info % 2 != 0)
				list.del_after(p);
			isDelete = true;
		}
		if (!isDelete)
			p = p->next;
	}

	return isDelete;
}

int main()
{
	setlocale(0, "");
	LIST list;
	char fileName[] = "input.txt";

	create_list(list, fileName);
	list.print();

	if (!list.empty())
	{
		std::ofstream out("output.txt");
		if (task(list))
		{
			list.print();
			list.print(out);
		}
		else
		{
			std::cout << "Подпоследовательность не найдена\n";
			list.print(out, "Подпоследовательность не найдена\n");
		}
		std::cout << "Результат работы записан в output.txt\n";
	}

	isContinue(list);

	return 0;
}

void create_list(LIST& list, const char* fileName)
{
	std::ifstream input(fileName);
	char menu;
	do {
		std::cout << "\nВыберите:\n";
		std::cout << "  1. create_by_stack\n";
		std::cout << "  2. create_by_queue\n";
		std::cout << "  3. create_by_order\n";
		std::cout << "--> ";
		std::cin >> menu;
	} while (menu != '1' && menu != '2' && menu != '3');

	if (menu == '1')
		list.create_by_stack(input);
	else if (menu == '2')
		list.create_by_queue(input);
	else if (menu == '3')
		list.create_by_order(input);
	input.close();
}

void isContinue(LIST& list)
{
	char menu;
	do {
		std::cout << "\nЗавершить работу? (y/n):\n";
		std::cout << "--> ";
		std::cin >> menu;
	} while ((menu != 'y' && menu != 'Y') && (menu != 'n' && menu != 'N'));

	if (menu == 'n' || menu == 'N')
	{
		while (list.get_head()->next)
			list.del_after(list.get_head());
		main();
	}
}