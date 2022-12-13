#include <fstream>
#include "carpark.h"
#include "passenger.h"
#include "cargo.h"


void init_carpark(CarPark& carpark, std::ifstream& file)
{
	char isPassenger;
	while (file >> isPassenger)
	{
		//car
		std::string brand,
					state_number,
					surname,
					fname,
					patronymic;

		//passenger
		std::string model,
					type_of_body,
					color;

		//cargo
		std::string type_of_cargo;
		size_t		tonnage;

		file >> brand >> state_number >> surname >> fname >> patronymic;

		if (isPassenger == '1') 
		{
			file >> type_of_body >> model >> color;
			Passenger passenger = Passenger(type_of_body, model, color, brand, state_number, surname, fname, patronymic);
			carpark.adding_by_pointer(std::move(std::make_unique<Passenger>(passenger)));
		}

		else
		{
			file >> type_of_cargo >> tonnage;
			Cargo cargo = Cargo(tonnage, type_of_cargo, brand, state_number, surname, fname, patronymic);
			carpark.adding_by_pointer(std::move(std::make_unique<Cargo>(cargo)));
		}
	}
}

void task(CarPark& carpark)
{
	auto isVan = [](const CInfo& ptr)
	{
		Cargo* t = dynamic_cast<Cargo*>(ptr.get());
		return t && t->get_type_of_cargo() == "VAN";
	};
	carpark.erase_if(isVan);
}

int main()
{
	std::ifstream file("text.txt");
	CarPark carpark("carpark #1");
	init_carpark(carpark, file);
	carpark.print();
	task(carpark);
	carpark.print();
	file.close();
	std::cin.get();
}