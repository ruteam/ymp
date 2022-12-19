#pragma once
#include "carpark.h"

CarPark::CarPark()
	: name("unnamed") 
{}

CarPark::CarPark(string name)
	: name(name) 
{}

CarPark::~CarPark()
{
	name.clear();
}

string CarPark::get_name() const
{
	return name;
}

void CarPark::set_name(string _name)
{
	name = _name;
}

void CarPark::insert(PPtr ptr)
{
	list<PPtr>::iterator beg = list_of_cars.begin();
	while (beg != list_of_cars.end() && (*beg)->compare(*ptr) == -1)
		++beg;
	list_of_cars.insert(beg, move(ptr));
}

void CarPark::remove(function<bool(const PPtr&)> _Pred)
{
	list_of_cars.remove_if(_Pred);
}

void CarPark::sort()
{
	list_of_cars.sort([](const PPtr& ptrFirst, const PPtr& ptrSecond)
	{
		return ptrFirst->compare(*ptrSecond) == -1;
	});
}

void CarPark::print()
{
	cout << "\n\t- " << name << " -\n";
	for (const PPtr& ptr : list_of_cars)
		ptr->print();
}