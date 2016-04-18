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
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Constants
const int MAX_ITEMS = 100;
const int FIELD_COUNT = 6;
const string INVENTORY_FILE = "inventory.txt";

// Types
struct Book {
	int isbn;
	string title;
	string author;
	string publisher;
	int quantity;
	double price;
};
typedef Book InventoryListType[MAX_ITEMS];

// Function Prototypes
void readInventory(InventoryListType, int &, int);
void addInventory(InventoryListType, int &, int);
void deleteInventory(InventoryListType, int &, int);
void updateInventory(InventoryListType, int, int);
void sortTitle(InventoryListType, int, int);
void writeInventory(InventoryListType, int, int);
void displayMenu();
void displayInventory(InventoryListType, int, int);
void displayFeedback(string, string);
bool validateInput();

//*************************************************
// void displayMenu
//
// Display the menu.
//*************************************************
void displayMenu(){
	cout << "----------------------------------\n"
	     << "Please pick from the menu below:\n\n"
	     << "1. Read inventory from file\n"
	     << "2. Add an entry\n"
	     << "3. Delete an entry\n"
	     << "4. Update an entry\n"
	     << "5. Sort inventory\n"
	     << "6. Write inventory to file and exit\n"
	     << "----------------------------------\n\n";
}
//*************************************************
// void readInventory
// 
// Read the input inventory file and put the data
// into the Book struct contained in the 
// InventoryListType. Increment size when a book is added.
//*************************************************
void readInventory(InventoryListType inventory, int &size, int maxsize){
	// Create and open an ifstream
	int line = 0;
	ifstream inFile;
	string temp, temp2;
	inFile.open(INVENTORY_FILE.c_str());
	// Loop over the file
	while(!inFile.eof() && size < maxsize){
		// Put data into the InventoryListType.
		// Since the type of the lines and the
		// period of the record is 5 lines, use
		// a switch statement keyed off of a modulus 5.
		// The different lines of the switch will
		// insert values into different lines of the 
		// InventoryListType and handle the appropriate
		// type casting.
		getline(inFile, temp);
		switch(line % FIELD_COUNT){
			case(0): // isbn
				inventory[size].isbn = atoi(temp.c_str());
				break;
			case(1): // title
				inventory[size].title = temp.c_str();
				break;
			case(2): // author
				inventory[size].author = temp.c_str();
				break;
			case(3): // publisher
				inventory[size].publisher = temp.c_str();
				break;
			case(4): // quantity
				inventory[size].quantity = atoi(temp.c_str());
				break;
			case(5): // price
				inventory[size].price = atof(temp.c_str());
				size++;
				// reached the end of a record, go to the next one.

		}
		line++;
	}
	// Close the ifstream
	inFile.close();
	cout << "Inventory loaded (" << size << " books)!\n\n";
	displayInventory(inventory, size, maxsize);
}
//*************************************************
// void addInventory
//
// Check if the InventoryListType can hold another
// item. If it can, then prompt the user for the
// fields of the Book struct and add the new Book
// to the InventoryListType. After it is added, call
// sortTitle. Var size is passed by reference since 
// this function will increment size.
//*************************************************
void addInventory(InventoryListType inventory, int &size, int maxsize){
	string temp;
	// Check if InventoryListType is full
	if(size < maxsize){
		// Create a new Book, prompt the user
		// for the values and put them into the Book.
		// Then add the Book to InventoryListType.
		// increment size.
		// call sortTitle.
		Book newBook;
		cout << "Please enter the isbn:\n";
		getline(cin, temp);
		newBook.isbn = atoi(temp.c_str());
		cout << "Please enter the title:\n";
        getline(cin, temp);
        newBook.title = temp.c_str();
		cout << "Please enter the author:\n";
		getline(cin, temp);
        newBook.author = temp.c_str(); 
		cout << "Please enter the publisher:\n";
		getline(cin, temp);
        newBook.publisher = temp.c_str();
		cout << "Please enter the quantity:\n";
     	getline(cin, temp);
        newBook.quantity = atoi(temp.c_str());
		cout << "Please enter the price:\n";
    	getline(cin, temp);
        newBook.price = atof(temp.c_str());
		inventory[size] = newBook; // add to next spot in inventory
		size++; //increment size
	} else {
		cout << "The inventory is full, you cannot "
		     << "add any more books, sorry.\n";
	}	
}
//*************************************************
// void deleteInventory
//
// Call displayInventory so the user can pick which
// item to delete. Ask which item to delete, then
// confirm the choice. Remove the item and call
// sortTitle after it is removed. Var size is passed
// by reference since this function will decrement size.
//*************************************************
void deleteInventory(InventoryListType inventory, int &size, int maxsize){
	int bookIndex;
	char input;
	
	if(!size){
		cout << "There are no books to delete.\n";
		return;
	}
	cout << "Please enter the index of the book to delete:\n";
	displayInventory(inventory, size, maxsize);
	cin >> bookIndex;
	cin.ignore();
	if(!validateInput())
		return;
	if(bookIndex < 0 || bookIndex > size - 1){
		cout << "Invalid choice!\n";
		return;
	}
	cout << "This will remove book [" << inventory[bookIndex].title
		 << "] do you want to continue (Y|N)?\n";
	// Collect verification input
	cin.get(input);
	// If verified
	if(toupper(input) == 'Y'){
		// Loop through inventory starting at bookIndex + 1
		// and move each book down one index. The first move
		// will replace the book at bookIndex.
		displayFeedback(inventory[bookIndex].title, "deleting...");
		if(bookIndex < size - 1 && bookIndex < maxsize - 1){ // prevent moving in data from outside array
			for(bookIndex; bookIndex < size - 1 && bookIndex < maxsize - 1; bookIndex++){
				inventory[bookIndex] = inventory[bookIndex + 1];
			}
		}
		// decrement &size	
		size--;
		sortTitle(inventory, size, maxsize);
	}
}
//*************************************************
// void updateInventory
//
// This will allow the user to update the quantity
// for a Book in the inventory. First, call
// displayInventory so the user can pick which book 
// to update.
//*************************************************
void updateInventory(InventoryListType inventory, int size, int maxsize){
	int bookIndex;
	char input;

	if(!size){
		cout << "There are no books to update.\n";
		return;
	}
	cout << "Please enter the index of the book to edit:\n";
	displayInventory(inventory, size, maxsize);
	cin >> bookIndex;
	cin.ignore();
	if(!validateInput())
		return;
	if(bookIndex < 0 || bookIndex > size - 1){
		cout << "Invalid choice!\n";
		return;
	}
	cout << "The current quantity of [" << inventory[bookIndex].title
	     << "] is " << inventory[bookIndex].quantity << endl;
	// Ask user if they want to enter a new quantity, increment, or decrement.
	// Collect input.
	cout << "Do you want to add one (I) or remove one (D) or enter a new quantity (N)?\n";
	cin.get(input);
	// Switch statement based on their input
	switch(tolower(input)){
		case('i'):
			inventory[bookIndex].quantity++;
			displayFeedback(inventory[bookIndex].title, "updated");
			break;
		case('d'):
			inventory[bookIndex].quantity--;
			displayFeedback(inventory[bookIndex].title, "updated");
			break;
		case('n'):
			cout << "What is the new quantity?\n";
			cin >> inventory[bookIndex].quantity;
			cin.ignore();
			if(!validateInput()){
				cout << "Not a valid quantity!\n";
				return;
			}
			displayFeedback(inventory[bookIndex].title, "updated!");
			break;
		default:
			cout << "Invalid choice.\n";
	}
}
//*************************************************
// void sortTitle
// 
// Sort the InventoryListType by the title member
// using selectionSort.
//*************************************************
void sortTitle(InventoryListType inventory, int size, int maxsize){
	// Implement selectionsort
	// Loop through inventory
	Book temp;
	for(int i = 0; i < size - 1 && i < maxsize - 1; i++){
		// Loop through inventory for each book.title
		// checking indicies above it to see if they
		// are lower (earlier alphabetical). If a lower
		// book.title is found, then swap the locations of
		// the books using the temp book as intermediary.
		for(int j = i + 1; j < size && j < maxsize; j++){
			if(inventory[i].title > inventory[j].title){
				temp = inventory[i];
				inventory[i] = inventory[j];
				inventory[j] = temp;
			}
		}
	}
	displayInventory(inventory, size, maxsize);
}
//*************************************************
// void writeInventory
// 
// Sort the InventoryListType and then write the 
// inventory to the inventory file.
//*************************************************
void writeInventory(InventoryListType inventory, int size, int maxsize){
	if(!size){
		cout << "There are no books to write out.\n";
		return;
	}
	cout << "Writing inventory to the file:\n";
	sortTitle(inventory, size, maxsize);
	// create and open an ofstream
	ofstream outFile;
	outFile.open(INVENTORY_FILE.c_str());
	// loop through the InventoryListType
	for(int i = 0; i < size && i < maxsize; i++){
		// Output the fields to the file in the
		// correct order.
		outFile << inventory[i].isbn << '\n';
		outFile << inventory[i].title << '\n';
		outFile << inventory[i].author << '\n';
		outFile << inventory[i].publisher << '\n';
		outFile << inventory[i].quantity << '\n';
		outFile << inventory[i].price << '\n';
	}
	// close the ofstream
	outFile.close();
	cout << "File written, goodbye!\n\n";
}
//*************************************************
// void displayInventory
//
// Print an indexed list of the inventory to the screen.
//*************************************************
void displayInventory(InventoryListType inventory, int size, int maxsize){
	cout << "\tCurrent inventory (" << size << " books):\n";
	// loop through the InventoryListType
	for(int i = 0; i < size && i < maxsize; i++){
		// output each i and Book to the screen
		cout << "\t" << i << ". " << inventory[i].title << endl;
	}
}
//*************************************************
// void displayFeedback
//
// Print feedback
//*************************************************
void displayFeedback(string bookname, string verb){
	cout << "\n\"" << bookname << "\" " << verb << "\n\n";
}
//*************************************************
// bool validateInput
//
// Do basic checks to validate input.
// Researched via: http://stackoverflow.com/questions/5655142/how-to-check-if-input-is-numeric-in-c
//*************************************************
bool validateInput(){
	if(cin.fail()){
		cout << "Invalid choice!\n";
		cin.clear();
		cin.ignore(100 ,'\n');
		return false;
	} else {
		return true;
	}
}