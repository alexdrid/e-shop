#ifndef USER_H
#define USER_H
#include <string>

using namespace std;

class User
{
public:
	User();
	User(string user, string pass);
	User(string strUser);

	void setUser(string user);
	string getUser();
	
	void setPass(string pass);
	string getPass();

	

	void save(ofstream &outfile);

	string toString();


protected:
	string user;
	string pass;
};
#endif 

