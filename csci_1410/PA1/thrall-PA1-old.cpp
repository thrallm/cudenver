// Magic Number Program
// Author: Mason Thrall, mason.thrall@ucdenver.edu
// Successfully compiled on csegrid using g++
// Date: 02/04/2016
//////////////////////////////////////////////////
#include <iostream> // cin, cout
#include <iomanip> // setw(), setfill()
#include<string>
using namespace std;

int main() {
	// Declare the variables
	int originalNumber;
	int hundreds, tens, ones;
	int reversedNumber;
	int differenceNumber;
	int differenceReverseNumber;
	int magicNumber;
	string name, className;

	// Collect user input
	// todo: Add menu logic with a loop, 
	// checking the input for each option 
	cout << "Welcome to the Magic Number program! Please enter your name and class:" << endl;
	cin >> name >> className;
	cout << endl;
	cout << "Please enter a three digit number " << name << " from class " << className << "." << endl;
	cin >> originalNumber;
	cout << endl;

	// Do Math
	// Reverse the number
	// Do this by isolating each place
	// Hundreds is easy, just divide by 100
	hundreds = originalNumber / 100;
	// To get tens, do the modulus 100,
	// which gives you the tens and ones,
	// then divide by 10.
        tens = originalNumber % 100 / 10;
	// Ones can be gotten with the modulus 10
	ones = originalNumber % 10;
	// Then recombining them with the numbers shifted
	reversedNumber = hundreds + tens * 10 + ones * 100;
	// Subtract reversed from original
	differenceNumber = originalNumber - reversedNumber;
	// Reverse that difference using the same method as before
	hundreds = differenceNumber / 100;
        tens = (differenceNumber % 100) / 10;
        ones = differenceNumber % 10;
	differenceReverseNumber =  hundreds + tens * 10 + ones * 100;
	// Calculate the Magic Number
	magicNumber = differenceNumber + differenceReverseNumber;

	// Output the results to the console for the user
	cout << setw(3) << setfill('0');
        cout << "The number you entered is: " << setw(3);
	cout << setfill('0') << originalNumber << endl;
	cout << "The reversal of the input is: " << setw(3);
	cout << setfill('0') << reversedNumber <<  endl;
	cout << "Subtraction of reversal from the original number is: ";
        cout << setw(3) << setfill('0') << originalNumber << " - ";
	cout << setw(3) << setfill('0') << reversedNumber << " = ";
	cout << setw(3) << setfill('0') << differenceNumber << endl;
	cout << "Reversal of the resulting number is: " << setw(3);
        cout << setfill('0') << differenceReverseNumber <<  endl;
	cout << "Addition of the number to the un-reversed form is: ";
	cout << setw(3) << setfill('0') << differenceNumber << " + ";
	cout << differenceReverseNumber << " = " << magicNumber << endl;
	cout << "The final outcome is: " << setw(4);
        cout << setfill('0') << magicNumber;
	cout << " which is our Magic Number" << endl;

	return 0;
}
