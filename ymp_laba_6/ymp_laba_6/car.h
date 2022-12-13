#pragma once
#include <iostream>
#include <string>

using namespace std;

class Car
{
private:
	string brand;
	string state_number;
	string surname;
	string firstname;
	string patronymic;
public:
	Car();
	Car(string brand, string state_number, string surname, string firstname, string patronymic);
	
	string get_brand() const;
	string get_state_number() const;
	string get_fio() const;

	void set_brand(string _brand);
	void set_state_number(string _state_number);
	void set_fio(string _surname, string _firstname, string _patronymic);
	
	int compare(const Car& tmp) const;
	virtual void print();
};

