
#include <fstream>
#include "carpark.h"
#include "passenger.h"
#include "cargo.h"

void init_carpark(CarPark& carpark, ifstream& file)
{
	char isPassenger;
	while (file >> isPassenger)
	{
		//car
		string brand,
			   state_number,
			   surname,
			   firstname,
			   middlename;

		//passenger
		string model,
			   type_of_body,
			   color;

		//cargo
		string type_of_cargo;
		size_t tonnage;

		file >> brand 
			 >> state_number 
			 >> surname 
			 >> firstname 
			 >> middlename;

		if (isPassenger == '1')
		{
			file >> type_of_body >> model >> color;
			Passenger passenger(type_of_body, model, color, brand, state_number, surname, firstname, middlename);
			carpark.insert(move(make_unique<Passenger>(passenger)));
		}
		else
		{
			file >> type_of_cargo >> tonnage;
			Cargo cargo(tonnage, type_of_cargo, brand, state_number, surname, firstname, middlename);
			carpark.insert(move(make_unique<Cargo>(cargo)));
		}
	}
}

void task(CarPark& carpark)
{
	auto isVan = [](const PPtr& ptr)
	{
		Cargo* tmp = dynamic_cast<Cargo*>(ptr.get());
		return tmp && tmp->get_type_of_cargo() == "Фургон";
	};
	carpark.remove(isVan);
}

int main()
{
	setlocale(LC_ALL, "ru");
	ifstream file("text.txt");
	CarPark carpark("carpark #1");
	init_carpark(carpark, file);
	file.close();
	carpark.print();
	task(carpark);
	carpark.print();
	cin.get();
}