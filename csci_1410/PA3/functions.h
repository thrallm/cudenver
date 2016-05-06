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
void sortInventoryByVin(vector<Vehicle> &vlist);
void searchInventoryByMake(vector<Vehicle> &vlist);
void readInventoryFile(vector<Vehicle> &vlist);
void writeInventoryFile(vector<Vehicle> &vlist);
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
		cout << "Vehicle Number:\t" << i + 1 << endl;
		vlist[i].print();
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
	//cout << vlist.size() << endl;
}

//*********************************************
// Update a vehicle.
//*********************************************
void updateVehicle(vector<Vehicle> &vlist) {
	char choice;
	string temp;
	if (!checkValidInventory(vlist)) {
		return;
	}
	int i = getValidVehicleIndex(vlist);
	Vehicle v = vlist.at(i - 1); // adjust for 1 indexed menu.
	cout << "You picked " << v.getMake() << " : " << v.getModel() << endl;
	// Display a menu of the fields which they can update
	// Get which field to update for the selected item
	// Switch statement to collect input and call the
	// appropriate Vehicle mutator.
	cout << "Which element do you want to update?\n";
	cout << "1. VIN\n2. Make\n3. Model\n4. Year\n5. Price\n6. DealerNum\n";
	cin.get(choice);
	cin.ignore();
	switch (choice) {
		case '1':
			cout << "What is the new VIN?\n";
			getline(cin, temp);
			v.setVin(atoi(temp.c_str()));
			break;
		case '2':
			cout << "What is the new make?\n";
			getline(cin, temp);
			v.setMake(temp);
			break;
		case '3':
			cout << "What is the new model?\n";
			getline(cin, temp);
			v.setModel(temp);
			break;
		case '4':
			cout << "What is the new year?\n";
			getline(cin, temp);
			v.setYear(atoi(temp.c_str()));
			break;
		case '5':
			cout << "What is the new price?\n";
			getline(cin, temp);
			v.setPrice(atof(temp.c_str()));
			break;
		case '6':
			cout << "What is the new dealer number?\n";
			getline(cin, temp);
			v.dealerPtr->setDealerNum(atoi(temp.c_str()));
			break;
		default:
			cout << "invalid choice!\n";
	}
	// replace the vehicle in vlist at the appropriate index
	vlist[i - 1] = v;
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
void sortInventoryByVin(vector<Vehicle> &vlist) {
	if (!checkValidInventory(vlist)) {
		return;
	}
	cout << "Sorting inventory...\n";
	int start, minIndex;
	Vehicle minV;
	// Selection Sort
	for (start = 0; start < (vlist.size() - 1); start++) {
		minIndex = start;
		minV = vlist[start];
		for (int i = start + 1; i < vlist.size(); i++) {
			if (vlist[i].getVin() < minV.getVin()) {
				minV = vlist[i];
				minIndex = i;
			}
		}
		vlist[minIndex] = vlist[start];
		vlist[start] = minV;
	}
}

//*********************************************
// Search the inventory by Make and 
// return the index of the first match.
//*********************************************
void searchInventoryByMake(vector<Vehicle> &vlist) {
	if (!checkValidInventory(vlist)) {
		return;
	}
	string searchMake;
	bool found = false;
	int foundIndex = -1;
	cout << "Please enter the Make of the Vehicle to search for:\n";
	getline(cin, searchMake);
	// Linear Search (short list, and vector is not sorted by Make)
	// add !found so it stops on the first vehicle it finds.
	for (int i = 0; (i < vlist.size()) && !found; i++) {
		if (vlist[i].getMake() == searchMake) {
			found = true;
			foundIndex = i;
		}
	}
	if (found) {
		cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++\n";
		cout << "Vehicle found! It is Vehicle number ";
		cout << foundIndex + 1 << endl;
		cout << "Vehicle info:\n";
		vlist[foundIndex].print();
		cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++\n";
	}
	else {
		cout << "---------------------------------------------------\n";
		cout << "Sorry, no vehicle of that make found.\n";
		cout << "---------------------------------------------------\n";
	}
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
	outf.open("inventory.out");
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
ostream &operator << (ostream &strm, const Vehicle &v) {
	strm << v.getVin() << endl;
	strm << v.getMake() << endl;
	strm << v.getModel() << endl;
	strm << v.getYear() << endl;
	strm << v.getPrice() << endl;
	strm << v.dealerPtr->getDealerNum() << endl;
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
	int t;
	cout << "Adding vehicle...\n";
	cout << "Please enter the VIN:\n";
	getline(strm, temp);
	v.setVin(atoi(temp.c_str()));
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
	cout << "Please enter the dealer number:\n";
	getline(strm, temp);
	cout << temp;
	t = atoi(temp.c_str());
	v.dealerPtr->setDealerNum(t);
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
