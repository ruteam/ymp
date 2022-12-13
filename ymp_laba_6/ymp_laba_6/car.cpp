#include "car.h"

Car::Car()
	: brand(""), state_number(""), surname(""), fname(""), patronymic("")
{}

Car::Car(const std::string& brand, const std::string& state_number, const std::string& surname, const std::string& fname, const std::string& patronymic)
	: brand(brand), state_number(state_number), surname(surname), fname(fname), patronymic(patronymic)
{}

std::string Car::get_brand() const
{
	return brand;
}

std::string Car::get_state_number() const
{
	return state_number;
}

std::string Car::get_fio() const
{
	return surname + ' ' + fname + ' ' + patronymic;
}

void Car::set_brand(const std::string& _brand)
{
	brand = _brand;
}

void Car::set_state_number(const std::string& _state_number)
{
	state_number = _state_number;
}

void Car::set_fio(const std::string& _surname, const std::string& _fname, const std::string& _patronymic)
{
	surname = _surname;
	fname = _fname;
	patronymic = _patronymic;
}

int Car::compare(const Car& tmp) const
{
	int result = 1;
	if (surname < tmp.surname ||
		surname == tmp.surname && fname < tmp.fname)
		result = -1;
	else
		result = 0;
	return result;
}

void Car::print()
{
	std::cout << get_fio() << '\n' << brand << '\n' << state_number << '\n';
}

