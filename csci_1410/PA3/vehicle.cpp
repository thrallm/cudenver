#include "vehicle.h"

//*********************************************
// Constructor for Dealer class.
//*********************************************
Dealer::Dealer() {
	dealerNum = 0;
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
	VIN = "";
	make = "";
	model = "";
	year = 0;
	price = 0.0;
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
}
//*********************************************
// Accessor for Vehicle.VIN
//*********************************************
string Vehicle::getVin() const {
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
void Vehicle::setVin(string v) {
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
