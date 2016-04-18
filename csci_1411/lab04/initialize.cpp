// This program tests whether or not an initialized value
// is equal to a value input by the user 

// name: Mason Thrall

#include <iostream>
using namespace std;

int main( )
{
 	int num1;
	int num2;

	cout << "Please enter an integer" << endl;
	cin >> num1;
	cout << "Please enter another integer" << endl;
        cin >> num2;

	cout << "num1 = " << num1 << " and num2 = " << num2 << endl;

	if (num1 == num2) {
		cout << "The values are the same." << endl;
		cout << "Hey, that's a coincidence!" << endl; 
	} else {
		cout << "The values are not the same." << endl;
	}		
	return 0;	
}

// Exercise 1:
// Nope the program doens't work as expected, it always prints "Hey, that's  a coincidence!".
// This is because the num1 = num2 is using the assignment operator instead of the relational expression ==.
//
// Exercise 2:
// Program is modified to ask for both numbers.
//
// Exercise 3:
// Output for the matching condition is updated.
//
// Exercise 4:
// The program is modified to use a single if/else statement.
