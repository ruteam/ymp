#include "Account.h"
#include <tuple>
Account::Account(std::ifstream& file)
{
	file >> number;
	for (int i = 0; i < 3; ++i)
		file >> date[i];
	file.ignore();
	std::getline(file, client);
	file >> type_of_transaction;
	file.ignore();
	file >> sum;
	file.ignore();
	std::string delim_line;
	std::getline(file, delim_line);
}

void Account::print()
{
	std::cout << number << '\n';
	for (int i = 0; i < 3; ++i)
	{
		std::cout << date[i];
		if (i != 2)
			std::cout << '.';
	}

	std::cout << '\n';
	std::cout << client << '\n';
	if (type_of_transaction)
		std::cout << "Приход" << '\n';
	else
		std::cout << "Расход" << '\n';
	std::cout << sum << '\n';
	std::cout << "---------------------------\n";
}

int Account::compare(const Account& acc)
{
	int result = 1;
	if (date[2] == acc.date[2] && date[1] < acc.date[1] || date[2] < acc.date[2])
		result = -1;
	else if (date[2] == acc.date[2] && date[1] == acc.date[1])
		result = 0;


	return result;
}

int Account::get_year()
{
	return date[2];
}

int Account::get_month()
{
	return date[1];
}

int Account::get_sum()
{
	return sum;
}

int Account::get_number()
{
	return number;
}

bool Account::get_type_of_transaction()
{
	return type_of_transaction;
}
