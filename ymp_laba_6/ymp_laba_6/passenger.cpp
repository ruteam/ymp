#include "passenger.h"

Passenger::Passenger()
	: type_of_body(""), model(""), color(""), Car()
{}

Passenger::Passenger(string type_of_body, string model, string color, string brand, string state_number, string surname, string firstname, string patronymic)
	: type_of_body(type_of_body), model(model), color(color), Car(brand, state_number, surname, firstname, patronymic)
{}

string Passenger::get_type_of_body() const
{
	return type_of_body;
}

string Passenger::get_model() const
{
	return model;
}

string Passenger::get_color() const
{
	return color;
}

void Passenger::set_type_of_body(string _type_of_body)
{
	type_of_body = _type_of_body;
}

void Passenger::set_model(string _model)
{
	model = _model;
}

void Passenger::set_color(string _color)
{
	color = _color;
}

void Passenger::print()
{
	cout << "\n\t| Passenger |\n";
	Car::print();
	cout << type_of_body << '\n' << model << '\n' << color << '\n';
}
