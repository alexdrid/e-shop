#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include "Product.h"
#include "Television.h"

Television::Television(){}

Television::Television(string model, string manufacturer, double price, bool availability, double size, bool play3D)
{
	this->manufacturer = manufacturer;
	this->model = model;
	this->price = price;
	this->availability = availability;
	this->size = size;
	this->play3D = play3D;
}

Television::Television(string strTV)
{
	istringstream issin(strTV);
	string split[7];
	int i = 0;

	while (getline(issin, split[i], '|')) {
		i++;
	}
	if (split[0] == "tv") {
		this->manufacturer = split[1];
		this->model = split[2];
		this->size = stod(split[3]);
		if (this->play3D = true)
			bool_cast_3D(true) = split[4];
		else
			bool_cast_3D(false) = split[4];
		this->price = stod(split[5]);
		if (this->availability == true)
			bool_cast_availability(true) = split[6];
		else
			bool_cast_availability(false) = split[6];
	}
	
}

void Television::setSize(double size)
{
	this->size = size;
}


double Television::getSize()
{
	return size;
}

void Television::set3D(bool play3D)
{
	this->play3D = play3D;
}

bool Television::get3D()
{
	return play3D;
}

void Television::save(ofstream & outfile)
{
	outfile << this->toString() << endl;
}

string Television::toString()
{
	string str = "tv" + '|' + manufacturer + '|' + model + '|' + to_string(size) + '|' + bool_cast_3D(play3D) + '|' + to_string(price) + '|' + bool_cast_availability(availability);
	return str;
}

string Television::bool_cast_availability(bool availability)
{
	ostringstream ss;
	ss << boolalpha << availability;
	return ss.str();
}

string Television::bool_cast_3D(bool play3D)
{
	ostringstream ss;
	ss << boolalpha << play3D;
	return ss.str();
}
