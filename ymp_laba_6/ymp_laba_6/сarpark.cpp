#pragma once
#include "carpark.h"

CarPark::CarPark()
	: name("") 
{}

CarPark::CarPark(std::string name)
	: name(name) 
{}

std::string CarPark::get_name() const
{
	return name;
}

void CarPark::set_name(std::string _name)
{
	name = _name;
}

void CarPark::adding_by_pointer(CInfo ptr)
{
	std::list<CInfo>::iterator beg = list_of_cars.begin();
	while (beg != list_of_cars.end() && (*beg)->compare(*ptr) == -1)
		++beg;
	list_of_cars.insert(beg, std::move(ptr));
}

void CarPark::add_to_head(CInfo ptr)
{
	list_of_cars.push_front(std::move(ptr));
}

void CarPark::add_to_tail(CInfo ptr)
{
	list_of_cars.push_back(std::move(ptr));
}

void CarPark::erase_if(std::function<bool(const CInfo&)> function)
{
	list_of_cars.erase(std::remove_if(list_of_cars.begin(), list_of_cars.end(), function), list_of_cars.end());
}

void CarPark::sort()
{
	list_of_cars.sort([](const CInfo& ptrFirst, const CInfo& ptrSecond)
	{
		return ptrFirst->compare(*ptrSecond) == -1;
	});
}

void CarPark::print()
{
	std::cout << "\n\t- " << name << " -\n";
	for (const CInfo& ptr : list_of_cars)
		ptr->print();
}