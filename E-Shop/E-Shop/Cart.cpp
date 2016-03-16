#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include "Product.h"
#include "Cart.h"

using namespace std;

Cart::Cart(){}

Cart::Cart(int id, int quantity)
{
	this->id = id;
	this->quantity = quantity;
}

Cart::Cart(string strCart)
{
	istringstream issin(strCart);
	string split[2];
	int i = 0;

	while (getline(issin, split[i], '|')) {
		i++;
	}

	this->id = stoi(split[0]);
	this->quantity = stoi(split[1]);
}

void Cart::setId(int id)
{
	this->id = id;
}

int Cart::getId() {
	return id;
}

void Cart::setQuantity(int quantity)
{
	this->quantity = quantity;
}

int Cart::getQuantity() {
	return quantity;
}

void Cart::addProduct(Product p)
{
	products.push_back(p);
}

vector<Product> Cart::getProducts()
{
	return products;
}

void Cart::save(ofstream & outfile)
{
	outfile << this->toString() << endl;
}

string Cart::toString()
{
	string str = to_string(id) + "|" + to_string(quantity);
	return str;
}


