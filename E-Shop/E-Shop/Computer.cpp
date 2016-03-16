#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include "Computer.h"
#include "Product.h"

using namespace std;

Computer::Computer(){}

Computer::Computer(string model, string manufacturer, double price, bool availability, double ramSpace, double cpuSpeed, double diskSize, string diskType, string gpuName)
{
	this->manufacturer = manufacturer;
	this->model = model;
	this->price = price;
	this->availability = availability;
	this->ramSpace = ramSpace;
	this->cpuSpeed = cpuSpeed;
	this->diskSize = diskSize;
	this->diskType = diskType;
	this->gpuName = gpuName;
}

Computer::Computer(string strPC)
{
	istringstream issin(strPC);
	string split[9];
	int i = 0;
	while (getline(issin, split[i], '|')) {
		i++;
	}

	if (split[0] == "pc") {
		this->manufacturer = split[1];
		this->model = split[2];
		this->ramSpace = stod(split[3]);
		this->cpuSpeed = stod(split[4]);
		this->diskSize = stod(split[5]);
		this->diskType = split[6];
		this->gpuName = split[7];
		this->price = stod(split[8]);
	}
}


void Computer::setRam(double ramSpace)
{
	this->ramSpace = ramSpace;
}

double Computer::getRam()
{
	return ramSpace;
}

void Computer::setCpu(double cpuSpeed)
{
	this->cpuSpeed = cpuSpeed;
}

double Computer::getCpu()
{
	return cpuSpeed;
}

void Computer::setDisk(double diskSize)
{
	this->diskSize = diskSize;
}

double Computer::getDisk()
{
	return diskSize;
}

void Computer::setDiskType(string diskType)
{
	this->diskType = diskType;
}

string Computer::getDiskType()
{
	return diskType;
}

void Computer::setGpu(string gpuName)
{
	this->gpuName = gpuName;
}

string Computer::getGpu()
{
	return gpuName;
}

void Computer::save(ofstream &outfile)
{
	outfile << this->toString() << endl;
}

string Computer::toString()
{
	string str = "pc" + '|' + manufacturer + '|' +  model +  '|' + to_string(ramSpace) + '|' + to_string(cpuSpeed) + '|' + to_string(diskSize) + '|' + diskType + '|' + gpuName + '|' + to_string(price);
	return str;
}

string Computer::bool_cast(bool availability)
{
	ostringstream ss;
	ss << boolalpha << availability;
	return ss.str();
}
