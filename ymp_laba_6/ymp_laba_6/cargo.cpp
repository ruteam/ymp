#include "cargo.h"

Cargo::Cargo()
	: tonnage(0), type_of_cargo(TANKER), Car()
{}

Cargo::Cargo(size_t tonnage, std::string type_of_cargo, std::string brand, std::string state_number, std::string surname, std::string fname, std::string patronymic)
	: tonnage(tonnage), type_of_cargo(set_type_of_cargo(type_of_cargo)), Car(brand, state_number, surname, fname, patronymic)
{}

size_t Cargo::get_tonnage() const
{
	return tonnage;
}

std::string Cargo::get_type_of_cargo() const
{
    return type_of_cargo == TANKER ? "TANKER" : type_of_cargo == VAN ? "VAN" : "ONBOARD";
}

void Cargo::set_tonnage(size_t _tonnage)
{
    tonnage = _tonnage;
}

t_cargo Cargo::set_type_of_cargo(std::string str)
{
    return str == "TANKER" ? TANKER: str == "VAN" ? VAN: ONBOARD;
}

void Cargo::print()
{
    std::cout << "\n\t| Cargo |\n";
    Car::print();
    std::cout << tonnage << " Ton" << '\n' << get_type_of_cargo() << '\n';
}
