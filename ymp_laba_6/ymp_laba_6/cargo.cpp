#include "cargo.h"

Cargo::Cargo()
	: tonnage(0), type_of_cargo(TANKER), Car()
{}

Cargo::Cargo(size_t tonnage, string type_of_cargo, string brand, string state_number, string surname, string firstname, string patronymic)
	: tonnage(tonnage), type_of_cargo(set_type_of_cargo(type_of_cargo)), Car(brand, state_number, surname, firstname, patronymic)
{}

size_t Cargo::get_tonnage() const
{
	return tonnage;
}

string Cargo::get_type_of_cargo() const
{
    return type_of_cargo == TANKER ? "TANKER" : type_of_cargo == VAN ? "VAN" : "ONBOARD";
}

void Cargo::set_tonnage(size_t _tonnage)
{
    tonnage = _tonnage;
}

t_cargo Cargo::set_type_of_cargo(string str)
{
    return str == "TANKER" ? TANKER: str == "VAN" ? VAN: ONBOARD;
}

void Cargo::print()
{
    cout << "\n\t| Cargo |\n";
    Car::print();
    cout << tonnage << " Ton" << '\n' << get_type_of_cargo() << '\n';
}
