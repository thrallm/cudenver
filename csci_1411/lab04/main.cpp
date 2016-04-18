// Class: CSCI 1411-003
// Assignment: Lab 04, Question: 4.5 Option: 2
// Author: Mason Thrall, mason.thrall@ucdenver.edu 
// Status: Compiled successfully on CSEgrid
// Date: 02/12/2016
//////////////////////////////////////////////////
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
	const int SHIRT_PRICE = 12;
	int shirtCount = -1; 
	double shirtPrice = 0.0;
	
	cout << "Welcome to the t-shirt store calculator." << endl;
	// Loop until valid input
	while (shirtCount < 0) {
		cout << "How many t-shirts do you want?" << endl;
        	cin >> shirtCount;
		// Help from http://stackoverflow.com/questions/5131647
		cin.clear(); // Clear any error flags
		cin.ignore(1e6,'\n'); // Clear the buffer
		if (shirtCount < 0)
			cout << "Invalid Input: Please enter a non-negative number." << endl;
	}

	// Calculate shirt unit price
	if (shirtCount < 5) {
		shirtPrice = SHIRT_PRICE;
	} else if (shirtCount >= 5 && shirtCount <= 10) {
		shirtPrice = SHIRT_PRICE * .9;
	} else if (shirtCount >= 11 && shirtCount <= 20) {
                shirtPrice = SHIRT_PRICE * .85;
        } else if (shirtCount >= 21 && shirtCount <= 30) {
                shirtPrice = SHIRT_PRICE * .8;
        } else {
                shirtPrice = SHIRT_PRICE * .75;
	}
	
	// Output results
	cout << setprecision(2) << fixed << showpoint; 
        cout << "The cost per shirt is $" << shirtPrice;
	cout << " and the total price is $" << shirtPrice * shirtCount << endl;
	return 0;
}
