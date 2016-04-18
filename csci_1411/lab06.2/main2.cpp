// CSCI 1411-003 - lab06.2 - question 6.8 - option 1
// Convert miles to kilometers or vice versa. Allow
// user to select which from a menu. Loop until the user
// selects the quit option. Do the calculation in a value
// returning functions.
// Author: Mason Thrall, mason.thrall@ucdenver.edu 
#include <iostream>
#include <iomanip>
using namespace std;

// Function prototypes
void convertUnits(int);
void displayMenu();
void getValue(double &);

// Constants
const double KM_TO_MILE = 0.621;
const double MILE_TO_KM = 1.61;

int main() {
	char menuChoice;
	// loop menu until exit is selected
	do {
		displayMenu();
		cin.get(menuChoice);
		convertUnits(menuChoice);
	} while ( menuChoice != '3' );
	return 0;
}

// Convert and display the conversion based on the inputted menu choice.
void convertUnits(int menuChoice){
	double value;
	switch(menuChoice){
		case('1'):
			getValue(value);
			cout << value << " miles = " << value * MILE_TO_KM << " kilometers\n";
			break;
		case('2'):
			getValue(value);
			cout << value << " kilometers = " <<  value * KM_TO_MILE << " miles\n";
			break;
		case('3'):
			cout << "Goodbye!\n";
			break;
		default:
			cout << "Please input a valid choice\n";
	}	
}

// Display the menu options.
void displayMenu(){
	cout << "Please input\n"
	     << "1 Convert miles to kilometers\n"
	     << "2 Convert kilometers to miles\n"
	     << "3 Quit\n";
}

// Get the original value from the user.
void getValue(double &value){
	cout << "Please input the value to be converted: ";
        cin >> value;
        cin.ignore();
}
