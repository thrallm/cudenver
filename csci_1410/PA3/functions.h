#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <iostream>
#include <cstdlib>
#include <vector>
#include <fstream>
#include "vehicle.h"
using namespace std;

// prototypes
void displayMenu();
bool checkValidInventory(vector<Vehicle> &vlist);
bool checkAffirm();
void displayInventory(vector<Vehicle> &vlist);
void addVehicle(vector<Vehicle> &vlist);
void updateVehicle(vector<Vehicle> &vlist);
void deleteVehicle(vector<Vehicle> &vlist);
void sortInventory(vector<Vehicle> &vlist);
void searchInventory(vector<Vehicle> &vlist);
void readInventoryFile(vector<Vehicle> &vlist);
void writeInventoryFile(vector<Vehicle> &vlist);
Vehicle getValidVehicle(vector<Vehicle> &vlist);
int getValidVehicleIndex(vector<Vehicle> &vlist);
// overloaded stream operator prototypes
ostream &operator << (ostream &, const Vehicle &);
istream &operator >> (istream &, Vehicle &);

//*********************************************
// Display the menu for the dealership UI.
//*********************************************
void displayMenu() {
	cout << "+++++++++++++++++++++++++++++++++++++++++++++\n";
	cout << "Welcome to the dealership.                  +\n";
	cout << "Please pick from the menu options below     +\n";
	cout << "1. Display Inventory                        +\n";
	cout << "2. Add a vehicle                            +\n";
	cout << "3. Update a vehicle                         +\n";
	cout << "4. Delete a vehicle                         +\n";
	cout << "5. Sort inventory by VIN                    +\n";
	cout << "6. Search inventory by Make                 +\n";
	cout << "7. Read inventory from file                 +\n";
	cout << "8. Write inventory to file and exit         +\n";
	cout << "+++++++++++++++++++++++++++++++++++++++++++++\n";
}

//*********************************************
// Display the Inventory.
//*********************************************
void displayInventory(vector<Vehicle> &vlist) {
	if (!checkValidInventory(vlist)) {
		return;
	}
	cout << "Current Inventory\n";
	cout << "==============================\n";
	// Help with size_t http://stackoverflow.com/questions/7443222
	for (size_t i = 0; i < vlist.size(); i++) {
		cout << "Vehicle number:\t" << i + 1 << endl;
		cout << "VIN:\t" << vlist[i].getVin() << endl;
		cout << "Make:\t" << vlist[i].getMake() << endl;
		cout << "Model:\t" << vlist[i].getModel() << endl;
		cout << "Year:\t" << vlist[i].getYear() << endl;
		cout << "Price:\t" << vlist[i].getPrice() << endl;
		// TODO: display dealer info.
		cout << "-------------------------------\n";
	}
}
//*********************************************
// Add a vehicle.
//*********************************************
void addVehicle(vector<Vehicle> &vlist) {
	string temp;
	Vehicle v; // maybe should use a pointer here.
	cin >> v; // overloaded insertion operator;
	vlist.push_back(v); // does this mean v is duplicate storage?
	cout << vlist.size() << endl;
}

//*********************************************
// Update a vehicle.
//*********************************************
void updateVehicle(vector<Vehicle> &vlist) {
	if (!checkValidInventory(vlist)) {
		return;
	}
	Vehicle v = getValidVehicle(vlist);
	cout << v.getMake() << endl; // testing
	// Display a menu of the fields which they can update
	// Get which field to update for the selected item
	// Switch statement to collect input and call the
	// appropriate Vehicle mutator.
}

//*********************************************
// Delete a vehicle.
//*********************************************
void deleteVehicle(vector<Vehicle> &vlist) {
	if (!checkValidInventory(vlist)) {
		return;
	}
	int i = getValidVehicleIndex(vlist);
	cout << "This will remove vehicle " << i;
	if (checkAffirm()) {
		// adjust for 1 index menu system
		vlist.erase(vlist.begin() + i - 1);
	}
}

//*********************************************
// Sort the inventory.
//*********************************************
void sortInventory(vector<Vehicle> &vlist) {
	cout << "Sorting inventory...\n";
	// TODO: Implement selection sort for the 
	// vlist. Will need a temp Vehicle which
	// could be a pointer to a Vehicle.
}

//*********************************************
// Search the inventory.
//*********************************************
void searchInventory(vector<Vehicle> &vlist) {
	// Call sort on the Vehicle vector.
	sortInventory(vlist);
	cout << "Searching inventory...\n";
	// TODO: Implement Binary Search on vlist.
}

//*********************************************
// Read inventory from a file.
//
// The inventory file is a file of 
// the Vehicle vector.
//*********************************************
void readInventoryFile(vector<Vehicle> &vlist) {
	cout << "Reading inventory file...\n";
	ifstream inf;
	inf.open("inventory.dat");
	Vehicle *vPtr = nullptr;
	vPtr = new Vehicle;
	// Use peek to prevent reading a final empty line 
	// and making a blank vehicle from it. Help from 
	// http://stackoverflow.com/questions/6283632
	char c = inf.peek(); 
	while (c != EOF) {
		inf >> *vPtr;
		vlist.push_back(*vPtr);
		c = inf.peek();
	}
	inf.close();
	delete vPtr;
}

//*********************************************
// Write inventory to a file.
//
// Write out data of Vehicle vector
// to inventory.dat using the << operator
// which is overloaded for Vehicle objects.
//*********************************************
void writeInventoryFile(vector<Vehicle> &vlist) {
	cout << "Writing inventory file...\n";
	ofstream outf;
	outf.open("inventory.dat");
	// http://stackoverflow.com/questions/7443222
	for (size_t i = 0; i < vlist.size(); i++) {
		outf << vlist[i];
	}
	outf.close();
}

//*********************************************
// Check if inventory is valid
//*********************************************
bool checkValidInventory(vector<Vehicle> &vlist) {
	bool valid;
	valid = static_cast<bool>(vlist.size());
	if (!valid)
		cout << "Inventory is empty!\n";
	return valid;
}

//*********************************************
// Get a valid vehicle from the inventory
//*********************************************
Vehicle getValidVehicle(vector<Vehicle> &vlist) {
	int choice = getValidVehicleIndex(vlist);
	Vehicle v = vlist.at(choice - 1); // adjust for 1 indexed menu.
	return v;
}

//*********************************************
// Get a valid vehicle index from the inventory
//*********************************************
int getValidVehicleIndex(vector<Vehicle> &vlist) {
	string temp;
	int choice = 0;
	cout << "Please pick the vehicle...\n";
	// display inventory list
	displayInventory(vlist);
	// let the user pick from the list
	getline(cin, temp);
	choice = atoi(temp.c_str());
	// verify input is valid
	while (choice > vlist.size() || choice <= 0) {
		cout << "Invalid choice, please pick again.\n";
		getline(cin, temp);
		choice = atoi(temp.c_str());
	}
	return choice;
}

//*********************************************
// Overload the extraction operator to extract a Vehicle.
// This calls public member functions, so it doesn't 
// need to be a friend.
//*********************************************
ostream &operator << (ostream &strm, const Vehicle &obj) {
	strm << obj.getVin() << endl;
	strm << obj.getMake() << endl;
	strm << obj.getModel() << endl;
	strm << obj.getYear() << endl;
	strm << obj.getPrice() << endl;
	return strm;
}

//*********************************************
// Overload the insertion operator to insert to a Vehicle.
// If used with cin, then it gets lines from the user.
// If used with ifstream, then it gets a line at a time.
// As long as the ifstream is formatted correctly 
// (vin, make, model, year, price), it will iterate the file.
// This was helpful:
// http://stackoverflow.com/questions/15377179
//*********************************************
istream &operator >> (istream &strm, Vehicle &v) {
	string temp;
	cout << "Adding vehicle...\n";
	cout << "Please enter the VIN:\n";
	getline(strm, temp);
	v.setVin(temp);
	cout << "Please enter the make:\n";
	getline(strm, temp);
	v.setMake(temp);
	cout << "Please enter the model:\n";
	getline(strm, temp);
	v.setModel(temp);
	cout << "Please enter the year:\n";
	getline(strm, temp);
	v.setYear(atoi(temp.c_str()));
	cout << "Please enter the price:\n";
	getline(strm, temp);
	v.setPrice(atof(temp.c_str()));
	return strm;
}

//*********************************************
// UI to verify a user wants to continue.
//*********************************************
bool checkAffirm() {
	char choice;
	cout << " are you sure (Y|N)?\n";
	cin.get(choice);
	cin.ignore();
	if (toupper(choice) == 'Y')
		return true;
	else 
		return false;
}
#endif
