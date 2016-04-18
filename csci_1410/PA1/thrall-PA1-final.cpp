// Assignment: PA1-prep - Magic Number Program
// Description: This program prepares for PA1 by outlining the program.
	// PA1 is a magic number program which reverses a 3 digit number
	// and does some other calculations and displays the output of the calculations.
	// Menu options 'A' and 'B' are very similar and should be done with a function,
	// but we are not supposed to use functions for this assignment, so their
	// outlines are very similar.
// Author: Mason Thrall, mason.thrall@ucdenver.edu
// Successfully compiled on csegrid using g++
// Met all requirements
// Date: 02/15/2016
//////////////////////////////////////////////////
#include <iostream> // cin, cout
#include <iomanip> // setw(), setfill()
#include <string>
using namespace std;

int main() {
	// Declare the constants
	const int DEMO_ORIGINAL_NUMBER = 321; // for storing the example number for option 'A'

	// Declare the variables
	string studentName, className; // the user info
	string expectedOutputType; // what type of output to expect
	char menuChoice; // the current menu choice chosen by the user
	int originalNumber; // number used for starting the calculation
	int hundreds, tens, ones; // the places
	int reversedNumber; // the reversed number
	int differenceNumber; // the difference between original and reversed
	int differenceReverseNumber; // the reversed difference
	int magicNumber; // the magic number

	// Collect user input
	// Output intro (monitor)
        cout << "Welcome to the Magic Number program! Please enter your name and class:" << endl;
	// Collect name and class (keyboard)
        cin >> studentName >> className;
	do {
		originalNumber = -1;	
		// Clear newlines and error codes from cin
		cin.ignore(1e6, '\n');
                cin.clear();
		// Loop until option 'C' is selected for exiting
		// Display menu
		cout << "Please select an option from the menu below:" << endl;
		cout << "a. Display an example" << endl;
		cout << "b. Try it out yourself" << endl;
		cout << "c. Exit" << endl;
		// Collect choice using cin.get() and assign to menuChoice
		cin.get(menuChoice);
		// Process menuChoice
		if (menuChoice == 'a' || menuChoice == 'A') {
			cout << "OK, using the demo number " << DEMO_ORIGINAL_NUMBER << endl;
			originalNumber = DEMO_ORIGINAL_NUMBER;
		} else if (menuChoice == 'b' || menuChoice == 'B') {
			cout << "Please input a 3 digit number:" << endl;
			cin >> originalNumber;
			cout << originalNumber << endl;
			if (originalNumber < 0 || originalNumber > 1000) {
				cout << "That is not 3 digits." << endl;
				// set originalNumber to an invalid value
				// so that the menu repeats
				originalNumber = -1;	
			}
		}
		// Process the magic number if there is a valid originalNumber.
		if (originalNumber > 0) {	
			// Do the math and assign the variables as necessary.
			// Reverse originalNumber
			// Do this by isolating each place
			// Hundreds is easy, just divide originalNumber by 100
			hundreds = originalNumber / 100;
			// To get tens, do the modulus 100 of originalNumber,
			// which gives you the tens and ones, then divide by 10.
			tens = originalNumber % 100 / 10; 
			// Ones can be gotten with the modulus 10 of originalNumber
			ones = originalNumber % 10; 
			// Then recombine them with the numbers shifted places
			if (hundreds < ones)
				expectedOutputType = "negative";
			else if (hundreds > ones)
				expectedOutputType = "positive";
			else
				expectedOutputType = "zero";
			reversedNumber = hundreds + tens * 10 + ones * 100;	
			// Subtract reversed from original
			differenceNumber = originalNumber - reversedNumber;
			// Reverse that difference using the same method as before
			hundreds = differenceNumber / 100;
        		tens = (differenceNumber % 100) / 10;
			ones = differenceNumber % 10;
			differenceReverseNumber =  hundreds + tens * 10 + ones * 100;
			// Calculate the Magic Number
			// differenceNumber + differenceReverseNumber
			magicNumber = differenceNumber + differenceReverseNumber;	
			// Display output (monitor) to the user
			// Pad all numbers with "0" to 3 digits so they always display as 3 digits
			// Using setw(3) and setfill("0")
			cout << setw(3) << setfill('0') << endl;
			cout << "..................................." << endl;
			cout << "... The number you entered is: " << setw(3);
			cout << setfill('0') << originalNumber << endl;
			cout << "... We should expect the Magic Number to be " << expectedOutputType << endl;
			cout << "... The reversal of the input is: " << setw(3);
			cout << setfill('0') << reversedNumber <<  endl;
			cout << "... Subtraction of reversal from the original number is: ";
			cout << setw(3) << setfill('0') << originalNumber << " - ";
			cout << setw(3) << setfill('0') << reversedNumber << " = ";
			cout << setw(3) << setfill('0') << differenceNumber << endl;
			cout << "... Reversal of the resulting number is: " << setw(3);
			cout << setfill('0') << differenceReverseNumber <<  endl;
			cout << "... Addition of the number to the un-reversed form is: ";
			cout << setw(3) << setfill('0') << differenceNumber << " + ";
			cout << differenceReverseNumber << " = " << magicNumber << endl;
			cout << "... The final outcome is: " << setw(4);
			cout << setfill('0') << magicNumber;
			cout << " which is our Magic Number" << endl;
			cout << "..................................." << endl << endl;
		}
	} while (menuChoice != 'c' && menuChoice != 'C');
	// exit the program
	cout << "Goodbye!" << endl;
	return 0;
}
