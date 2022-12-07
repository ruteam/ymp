#pragma once
#include <string>
#include <iostream>
#include <fstream>
using TDate = int[3];

class Account
{
private:
	int number;
	TDate date;
	std::string client;
	bool type_of_transaction;
	int sum;
public:
	Account() {}
	Account(std::ifstream& file);
	void print();
	int compare(const Account& acc);
	int get_year();
	int get_month();
	int get_sum();
	int get_number();
	bool get_type_of_transaction();
};