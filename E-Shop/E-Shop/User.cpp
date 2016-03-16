#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include "User.h"

User::User(){}

User::User(string user, string pass)
{
	this->user = user;
	this->pass = pass;
}

User::User(string strUser)
{
	istringstream issin(strUser);
	string split[2];
	int i = 0;

	while (getline(issin, split[i], '|')) {
		i++;
	}

	this->user = split[0];
	this->pass = split[1];
}

void User::setUser(string user){
	this->user = user;
}

void User::setPass(string pass) {
	this->pass = pass;
}

string User :: getUser() {
	return user;
}

string User::getPass() {
	return pass;
}

void User::save(ofstream & outfile)
{
	outfile << this->toString() << endl;
}

string User::toString()
{
	string str = user + '|' + pass;
	return str;
}
