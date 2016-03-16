#ifndef CLIENT_H
#define CLIENT_H
#include "User.h"
#include <string>

class Client :
	public User
{
public:
	Client();
	Client(int afm, int phoneNum, string address);

	void setAfm(int afm);
	int getAfm();

	void setPhoneNum(int phoneNum);
	int getPhoneNum();

	void setAddress(string address);
	string getAddress();

	
protected:
	int afm;
	int phoneNum;
	string address;
};
#endif // !CLIENT_H

