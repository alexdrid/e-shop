#ifndef COMPUTERS_H
#define COMPUTERS_H
#include <string>
#include "Product.h"

using namespace std;

class Computer :
	public Product
{
public:
	Computer();
	Computer(string model, string manufacturer, double price, bool availability, double ramSpace, double cpuSpeed, double diskSize, string diskType, string gpuName);
	Computer(string strPC);

	void setRam(double ramSpace);
	double getRam();

	void setCpu(double cpuSpeed);
	double getCpu();

	void setDisk(double diskSize);
	double getDisk();

	void setDiskType(string diskType);
	string getDiskType();

	void setGpu(string diskType);
	string getGpu();

	void save(ofstream &outfile);
	string toString();
	
	string bool_cast(bool avalability);
private:
	double ramSpace;
	double cpuSpeed;
	double diskSize;
	string diskType;
	string gpuName;
};
#endif

