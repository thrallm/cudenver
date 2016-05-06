#include "vehicle.h"
#include <iostream>
#include <iomanip>

//*********************************************
// Constructor for Dealer class.
//*********************************************
Dealer::Dealer() {
	dealerNum = -1;
}
//*********************************************
// Accessor for Dealer.dealerNum
//*********************************************
int Dealer::getDealerNum() const {
	return dealerNum;
}
//*********************************************
// Mutator for Dealer.dealerNum
//*********************************************
void Dealer::setDealerNum(int d) {
	dealerNum = d;
}

//*********************************************
// Constructor for Vehicle class.
//*********************************************
Vehicle::Vehicle() {
	VIN = -1;
	make = "";
	model = "";
	year = 0;
	price = 0.0;
	dealerPtr = new Dealer;
}
//*********************************************
// Constructor for Vehicle class with params.
//*********************************************
Vehicle::Vehicle(int v, string ma, string mo, int y, double p) {
	VIN = v;
	make = ma;
	model = mo;
	year = y;
	price = p;
	dealerPtr = new Dealer;
}
//*********************************************
// Accessor for Vehicle.VIN
//*********************************************
int Vehicle::getVin() const {
	return VIN;
}
//*********************************************
// Accessor for Vehicle.make
//*********************************************
string Vehicle::getMake() const {
	return make;
}
//*********************************************
// Accessor for Vehicle.model
//*********************************************
string Vehicle::getModel() const {
	return model;
}
//*********************************************
// Accessor for Vehicle.year
//*********************************************
int Vehicle::getYear() const {
	return year;
}
//*********************************************
// Accessor for Vehicle.price
//*********************************************
double Vehicle::getPrice() const {
	return price;
}
//*********************************************
// Mutator for Vehicle.VIN
//*********************************************
void Vehicle::setVin(int v) {
	VIN = v;
}
//*********************************************
// Mutator for Vehicle.make
//*********************************************
void Vehicle::setMake(string m) {
	make = m;
}
//*********************************************
// Mutator for Vehicle.model
//*********************************************
void Vehicle::setModel(string m) {
	model = m;
}
//*********************************************
// Mutator for Vehicle.year
//*********************************************
void Vehicle::setYear(int y) {
	year = y;
}
//*********************************************
// Mutator for Vehicle.price
//*********************************************
void Vehicle::setPrice(double p) {
	price = p;
}

void Vehicle::print() {
	cout << "VIN:\t" << VIN << endl;
	cout << "Make:\t" << make << endl;
	cout << "Model:\t" << model << endl;
	cout << "Year:\t" << year << endl;
	cout << "Price:\t$" << fixed << setprecision(2) << price << endl;
	cout << "Dealer Number:\t" << dealerPtr->getDealerNum() << endl;
}
