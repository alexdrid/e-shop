#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include "Client.h"

Client::Client(){}

Client::Client(int afm, int phoneNum, string address)
{
	this->afm = afm;
	this->phoneNum = phoneNum;
	this->address = address;
}

void Client::setAfm(int afm)
{
	this->afm = afm;
}

int Client::getAfm()
{
	return afm;
}

void Client::setPhoneNum(int phoneNum)
{
	this->phoneNum = phoneNum;
}

int Client::getPhoneNum()
{
	return phoneNum;
}

void Client::setAddress(string address)
{
	this->address = address;
}

string Client::getAddress()
{
	return address;
}

