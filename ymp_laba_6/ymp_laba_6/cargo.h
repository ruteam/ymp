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
	Cargo(const size_t& tonnage, const t_cargo& type_of_cargo, const std::string& brand, const std::string& state_number, const std::string& surname, const std::string& fname, const std::string& patronymic);

	size_t get_tonnage() const;
	std::string get_type_of_cargo() const;

	void set_tonnage(const size_t& _tonnage);
	static t_cargo set_type_of_cargo(const std::string& str);

	void print();
};

