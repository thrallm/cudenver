// Readata, from CSCI 1411-003 lab 10.3
// Demonstrate cin writing past the end of the array, BAD.
// Author: Mason Thrall, mason.thrall@ucdenver.edu 
#include <iostream>
using namespace std;

const short STRLEN = 10;

int main() {
	char last[STRLEN];
	short choice;

	cout << "Please choose bad (0) or good (1)\n";
        cin >> choice;
	cin.ignore();
	switch(choice){
		case(0):
			cout << "Please enter your last name (up to 9 characters only).\n";
			cin >> last;
			break;
		case(1):
			cout << "Please enter your last name (up to 9 characters only).\n";
			cin.getline(last, STRLEN);
			break;
		default:
			cout << "You didn't choose!\n";
	}
	cout << "You entered " << last << "\n";
	return 0;
}
//
// Exercise 1: Program is written.
//
// Exercise 2: The program allows you to write in Newmanouskous even though it
// is longer than the length of the array. It returns:
// You entered Newmanouskous
//
// Exercise 3: Program is modified with an option to use getline. Using cin.getline(last, 10)
// then the program returns the input string cropped to the correct len:
// You entered Newmanous
//
// Exercise 4: In grades.cpp file.
