#pragma once
#include "car.h"

enum t_cargo
{
	TANKER,
	VAN,
	ONBOARD
};

class Cargo : public Car
{
private:
	size_t tonnage;
	t_cargo type_of_cargo;
public:
	Cargo();
	Cargo(size_t tonnage, string type_of_cargo, string brand, string state_number, string surname, string firstname, string patronymic);

	size_t get_tonnage() const;
	string get_type_of_cargo() const;

	void set_tonnage(size_t _tonnage);
	static t_cargo set_type_of_cargo(string str);

	void print();
};

