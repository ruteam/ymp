#pragma once
#include <vector>
#include "car.h"
#include <list>
#include <memory> 
#include <algorithm>
#include <functional>

using namespace std;
using PInfo = unique_ptr<Car>;

class CarPark
{
private:
	string name;
	list<PInfo> list_of_cars;
public:
	CarPark();
	CarPark(string name);

	string get_name() const;

	void set_name(string _name);

	void adding_by_pointer(PInfo ptr);
	void erase_if(function<bool(const PInfo&)> function);
	void sort();
	void print();
};