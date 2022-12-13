#pragma once
#include "carpark.h"

CarPark::CarPark()
	: name("") 
{}

CarPark::CarPark(const std::string& name)
	: name(name) 
{}

std::string CarPark::get_name() const
{
	return name;
}

void CarPark::set_name(const std::string& _name)
{
	name = _name;
}

void CarPark::adding_by_pointer(CInfo ptrCar)
{
	auto beg = list_of_cars.begin();
	while (beg != list_of_cars.end() && (*beg)->compare(*ptrCar) == -1)
		++beg;
	list_of_cars.insert(beg, std::move(ptrCar));
}

void CarPark::add_to_head(CInfo ptrCar)
{
	list_of_cars.push_front(std::move(ptrCar));
}

void CarPark::add_to_tail(CInfo ptrCar)
{
	list_of_cars.push_back(std::move(ptrCar));
}

void CarPark::erase_if(std::function<bool(const CInfo&)> function)
{
	auto i = std::remove_if(list_of_cars.begin(), list_of_cars.end(), function);
	list_of_cars.erase(i, list_of_cars.end());
}

void CarPark::sort()
{
	list_of_cars.sort(
		[](const CInfo& ptrCarFirst, const CInfo& ptrCarSecond)
		{
			return ptrCarFirst->compare(*ptrCarSecond) == -1;
		}
	);
}

void CarPark::print()
{
	for (const CInfo& ptrCar : list_of_cars)
		ptrCar->print();
}