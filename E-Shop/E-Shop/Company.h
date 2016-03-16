#ifndef COMPANY_H
#define COMPANY_H
#include "Client.h"

class Company :
	public Client
{
public:
	Company();
	Company(string companyName, string contactFname, string contactLname, int discount, int faxNum, int afm, int phoneNum, string address);
	Company(string strCom);

	void setCompanyName(string companyName);
	string getCompanyName();

	void setName(string contactFname, string contactLname);
	string getFname();
	string getLname();

	void setDiscout(int discount);
	int getDiscount();

	void setFax(int faxNum);
	int getFax();

	void save(ofstream &outfile);
	string toString();
private:
	string companyName;
	string contactFname;
	string contactLname;
	int discount;
	int faxNum;
};

#endif // !COMPANY_H



