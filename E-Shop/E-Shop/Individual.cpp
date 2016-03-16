#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include "User.h"
#include "Client.h"
#include "Individual.h"


Individual::Individual(){}

Individual::Individual(string fname, string lname, string idNum, int afm, int phoneNum, string address)
{
	this->fname = fname;
	this->lname = lname;
	this->idNum = idNum;
	this->afm = afm;
	this->phoneNum = phoneNum;
	this->address = address;
}

Individual::Individual(string strId)
{
	istringstream issin(strId);
	string split[9];
	int i = 0;
	if (split[0] == "id") {
		this->user = split[1];
		this->pass = split[2];
		this->fname = split[3];
		this->lname = split[4];
		this->idNum = stoi(split[5]);
		this->afm = stoi(split[6]);
		this->phoneNum = stoi(split[7]);
		this->address = split[8];
	}
}

void Individual::setName(string fname, string lname)
{
	this->fname = fname;
	this->lname = lname;
}

string Individual::getFname()
{
	return fname;
}

string Individual::getLname()
{
	return lname;
}

void Individual::setId(string idNum)
{
	this->idNum = idNum;
}

string Individual::getId()
{
	return idNum;
}

void Individual::save(ofstream & outfile)
{
	outfile << this->toString() << endl;
}

string Individual::toString()
{
	string str = "ind" + '|' + user + '|' + pass + '|' + fname + '|' + lname + '|' + idNum + '|' + to_string(afm) + '|' + to_string(phoneNum) + '|' + address;
	return str;
}

