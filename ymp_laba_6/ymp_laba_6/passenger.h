#pragma once
#include "car.h"

class Passenger: public Car
{
private:
	string type_of_body;
	string model;
	string color;
public:
	Passenger();
	Passenger(string type_of_body, string model, string color, string brand, string state_number, string surname, string firstname, string patronymic);

	string get_type_of_body() const;
	string get_model() const;
	string get_color() const;

	void set_type_of_body(string _type_of_body);
	void set_model(string _model);
	void set_color(string _color);

	void print();
};

