#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include "Product.h"

using namespace std;

Product::Product(){}

Product::Product(string model, string manufacturer,double price,bool availability) {
	this->model = model;
	this->manufacturer = manufacturer;
	this->price = price;
	this->availability = availability;
}

Product::Product(string strProd)
{
	istringstream issin(strProd);
	string split[2];
	int i = 0;
	while (getline(issin, split[i], '|')) {
		i++;
	}

	this->manufacturer = split[1];
	this->model = split[2];	
}

void Product::setModel(string model)
{
	this->model = model;
}

string Product::getModel()
{
	return model;
}

void Product::setManufacturer(string manufacturer)
{
	this->manufacturer = manufacturer;
}

string Product::getManufacturer()
{
	return manufacturer;
}

void Product::setPrice(double price)
{
	this->price = price;
}

double Product::getPrice()
{
	return price;
}

void Product::setAvailability(bool availability)
{
	this->availability = availability;
}

bool Product::getAvailability()
{
	return availability;
}

