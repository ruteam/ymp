#include "passenger.h"

Passenger::Passenger()
	: type_of_body(""), model(""), color(""), Car()
{}

Passenger::Passenger(std::string type_of_body, std::string model, std::string color, std::string brand, std::string state_number, std::string surname, std::string fname, std::string patronymic)
	: type_of_body(type_of_body), model(model), color(color), Car(brand, state_number, surname, fname, patronymic)
{}

std::string Passenger::get_type_of_body() const
{
	return type_of_body;
}

std::string Passenger::get_model() const
{
	return model;
}

std::string Passenger::get_color() const
{
	return color;
}

void Passenger::set_type_of_body(std::string _type_of_body)
{
	type_of_body = _type_of_body;
}

void Passenger::set_model(std::string _model)
{
	model = _model;
}

void Passenger::set_color(std::string _color)
{
	color = _color;
}

void Passenger::print()
{
	std::cout << "\n\t| Passenger |\n";
	Car::print();
	std::cout << type_of_body << '\n' << model << '\n' << color << '\n';
}
