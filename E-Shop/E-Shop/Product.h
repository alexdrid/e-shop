#ifndef PRODUCT_H
#define PRODUCT_H
#include <string>

using namespace std;

class Product
{
public:
	Product();
	Product(string model, string manufacturer, double price, bool availability);
	Product(string strProd);
	void setModel(string model);
	string getModel();

	void setManufacturer(string manufacturer);
	string getManufacturer();

	

	void setPrice(double price);
	double getPrice();

	void setAvailability(bool availability);
	bool getAvailability();
protected:
		string model;
		string manufacturer;
		string description;
		double price;
		bool availability;
};

#endif