#pragma once
#include <vector>
#include "car.h"
#include <list>
#include <functional>

using namespace std;
using PPtr = unique_ptr<Car>;

class CarPark
{
private:
	string name;
	list<PPtr> list_of_cars;
public:
	CarPark();
	CarPark(string name);
	~CarPark();

	string get_name() const;

	void set_name(string _name);

	void insert(PPtr ptr);
	void remove(function<bool(const PPtr&)> _Pred);
	void sort();
	void print();
};