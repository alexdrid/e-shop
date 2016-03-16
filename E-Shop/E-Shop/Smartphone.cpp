#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include "Smartphone.h"
#include "Product.h"

using namespace std;

Smartphone::Smartphone(){}

Smartphone::Smartphone(string model, string manufacturer, double price, bool availability,bool vid3DCapture , double srcSize, double batDuration)
{
	this->manufacturer = manufacturer;
	this->model = model;
	this->price = price;
	this->availability = availability;
	this->scrSize = srcSize;
	this->batDutation = batDuration;
	this->vid3Dcapture = vid3DCapture;
	
}

Smartphone::Smartphone(string strSP)
{
	istringstream issin(strSP);
	string split[8];
	int i = 0;

	while (getline(issin, split[i], '|')) {
		i++;
	}
	if (split[0] == "sm") {
		this->manufacturer = split[1];
		this->model = split[2];
		this->scrSize = stod(split[3]);
		this->batDutation = stod(split[4]);
		if (this->vid3Dcapture = true)
			bool_cast_capture(true) = split[5];
		else
			bool_cast_capture(false) = split[5];
		this->price = stod(split[6]);
		if (this->availability == true)
			bool_cast_availability(true) = split[7];
		else
			bool_cast_availability(false) = split[7];
	}
}

void Smartphone::setScreen(double scrSize)
{
	this->scrSize = scrSize;
}

double Smartphone::getScreen()
{
	return scrSize;
}

void Smartphone::setBattery(double batDuration)
{
	this->batDutation = batDuration;
}

double Smartphone::getBattery()
{
	return batDutation;
}

void Smartphone::set3DCapture(bool vid3DCapture)
{
	this->vid3Dcapture = vid3DCapture;
}

bool Smartphone::get3DCapture()
{
	return vid3Dcapture;
}

void Smartphone::save(ofstream & outfile)
{
	outfile << this->toString() << endl;
}

string Smartphone::toString()
{
	
	string str =  "sm" + '|' + manufacturer + '|' + model + '|' + to_string(scrSize)
		+ '|' + to_string(batDutation) + '|' + bool_cast_capture(vid3Dcapture) + '|' + to_string(price)  + '|' + bool_cast_availability(availability);
	return str;
}

string Smartphone::bool_cast_availability(bool availability)
{
	ostringstream ss;
	ss << boolalpha << availability;
	return ss.str();
}

string Smartphone::bool_cast_capture(bool vid3DCapture)
{
	ostringstream ss;
	ss << boolalpha << vid3DCapture;
	return ss.str();
}