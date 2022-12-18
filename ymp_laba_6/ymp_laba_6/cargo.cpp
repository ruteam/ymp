#include "cargo.h"

Cargo::Cargo()
	: tonnage(0), type_of_cargo(Цистерна), Car()
{}

Cargo::Cargo(size_t tonnage, string type_of_cargo, string brand, string state_number, string surname, string firstname, string middlename)
	: tonnage(tonnage), type_of_cargo(set_type_of_cargo(type_of_cargo)), Car(brand, state_number, surname, firstname, middlename)
{}

size_t Cargo::get_tonnage() const
{
	return tonnage;
}

string Cargo::get_type_of_cargo() const
{
    return type_of_cargo == Цистерна ? "Цистерна" : type_of_cargo == Фургон ? "Фургон" : "Бортовой";
}

void Cargo::set_tonnage(size_t _tonnage)
{
    tonnage = _tonnage;
}

t_cargo Cargo::set_type_of_cargo(string str)
{
    return str == "Цистерна" ? Цистерна: str == "Фургон" ? Фургон: Бортовой;
}

void Cargo::print()
{
    cout << "\n\t| Грузовой |\n";
    Car::print();
    cout << tonnage << " Тон" << '\n' << get_type_of_cargo() << '\n';
}
