#include <iostream>
#include <iomanip>
using namespace std;

// This program demonstrates how to use an array of structures
// Mason Thrall
// Fill in code to define a structure called taxPayer that has three 
// members:  taxRate, income, and taxes -- each of type float

struct taxPayer {
	float taxRate, income, taxes;
};

const int SIZE = 5;

int main() {
	// Fill in code to declare an array named citizen which holds
	// 5 taxPayers structures
	taxPayer citizens[SIZE];

	cout << fixed << showpoint << setprecision(2);
	cout << "Please enter the annual income and tax rate for 5 tax payers: ";
	cout << endl << endl << endl;

	for(int count = 0; count < SIZE; count++) {	
		cout << "Enter this year's income for tax payer " << (count + 1);
		cout << ": ";	
		// Fill in code to read in the income to the appropriate place
		cin >> citizens[count].income;

		cout << "Enter the tax rate for tax payer # " << (count + 1);
		cout << ": ";	
		// Fill in code to read in the tax rate to the appropriate place
		cin >> citizens[count].taxRate;
		// Fill in code to compute the taxes for the citizen and store it
		// in the appropriate place
		citizens[count].taxes = citizens[count].taxRate * citizens[count].income;
		cout << endl;
	}

	cout << "Taxes due for this year: " << endl << endl;

	// Fill in code for the first line of a loop that will output the 
	// tax information
	for(int count = 0; count < SIZE; count++) {
		cout << "Tax Payer # " << (count + 1) << ": " << "$ "
			 << citizens[count].taxes << endl;
	}

	return 0;
}
// Exercise 1: Code is complete.
// Exercise 2: You need the (count + 1) in the first case since you are printing out
// the taxpayer number in a human readable natual number format starting at 1. In the 
// second case, you use just count because you need to reference the row in the array
// which is zero indexed.
