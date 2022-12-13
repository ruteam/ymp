#pragma once
#include "car.h"

class Passenger: public Car
{
private:
	std::string type_of_body;
	std::string model;
	std::string color;
public:
	Passenger();
	Passenger(std::string type_of_body, std::string model, std::string color, std::string brand, std::string state_number, std::string surname, std::string fname, std::string patronymic);

	std::string get_type_of_body() const;
	std::string get_model() const;
	std::string get_color() const;

	void set_type_of_body(std::string _type_of_body);
	void set_model(std::string _model);
	void set_color(std::string _color);

	void print();
};

