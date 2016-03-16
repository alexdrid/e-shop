#ifndef OREDER_H
#include "Client.h"
#include "Product.h"

using namespace std;

class Order
{
public:
	Order();
	Order(string username,string orderId,string status,double cost,int prodId,int q);
	Order(string strOrder);

	void setUsername(string username);
	string getUsername();

	void setOrder(string orderId);
	string getOrder();

	void setStatus(string status);
	string getStatus();

	void setCost(double cost);
	double getCost();

	void setProdId(int prodId);
	int getProdId();

	void setQuantity(int q);
	int getQuantity();

	void save(ofstream &oitfile);
	string toString();
private:
	string username;
	string orderId;
	string status;
	double cost;
	int prodId;
	int q;
};
#endif // !OREDER_H



