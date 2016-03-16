#ifndef INDIVIDUAL_H
#define INDIVIDUAL_H
#include "Client.h"

class Individual :
	public Client
{
public:
	Individual();
	Individual(string fname, string lname, string idNum, int afm, int phoneNum, string address);
	Individual(string strId);
	void setName(string fname, string lname);
	string getFname();
	string getLname();

	void setId(string idNum);
	string getId();

	void save(ofstream &outfile);
	string toString();
private:
	string fname;
	string lname;
	string idNum;
};

#endif // !INDIVIDUAL_H


