// Program to run a Vehicle dealership
// class: CSCI 1410
// assignment: PA 3
// author: Mason Thrall, thrallm@ucdenver.edu
// successfully compiled on CSEgrid 
// using -std=c++11 flag on 2016/04/17
//////////////////////////////////////////////////

#include <iostream>
#include <cstdlib>
#include <vector>
#include <fstream>
#include "functions.h"
#include "vehicle.h"
using namespace std;

int main() {
	short choice;
	string temp;
	Dealer d;
	vector<Vehicle> vehicleList(0);
	do {
		displayMenu();
		getline(cin, temp);
		choice = atoi(temp.c_str());
		switch (choice) {
		case 1:
			displayInventory(vehicleList);
			break;
		case 2:
			addVehicle(vehicleList);
			break;
		case 3:
			updateVehicle(vehicleList);
			break;
		case 4:
			deleteVehicle(vehicleList);
			break;
		case 5:
			sortInventory(vehicleList);
			break;
		case 6:
			searchInventory(vehicleList);
			break;
		case 7:
			readInventoryFile(vehicleList);
			break;
		case 8:
			writeInventoryFile(vehicleList);
			break;
		default:
			cout << "Invalid choice\n";
		}
	} while (choice != 8);
    return 0;
}
