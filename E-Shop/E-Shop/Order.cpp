#include <iostream>
#include <fstream>
#include<sstream>
#include "Order.h"

using namespace std;

Order::Order(){}

Order::Order(string username, string orderId, string status, double cost, int prodId, int q)
{
	this->username = username;
	this->orderId = orderId;
	this->status = status;
	this->cost = cost;
	this->prodId = prodId;
	this->q = q;
}

Order::Order(string strOrder)
{
	istringstream issin(strOrder);
	string split[6];
	int i = 0;
	while (getline(issin, split[i], '|')) {
		i++;
	}

	this->username = split[0];
	this->orderId = split[1];
	this->status = split[2];
	this->cost = stod(split[3]);
	this->prodId = stoi(split[4]);
	this->q = stoi(split[5]);
}

void Order::setUsername(string username)
{
	this->username = username;
}

string Order::getUsername()
{
	return username;
}

void Order::setOrder(string orderId)
{
	this->orderId = orderId;
}

string Order::getOrder()
{
	return orderId;
}

void Order::setStatus(string status)
{
	this->status = status;
}

string Order::getStatus()
{
	return status;
}

void Order::setCost(double cost)
{
	this->cost = cost;
}

double Order::getCost()
{
	return cost;
}

void Order::setProdId(int prodId)
{
	this->prodId = prodId;
}

int Order::getProdId()
{
	return prodId;
}

void Order::setQuantity(int q)
{
	this->q = q;
}

int Order::getQuantity()
{
	return q;
}

void Order::save(ofstream & outfile)
{
	outfile << this->toString() << endl;
}

string Order :: toString() {
	string str = username + "|" + orderId + "|" + to_string(prodId) + "|" + to_string(q) + "|" + status + "|" + to_string(cost);
	return str;
}




