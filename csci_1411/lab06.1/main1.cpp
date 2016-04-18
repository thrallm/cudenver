// CSCI 1411-003 lab 6.1 - question 6.4 - option 2
// Get input of miles travelled and hours travelled.
// Calculate the speed in a function and output the
// speed in the main function.
// Author: Mason Thrall, mason.thrall@ucdenver.edu 
#include <iostream>
#include <iomanip>
using namespace std;

// Function prototypes
void calculateSpeed(double, double, double&);

// Main function
int main() {
	double miles;
	double hours;
	double milesPerHour;
	cout << "How many miles did you travel?\n";
	cin >> miles;
	cout << "How many hours were you travelling?\n";
	cin >> hours;
	calculateSpeed(miles, hours, milesPerHour);
	// milesPerHour is pass by reference b/c it is used in main.
	cout << fixed << setprecision(2);
	cout << "Your speed was " << milesPerHour << " miles per hour\n";
	return 0;
}

// Calculate the speed in miles per hour from the inputs of miles and hours.
void calculateSpeed(double miles, double hours, double& milesPerHour) {
	milesPerHour = miles / hours;	
}
