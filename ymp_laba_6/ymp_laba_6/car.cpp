#include "car.h"

Car::Car()
	: brand(""), state_number(""), surname(""), firstname(""), middlename("")
{}

Car::Car(string brand, string state_number, string surname, string firstname, string middlename)
	: brand(brand), state_number(state_number), surname(surname), firstname(firstname), middlename(middlename)
{}

string Car::get_brand() const
{
	return brand;
}

string Car::get_state_number() const
{
	return state_number;
}

string Car::get_fio() const
{
	return surname + ' ' + firstname + ' ' + middlename;
}

void Car::set_brand(string _brand)
{
	brand = _brand;
}

void Car::set_state_number(string _state_number)
{
	state_number = _state_number;
}

void Car::set_fio(string _surname, string _firstname, string _middlename)
{
	surname    = _surname;
	firstname  = _firstname;
	middlename = _middlename;
}

int Car::compare(const Car& tmp) const
{
	int result = 1;
	if (surname < tmp.surname ||
		surname == tmp.surname && firstname < tmp.firstname || 
		surname == tmp.surname && firstname == firstname && middlename < tmp.middlename)
		result = -1;
	else
		result = 0;
	return result;
}

void Car::print()
{
	cout << get_fio() << '\n' << brand << '\n' << state_number << '\n';
}

