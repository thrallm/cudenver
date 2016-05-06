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
	int VIN;
	string make;
	string model;
	int year;
	double price;
public:
	// public variables
	Dealer* dealerPtr;
	// constructors
	Vehicle();
	Vehicle(int v, string ma, string mo, int y, double p);
	// accessors
	int getVin() const;
	string getMake() const;
	string getModel() const;
	int getYear() const;
	double getPrice() const;
	// mutators
	void setVin(int v);
	void setMake(string m);
	void setModel(string m);
	void setYear(int y);
	void setPrice(double p);
	// other
	void print();
	//friends
	friend ostream &operator << (ostream &strm, const Vehicle &obj);
	friend istream &operator >> (istream &strm, Vehicle &v);
};
#endif
