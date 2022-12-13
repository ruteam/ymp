#pragma once
#include <iostream>
#include <string>

class Car
{
private:
	std::string brand;
	std::string state_number;
	std::string surname;
	std::string fname;
	std::string patronymic;
public:
	Car();
	Car(std::string brand, std::string state_number, std::string surname, std::string fname, std::string patronymic);
	
	std::string get_brand() const;
	std::string get_state_number() const;
	std::string get_fio() const;

	void set_brand(std::string _brand);
	void set_state_number(std::string _state_number);
	void set_fio(std::string _surname, std::string _fname, std::string _patronymic);
	
	int compare(const Car& tmp) const;
	virtual void print();
};

