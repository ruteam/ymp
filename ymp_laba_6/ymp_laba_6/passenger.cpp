#include "passenger.h"

Passenger::Passenger()
	: type_of_body(""), model(""), color(""), Car()
{}

Passenger::Passenger(const std::string& type_of_body, const std::string& model, const std::string& color, const std::string& brand, const std::string& state_number, const std::string& surname, const std::string& fname, const std::string& patronymic)
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

void Passenger::set_type_of_body(const std::string& _type_of_body)
{
	type_of_body = _type_of_body;
}

void Passenger::set_model(const std::string& _model)
{
	model = _model;
}

void Passenger::set_color(const std::string& _color)
{
	color = _color;
}

void Passenger::print()
{
	std::cout << "\n[======[ Passenger ]======]\n";
	Car::print();
	std::cout << type_of_body << '\n' << model << '\n' << color << '\n';
}
