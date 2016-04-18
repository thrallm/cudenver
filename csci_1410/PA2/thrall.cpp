// Assignment: PA2 - prep
// Author: Mason Thrall, mason.thrall@ucdenver.edu 
// Date: 2016/03/06
// Status: Compiled successfully using g++ on csegrid.
// Description: This program will provide a interface 
// for running a bookstore. The program has a menu 
// interface which is looped until quit is selected.
//
// Options are provided to:
// * read inventory from a file
// * add an item to the inventory
// * delete an item from the inventory
// * update an entry in the inventory
// * sort the inventory by title
// * write the inventory to a file
//
// The book info is stored in a struct called Book 
// which is contained in an inventory array.
// *************************************************

// Headers
#include "thrall.h"

int main() {
	InventoryListType inventoryList;
	string invFileName = "inventory.txt";
	int invSize = 0;
	char input;
	cout << "*******************************************\n";
	cout << "Welcome to the Bookstore Management System!\n";
	cout << "*******************************************\n\n";
	while(input != '6'){
		displayMenu();
		cin >> input;
		cin.ignore();
		cout << "++++++++++++++++++++++++++++++++++++++++++\n\n";
		switch(input){
			case('1'):
				readInventory(inventoryList, invSize, MAX_ITEMS);
				break;
			case('2'):
				addInventory(inventoryList, invSize, MAX_ITEMS);
				break;
			case('3'):
				deleteInventory(inventoryList, invSize, MAX_ITEMS);
				break;
			case('4'):
				updateInventory(inventoryList, invSize, MAX_ITEMS);
				break;
			case('5'):
				sortTitle(inventoryList, invSize, MAX_ITEMS);
				break;
			case('6'):
				writeInventory(inventoryList, invSize, MAX_ITEMS);
				break;
			default:
				cout << "Invalid option. Please pick again.\n";
		}
	}
	return 0;
}