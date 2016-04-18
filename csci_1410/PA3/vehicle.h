#ifndef VEHICLE_H
#define VEHICLE_H

#include <string>
using namespace std;

class Dealer {
private:
	int dealerNum;
public:
	// constructor
	Dealer(); 
	// accessors
	int getDealerNum() const;
	// mutators
	void setDealerNum(int d);
};

class Vehicle {
private:
	string VIN;
	string make;
	string model;
	int year;
	double price;
	Dealer dealer; // this needs to be a pointer
public:
	// constructors
	Vehicle();
	Vehicle(int v, string ma, string mo, int y, double p);
	// accessors
	string getVin() const;
	string getMake() const;
	string getModel() const;
	int getYear() const;
	double getPrice() const;
	// mutators
	void setVin(string v);
	void setMake(string m);
	void setModel(string m);
	void setYear(int y);
	void setPrice(double p);
};
#endif
