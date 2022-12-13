#pragma once
#include <vector>
#include "car.h"
#include <list>
#include <memory> 
#include <algorithm>
#include <functional>

using CInfo = std::unique_ptr<Car>;

class CarPark
{
private:
	std::string name;
	std::list<CInfo> list_of_cars;
public:
	CarPark();
	CarPark(const std::string& name);

	std::string get_name() const;

	void set_name(const std::string& _name);

	void adding_by_pointer(CInfo ptrCar);
	void add_to_head(CInfo ptrCar);
	void add_to_tail(CInfo ptrCar);

	void erase_if(std::function<bool(const CInfo&)> function);
	void sort();
	void print();
};