#ifndef SMARTPHONES_H
#define SMARTPHONES_H
#include <string>
#include "Product.h"

using namespace std;

class Smartphone :
	public Product
{
public:
	Smartphone();
	Smartphone(string model, string manufacturer, double price, bool availability, bool vid3DCapture, double srcSize, double batDuration);
	Smartphone(string strSP);

	void setScreen(double scrSize);
	double getScreen();

	void setBattery(double batDuration);
	double getBattery();

	void set3DCapture(bool vid3DCapture);
	bool get3DCapture();

	void save(ofstream &outfile);
	string toString();

	string bool_cast_availability(bool availability);
	string bool_cast_capture(bool vid3DCapture);
	

private:
	double scrSize;
	double batDutation;
	bool vid3Dcapture;
};

#endif // !SMARTPHONES_H





