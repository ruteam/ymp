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
	Passenger(const std::string& type_of_body, const std::string& model, const std::string& color, const std::string& brand, const std::string& state_number, const std::string& surname, const std::string& fname, const std::string& patronymic);

	std::string get_type_of_body() const;
	std::string get_model() const;
	std::string get_color() const;

	void set_type_of_body(const std::string& _type_of_body);
	void set_model(const std::string& _model);
	void set_color(const std::string& _color);

	void print();
};

