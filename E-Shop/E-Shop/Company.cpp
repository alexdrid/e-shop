#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include "User.h"
#include "Client.h"
#include "Company.h"

Company::Company(){}

Company::Company(string companyName, string contactFname, string contactLname, int discount, int faxNum, int afm, int phoneNum, string address)
{
	this->companyName = companyName;
	this->contactFname = contactFname;
	this->contactLname = contactLname;
	this->discount = discount;
	this->faxNum = faxNum;
}

Company::Company(string strCom)
{
	istringstream issin(strCom);
	string split[11];
	int i = 0;
	if (split[0] == "com") {
		this->user = split[1];
		this->pass = split[2];
		this->companyName = split[3];
		this->contactFname = split[4];
		this->contactLname = split[5];
		this->discount = stoi(split[6]);
		this->faxNum = stoi(split[7]);
		this->afm = stoi(split[8]);
		this->phoneNum = stoi(split[9]);
		this->address = split[10];
	}
}

void Company::setCompanyName(string companyName)
{
	this->companyName = companyName;
}

string Company::getCompanyName()
{
	return companyName;
}

void Company::setName(string contactFname, string contactLname)
{
	this->contactFname = contactFname;
	this->contactLname = contactLname;
}

string Company::getFname()
{
	return contactFname;
}

string Company::getLname()
{
	return contactLname;
}

void Company::setDiscout(int discount)
{
	this->discount = discount;
}

int Company::getDiscount()
{
	return discount;
}

void Company::setFax(int faxNum)
{
	this->faxNum = faxNum;
}

int Company::getFax()
{
	return faxNum;
}

void Company::save(ofstream & outfile)
{
	outfile << this->toString() << endl;
}

string Company::toString()
{
	string str = "com" + '|' + user + '|' + pass + '|' + companyName + '|' + contactFname + '|' + contactLname + '|' + to_string(discount) + '|' + to_string(faxNum) + '|' + to_string(afm) + '|' + to_string(phoneNum) + '|' + address;
	return str;
}


