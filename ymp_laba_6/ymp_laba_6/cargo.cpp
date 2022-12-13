#include "cargo.h"

Cargo::Cargo()
	: tonnage(0), type_of_cargo(TANKER), Car()
{}

Cargo::Cargo(const size_t& tonnage, const t_cargo& type_of_cargo, const std::string& brand, const std::string& state_number, const std::string& surname, const std::string& fname, const std::string& patronymic)
	: tonnage(tonnage), type_of_cargo(type_of_cargo), Car(brand, state_number, surname, fname, patronymic)
{}

size_t Cargo::get_tonnage() const
{
	return tonnage;
}

std::string Cargo::get_type_of_cargo() const
{
    return type_of_cargo == TANKER ? "TANKER" : type_of_cargo == VAN ? "VAN" : "ONBOARD";
}

void Cargo::set_tonnage(const size_t& _tonnage)
{
    tonnage = _tonnage;
}

t_cargo Cargo::set_type_of_cargo(const std::string& str)
{
    return str == "TANKER" ? TANKER: str == "VAN" ? VAN: ONBOARD;
}

void Cargo::print()
{
    std::cout << "\n[======[ Cargo ]======]\n";
    Car::print();
    std::cout << tonnage << " ton" << '\n' << get_type_of_cargo() << '\n';
}
