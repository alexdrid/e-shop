#ifndef TELEVISION_H
#define TELEVISION_H
#include <string>
#include "Product.h"

class Television :
	public Product
{
public:
	Television();
	Television(string model, string manufacturer, double price, bool availability,double size,bool play3D);
	Television(string strTV);

	void setSize(double size);
	double getSize();
	
	void set3D(bool play3D);
	bool get3D();

	void save(ofstream &outfile);
	string toString();

	string bool_cast_availability(bool availability);
	string bool_cast_3D(bool play3D);
private:
	double size;
	bool play3D;
};


#endif // !TELEVISIONS_H

