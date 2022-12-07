#include "My_List.h"
#include <Windows.h>



std::string monthToString(int month)
{
	std::string monthString = "� ";
	switch (month)
	{
	case 1:
		monthString += "������\n";
		break;
	case 2:
		monthString += "�������\n";
		break;
	case 3:
		monthString += "�����\n";
		break;
	case 4:
		monthString += "������\n";
		break;
	case 5:
		monthString += "���\n";
		break;
	case 6:
		monthString += "����\n";
		break;
	case 7:
		monthString += "����\n";
		break;
	case 8:
		monthString += "�������\n";
		break;
	case 9:
		monthString += "��������\n";
		break;
	case 10:
		monthString += "�������\n";
		break;
	case 11:
		monthString += "������\n";
		break;
	case 12:
		monthString += "�������\n";
		break;
	}
	return monthString;
}
void inputYear(int& year)
{
	do {
		std::cout << "������� ���:\n";
		std::cout << "--> ";
		std::cin >> year;
	} while (year < 1970);
}


void task(DLIST& accs)
{
	ptrNODE p = accs.get_begin();
	int year;
	inputYear(year);

	while (p && p->info.get_year() != year)
		p = p->next;

	if (!p)
		std::cout << "��� �� ������";
	else
	{
		int sum = 0;
		int maxSum = sum;
		int count = 0;
		std::string month = "\t";
		while (p && p->info.get_year() == year)
		{
			sum += p->info.get_type_of_transaction() ? p->info.get_sum() : -p->info.get_sum();;

			if (!p->next || p->next->info.get_month() != p->info.get_month())
			{
				if (sum > maxSum)
				{
					maxSum = sum;
					month = '\t' + monthToString(p->info.get_month());
					count = 1;
				}
				else
					if (sum == maxSum)
					{
						month += '\t' + monthToString(p->info.get_month());
						count += 1;
					}
				sum = 0;
			}
			p = p->next;
		}

		std::cout << "\n=====-- MAX PROFIT --=====";
		std::cout << "\n\t  " << maxSum << "\n";
		std::cout << month;
	}
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	std::ifstream file("accounts2.txt");
	if (file)
	{
		DLIST accs("accounts2.txt");
		accs.print();
		std::cout << "\n===========================\n";
		task(accs);
	}
	return 0;
}