#pragma once
#include "carpark.h"

CarPark::CarPark()
	: name("") 
{}

CarPark::CarPark(string name)
	: name(name) 
{}

string CarPark::get_name() const
{
	return name;
}

void CarPark::set_name(string _name)
{
	name = _name;
}

void CarPark::adding_by_pointer(PInfo ptr)
{
	list<PInfo>::iterator beg = list_of_cars.begin();
	while (beg != list_of_cars.end() && (*beg)->compare(*ptr) == -1)
		++beg;
	list_of_cars.insert(beg, move(ptr));
}

void CarPark::erase_if(function<bool(const PInfo&)> function)
{
	list_of_cars.erase(remove_if(list_of_cars.begin(), list_of_cars.end(), function), list_of_cars.end());
}

void CarPark::sort()
{
	list_of_cars.sort([](const PInfo& ptrFirst, const PInfo& ptrSecond)
	{
		return ptrFirst->compare(*ptrSecond) == -1;
	});
}

void CarPark::print()
{
	cout << "\n\t- " << name << " -\n";
	for (const PInfo& ptr : list_of_cars)
		ptr->print();
}